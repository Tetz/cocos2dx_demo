#include "HelloWorldScene.h"
#include "cocos2d.h"
#include "cocos-ext.h"
#include "spine/Json.h"
#include "picojson.h"

USING_NS_CC;
USING_NS_CC_EXT;

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include "JNICalls/InterfaceJNI.h"
#endif

// Basically, This app works with messagePlus(/var/mplus).

CCScene* HelloWorld::scene()
{
    CCScene *scene = CCScene::create();
    HelloWorld *layer = HelloWorld::create();
    scene->addChild(layer);
    return scene;
}

bool HelloWorld::init()
{
    if ( CCLayerColor::initWithColor(ccc4(255,255,255,255)) )
    {
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
    
    CCMenuItemImage *pCloseItem = CCMenuItemImage::create(
                                                          "CloseNormal.png",
                                                          "CloseSelected.png",
                                                          this,
                                                          menu_selector(HelloWorld::menuCloseCallback));
    
	pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
                                origin.y + pCloseItem->getContentSize().height/2));
    
    CCMenu* pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);
    
    // Send Button
    CCScale9Sprite* sendScale9Spy = CCScale9Sprite::create("Send.png");
    sendScale9Spy->setContentSize(CCSizeMake(200, 120));
    CCScale9Sprite* sendScale9Spy_onClick = CCScale9Sprite::create("SendHighlighted.png");
    sendScale9Spy_onClick->setContentSize(CCSizeMake(200, 120));
    
    CCMenuItemSprite* sendMessageItem = CCMenuItemSprite::create(sendScale9Spy, sendScale9Spy_onClick, this, menu_selector(HelloWorld::sendOnclick));
    sendMessageItem->setPosition(ccp(visibleSize.width/2,120));
    CCMenu* menu = CCMenu::create(sendMessageItem,NULL);
    menu->setPosition(CCPointZero);
    this->addChild(menu,1);
    
    CCLabelTTF *text = CCLabelTTF::create("", "arial", 48);
    text->setColor(ccc3(25, 25, 25));
    text->setPosition(CCPointMake(visibleSize.width/2, visibleSize.height/2));
    text->setTag(1);
    this->addChild(text);
    
    return true;
}


void HelloWorld::menuCloseCallback(CCObject* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT) || (CC_TARGET_PLATFORM == CC_PLATFORM_WP8)
	CCMessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
#else
    CCDirector::sharedDirector()->end();
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
#endif
}

// OnClick Action
void HelloWorld::sendOnclick()
{
    // Set Key and Value
    int numberOfPair = 4;
    std::pair <const char*, const char*>* pair;
    pair = new std::pair <const char*, const char*> [numberOfPair];
    int num = 0;
    pair[num++] = std::make_pair("uuid", HelloWorld::getUUID());
    pair[num++] = std::make_pair("name","Pikaho");
    pair[num++] = std::make_pair("message","Hello, I am pikaho");
    pair[num++] = std::make_pair("food","meat");
    
    // Array Initialization
    int count_char = 0;
    
    // Calculate Memory Size
    for (int cnt = 0; cnt < numberOfPair; cnt++)
    {
        count_char += strlen(pair[cnt].first);
        count_char += strlen(pair[cnt].second);
    }
    int jsonDataSize = count_char + 6*numberOfPair + 2 + 100;
    
    // Allocate memory
    char * jsonData;
    jsonData = new char [jsonDataSize];
    
    // NULL-terminated character sequence
    *jsonData = '\0';
    
    // Set jsonData
    jsonGenerator(numberOfPair, jsonData, pair);
    
    // Create Json Object
    const char * postData = jsonData;
    CCLog("Debug jsonGenerator : %s", postData);
    
    // HTTP Client
    std::vector<std::string> headers;
    headers.push_back("Content-Type: application/json; charset=utf-8");
    cocos2d::extension::CCHttpRequest* request = new cocos2d::extension::CCHttpRequest();
    request->setUrl("http://49.212.139.75:9000/main");
    request->setRequestType(cocos2d::extension::CCHttpRequest::kHttpPost);
    request->setResponseCallback(this, httpresponse_selector(HelloWorld::onHttpRequestCompleted));
    request->setRequestData(postData, strlen(postData));
    request->setHeaders(headers);
    request->setTag("POST Request");
    cocos2d::extension::CCHttpClient::getInstance()->send(request);
    
    // Release memory
    request->release();
    delete[] pair;
    delete[] jsonData;
    
    // Java Native Interface
    std::string uuid;
    uuid = "none";
#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    // TODO
    InterfaceJNI::func1();
    uuid = InterfaceJNI::getUUID();
#endif
    // foo->bar() is the same as (*foo).bar()
    CCLog("getUUID : %s", uuid.c_str());
    
}

// JSON Generator
void HelloWorld::jsonGenerator(int numberOfPair, char json[], std::pair<const char*, const char*> pair[])
{
    int max = numberOfPair;
    
    strcat(json, "{");
    for (int cnt = 0; cnt < max; cnt++)
    {
        strcat(json, "\"");
        strcat(json, pair[cnt].first);
        strcat(json, "\":\"");
        strcat(json, pair[cnt].second);
        strcat(json, "\"");
        if(cnt != max-1){
            strcat(json, ",");
        }
    }
    strcat(json, "}");
}


void HelloWorld::onHttpRequestCompleted(cocos2d::CCNode *sender, void *data)
{
    cocos2d::extension::CCHttpResponse *response = (cocos2d::extension::CCHttpResponse*)data;
    
    if (!response)
    {
        return;
    }
    
    if (0 != strlen(response->getHttpRequest()->getTag()))
    {
        CCLog("%s completed", response->getHttpRequest()->getTag());
    }
    
    int statusCode = response->getResponseCode();
    char statusString[64] = {};
    sprintf(statusString, "HTTP Status Code: %d, tag = %s", statusCode, response->getHttpRequest()->getTag());
    CCLog("response code: %d", statusCode);
    
    if (!response->isSucceed())
    {
        CCLog("response failed");
        CCLog("error buffer: %s", response->getErrorBuffer());
        return;
    }
    
    // store data
    std::vector<char> *buffer = response->getResponseData();
    char* concatenated = (char*) malloc(buffer->size() + 1);
    std::string s2(buffer->begin(), buffer->end());
    
    strcpy(concatenated, s2.c_str());
    
    CCLog("JSON : %s",concatenated);
    CCLog("===");
    
    // JSON Parser
    Json* json = Json_create(concatenated);
    const char* json_result = Json_getString(json, "uuid", "default");
    CCLog("key 1 : %s", json_result);
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCLabelTTF *text = (CCLabelTTF*)this->getChildByTag(1);
    text->setColor(ccc3(25, 25, 25));
    text->setPosition(CCPointMake(visibleSize.width/2, visibleSize.height/2));
    text->setString(json_result);
    
    // Delete the JSON structure
    Json_dispose(json);
    
    
}


// Getter
const char* HelloWorld::getUUID()
{
    const char* uuid = "a8da9as8d";
    return uuid;
}

const char* HelloWorld::getName()
{
    const char* name = "Miky";
    return name;
}

const char* HelloWorld::getMessages()
{
    const char* uuid = "Hello, I am Miky! How are you doing?";
    return uuid;
}

const char* HelloWorld::getFood()
{
    CCString ccstr = "test";
    const char* uuid = "meat";
    return uuid;
}


