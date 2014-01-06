#include "HelloWorldScene.h"
#include "cocos2d.h"
#include "cocos-ext.h"
#include "spine/Json.h"
#include "picojson.h"
#include "DefTags.h"
#include "Getter.h"
#include "JsonGenerator.h"

USING_NS_CC;
USING_NS_CC_EXT;

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include "JNICalls/InterfaceJNI.h"
#endif

// Basically, this app works with messagePlus(/var/mplus).

CCScene* HelloWorld::scene()
{
    CCScene *scene = CCScene::create();
    HelloWorld *layer = HelloWorld::create();
    scene->addChild(layer);
    return scene;
}

bool HelloWorld::init()
{
    randNum = 3;
    
    if ( CCLayerColor::initWithColor(ccc4(255,255,255,255)) )
    {
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
    
    CCMenuItemImage * pCloseItem = CCMenuItemImage::create(
                                                          "CloseNormal.png",
                                                          "CloseSelected.png",
                                                          this,
                                                          menu_selector(HelloWorld::menuCloseCallback));
    
	pCloseItem->setPosition(ccp(origin.x + visibleSize.width - pCloseItem->getContentSize().width/2 ,
                                origin.y + pCloseItem->getContentSize().height/2));
    
    CCMenu * pMenu = CCMenu::create(pCloseItem, NULL);
    pMenu->setPosition(CCPointZero);
    this->addChild(pMenu, 1);
    
    // button1
    CCScale9Sprite * ccS9S_1 = CCScale9Sprite::create("Send.png");
    ccS9S_1->setContentSize(CCSizeMake(200, 120));
    CCScale9Sprite * ccS9S_on_1 = CCScale9Sprite::create("SendHighlighted.png");
    ccS9S_on_1->setContentSize(CCSizeMake(200, 120));
    
    // onClick1
    CCMenuItemSprite * ccMIS_1 = CCMenuItemSprite::create(ccS9S_1, ccS9S_on_1, this, menu_selector(HelloWorld::onClick1));
    ccMIS_1->setPosition(ccp(visibleSize.width/4,120));
    CCMenu* menu_1 = CCMenu::create(ccMIS_1,NULL);
    menu_1->setPosition(CCPointZero);
    this->addChild(menu_1,1);

    // button2
    CCScale9Sprite * ccS9S_2 = CCScale9Sprite::create("Send.png");
    ccS9S_2->setContentSize(CCSizeMake(200, 120));
    CCScale9Sprite * ccS9S_on_2 = CCScale9Sprite::create("SendHighlighted.png");
    ccS9S_on_2->setContentSize(CCSizeMake(200, 120));
    
    // onClick2
    CCMenuItemSprite * ccMIS_2 = CCMenuItemSprite::create(ccS9S_2, ccS9S_on_2, this, menu_selector(HelloWorld::onClick2));
    ccMIS_2->setPosition(ccp(visibleSize.width/4*3,120));
    CCMenu* menu_2 = CCMenu::create(ccMIS_2,NULL);
    menu_2->setPosition(CCPointZero);
    this->addChild(menu_2,1);
    
    // Monsters List
    int num = 0;

    monsterAry[num++] = "baby.png";
    monsterAry[num++] = "giga.png";
    monsterAry[num++] = "kodora.png";
    monsterAry[num++] = "meca.png";
    monsterAry[num++] = "kopute.png";
    
    
    // Label Tag 1
    CCLabelTTF * text = CCLabelTTF::create("", "arial", 48);
    text->setColor(ccc3(25, 25, 25));
    text->setPosition(CCPointMake(visibleSize.width/2, visibleSize.height/10 * 3));
    text->setTag(_LABEL_MY_MONSTERID_);
    this->addChild(text);
    
    // Label Tag 2
    CCLabelTTF * text2 = CCLabelTTF::create("", "arial", 36);
    text2->setColor(ccc3(25, 25, 25));
    text2->setPosition(CCPointMake(visibleSize.width/2, visibleSize.height/10 * 2));
    text2->setTag(_LABEL_MY_UUID_);
    this->addChild(text2);
    
    // My Pet
    CCSpriteBatchNode * batchNode = CCSpriteBatchNode::create(monsterAry[randNum]);
    CCSprite * pet = CCSprite::createWithTexture(batchNode->getTexture(), CCRect(0,0,128,128));
    pet->setPosition(CCPointMake(visibleSize.width/2, visibleSize.height/10 * 3));
    pet->setTag(_SPRITE_MY_PET_);
    this->addChild(pet);
    
    // Animation
    CCAnimation * animation = CCAnimation::create();
    animation->addSpriteFrameWithTexture(batchNode->getTexture(), CCRect(128*0,0,128,128));
    animation->addSpriteFrameWithTexture(batchNode->getTexture(), CCRect(128*3,0,128,128));
    animation->addSpriteFrameWithTexture(batchNode->getTexture(), CCRect(128*0,0,128,128));
    animation->addSpriteFrameWithTexture(batchNode->getTexture(), CCRect(128*4,0,128,128));
    animation->setDelayPerUnit(0.8f / 4.0f);
    animation->setRestoreOriginalFrame(true);
    CCAnimate * action = CCAnimate::create(animation);
    CCRepeatForever * actionreq = CCRepeatForever::create(action);
    pet->runAction(actionreq);
    
    // Label Tag 3
    CCLabelTTF * text3 = CCLabelTTF::create("", "arial", 48);
    text3->setColor(ccc3(25, 25, 25));
    text3->setPosition(CCPointMake(visibleSize.width/2, visibleSize.height/10 * 3));
    text3->setTag(_LABEL_MONSTERID_1_);
    this->addChild(text3);
    
    // Label Tag 4
    CCLabelTTF * text4 = CCLabelTTF::create("", "arial", 36);
    text4->setColor(ccc3(25, 25, 25));
    text4->setPosition(CCPointMake(visibleSize.width/2, visibleSize.height/10 * 2));
    text4->setTag(_LABEL_UUID_1_);
    this->addChild(text4);
    
   
    // Other Pets
    CCSprite * pet2 = CCSprite::create(monsterAry[randNum]);
    pet2->setPosition(CCPointMake(visibleSize.width/2, visibleSize.height/10 * 8));
    this->addChild(pet2);
   
   
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
void HelloWorld::onClick1()
{
	// TODO Debug
	CCLog("Dev=> %s","test8");

    // Get Size of Device Display
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    
    // Remove the sprite
    CCSprite * prepet = (CCSprite *)this->getChildByTag(_SPRITE_MY_PET_);
    prepet->removeFromParent();
    
    // Set Random Number
    randNum = rand() % 4;
    CCSpriteBatchNode * batchNode = CCSpriteBatchNode::create(monsterAry[randNum]);
    CCSprite * pet = CCSprite::createWithTexture(batchNode->getTexture(), CCRect(0,0,128,128));
    pet->setPosition(CCPointMake(visibleSize.width/2, visibleSize.height/10 * 3));
    pet->setTag(_SPRITE_MY_PET_);
    this->addChild(pet);
    
    // Animation
    CCAnimation * animation = CCAnimation::create();
    animation->addSpriteFrameWithTexture(batchNode->getTexture(), CCRect(128*0,0,128,128));
    animation->addSpriteFrameWithTexture(batchNode->getTexture(), CCRect(128*3,0,128,128));
    animation->addSpriteFrameWithTexture(batchNode->getTexture(), CCRect(128*0,0,128,128));
    animation->addSpriteFrameWithTexture(batchNode->getTexture(), CCRect(128*4,0,128,128));
    animation->setDelayPerUnit(0.8f / 4.0f);
    animation->setRestoreOriginalFrame(true);
    CCAnimate * action = CCAnimate::create(animation);
    CCRepeatForever * actionreq = CCRepeatForever::create(action);
    pet->runAction(actionreq);
   
    // Set parameters
    std::string uuid_str = Getter::getUUID();
    const char * uuid = uuid_str.c_str();
    CCLog("Getter::getUUID : %s", uuid);
    
    // Show UUID
    CCLabelTTF * text = (CCLabelTTF*)this->getChildByTag(_LABEL_MY_UUID_);
    text->setColor(ccc3(25, 25, 25));
    text->setPosition(CCPointMake(visibleSize.width/2, visibleSize.height/10 * 2));
    text->setString(uuid);
 
    // Set Key and Value
    int numberOfPair = 4;
    std::pair <const char *, const char *> * pair;
    pair = new std::pair <const char *, const char *> [numberOfPair];
    int num = 0;
    pair[num++] = std::make_pair("uuid", uuid);
    pair[num++] = std::make_pair("name","Pikaho");
    pair[num++] = std::make_pair("message","Hello, I am pikaho");
    pair[num++] = std::make_pair("food","meat");
    
    // Array Initialization
    int count_char = 0;
    
    // Calculate Memory Size
    for (int cnt = 0; cnt < num; cnt++)
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
    JsonGenerator * jsonGenerator = new JsonGenerator();
    jsonGenerator->generate(num, jsonData, pair);
    jsonGenerator->DisposeObject();
    
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
   
}

// Matching users
void HelloWorld::onClick2()
{
    // Set parameters
    std::string uuid_str = Getter::getUUID();
    const char * uuid = uuid_str.c_str();
    CCLog("Getter::getUUID : %s", uuid);
    
    // Show UUID
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCLabelTTF * text = (CCLabelTTF*)this->getChildByTag(_LABEL_MY_UUID_);
    text->setColor(ccc3(25, 25, 25));
    text->setPosition(CCPointMake(visibleSize.width/2, visibleSize.height/10 * 2));
    text->setString(uuid);
    
    // Set Key and Value
    int numberOfPair = 4;
    std::pair <const char *, const char *> * pair;
    pair = new std::pair <const char *, const char *> [numberOfPair];
    int num = 0;
    pair[num++] = std::make_pair("uuid", uuid);
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
    JsonGenerator * jsonGenerator = new JsonGenerator();
    jsonGenerator->generate(num, jsonData, pair);
    jsonGenerator->DisposeObject();
    
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
    std::vector<char> * buffer = response->getResponseData();
    char * concatenated = (char *) malloc(buffer->size() + 1);
    std::string s2(buffer->begin(), buffer->end());
    
    strcpy(concatenated, s2.c_str());
    
    CCLog("JSON : %s",concatenated);
    CCLog("===");
    
    // JSON Parser
    Json * json = Json_create(concatenated);
    const char * f1_uuid = Json_getString(json, "f1_uuid", "default");
    const char * f1_monster_id = Json_getString(json, "f1_monster_id", "default");
    const char * monsters_id = Json_getString(json, "monsters_id", "default");
    const char * monsters_name = Json_getString(json, "monsters_name", "default");
    CCLog("HTTP Response : key 1 : %s", monsters_id);
    CCLog("HTTP Response : key 2 : %s", monsters_name);
    
    
    // Show JSON data
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    CCLabelTTF * text = (CCLabelTTF*)this->getChildByTag(_LABEL_MY_MONSTERID_);
    text->setColor(ccc3(25, 25, 25));
    text->setPosition(CCPointMake(visibleSize.width/2, visibleSize.height/10 * 4));
    text->setString(monsters_name);
    
    // Show Friend MONSTER ID
    CCLabelTTF * text2 = (CCLabelTTF*)this->getChildByTag(_LABEL_MONSTERID_1_);
    text2->setColor(ccc3(25, 25, 25));
    text2->setPosition(CCPointMake(visibleSize.width/2, visibleSize.height/10 * 9));
    text2->setString(f1_monster_id);
    
    // Show Friend UUID
    CCLabelTTF * text3 = (CCLabelTTF*)this->getChildByTag(_LABEL_UUID_1_);
    text3->setColor(ccc3(25, 25, 25));
    text3->setPosition(CCPointMake(visibleSize.width/2, visibleSize.height/10 * 7));
    text3->setString(f1_uuid);
    
    
    // Delete the JSON structure
    Json_dispose(json);
    
}


