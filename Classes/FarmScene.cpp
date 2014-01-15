#include "FarmScene.h"
#include "cocos2d.h"
#include "cocos-ext.h"
#include "spine/Json.h"
#include "picojson.h"
#include "DefTags.h"
#include "Getter.h"
#include "Setter.h"
#include "JsonGenerator.h"
#include <string>

USING_NS_CC;
USING_NS_CC_EXT;

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include "JNICalls/InterfaceJNI.h"
#endif

// Basically, this app works with messagePlus(/var/mplus).

CCScene* Farm::scene()
{
    CCScene *scene = CCScene::create();
    Farm *layer = Farm::create();
    scene->addChild(layer);
    return scene;
}

bool Farm::init()
{
    
    if ( CCLayerColor::initWithColor(ccc4(255,255,255,255)) )
    {
    }
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    
    // Set background
    Setter::setBackground(this);
    
    CCPoint origin = CCDirector::sharedDirector()->getVisibleOrigin();
    
    CCMenuItemImage * pCloseItem = CCMenuItemImage::create(
                                                          "CloseNormal.png",
                                                          "CloseSelected.png",
                                                          this,
                                                          menu_selector(Farm::menuCloseCallback));
    
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
    CCMenuItemSprite * ccMIS_1 = CCMenuItemSprite::create(ccS9S_1, ccS9S_on_1, this, menu_selector(Farm::onClick1));
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
    CCMenuItemSprite * ccMIS_2 = CCMenuItemSprite::create(ccS9S_2, ccS9S_on_2, this, menu_selector(Farm::onClick2));
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
    randNum = 4;
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
    
    // Other Pets
    CCSpriteBatchNode * batchNode2 = CCSpriteBatchNode::create(monsterAry[randNum]);
    CCSprite * pet2 = CCSprite::createWithTexture(batchNode2->getTexture(), CCRect(0,0,128,128));
    pet2->setPosition(CCPointMake(visibleSize.width/2, visibleSize.height/10 * 8));
    pet2->setTag(_SPRITE_PET_1_);
    this->addChild(pet2);
    
    // Animation
    CCAnimation * animation2 = CCAnimation::create();
    animation2->addSpriteFrameWithTexture(batchNode->getTexture(), CCRect(128*0,0,128,128));
    animation2->addSpriteFrameWithTexture(batchNode->getTexture(), CCRect(128*3,0,128,128));
    animation2->addSpriteFrameWithTexture(batchNode->getTexture(), CCRect(128*0,0,128,128));
    animation2->addSpriteFrameWithTexture(batchNode->getTexture(), CCRect(128*4,0,128,128));
    animation2->setDelayPerUnit(0.8f / 4.0f);
    animation2->setRestoreOriginalFrame(true);
    CCAnimate * action2 = CCAnimate::create(animation2);
    CCRepeatForever * actionreq2 = CCRepeatForever::create(action2);
    pet->runAction(actionreq2);
    
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
    
    // Schecule
    this->schedule(schedule_selector(Farm::animationLogic), 1.0/10.0);
   
    return true;
}


void Farm::animationLogic()
{
    
    // Get Size of Device Display
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    
    // moving
    float x = 0;
    const float PI = 3.1415f;
    int max_cnt = 60 * 1;
    float cos_val = cosf(PI * (float)this->mLoopCount++ /(float)max_cnt);
    x = (float)visibleSize.width/3 * cos_val;
    if( this->mLoopCount > (max_cnt * 2))
    {
        this->mLoopCount = 0;
    }
   
    CCSprite * pet = (CCSprite *)this->getChildByTag(_SPRITE_MY_PET_);
    pet->setPosition(CCPointMake(x + visibleSize.width/2, visibleSize.height/10 * 3));
    pet->setTag(_SPRITE_MY_PET_);
    
    CCSprite * pet2 = (CCSprite *)this->getChildByTag(_SPRITE_PET_1_);
    pet2->setPosition(CCPointMake(x + visibleSize.width/2, visibleSize.height/10 * 8));
    pet2->setTag(_SPRITE_PET_1_);
    
}


void Farm::menuCloseCallback(CCObject* pSender)
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
void Farm::onClick1()
{
	// TODO Debug
	CCLog("Dev=> %s","onClick1");

    // Get Size of Device Display
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    
    // Remove the sprite
    CCSprite * prepet = (CCSprite *)this->getChildByTag(_SPRITE_MY_PET_);
    prepet->removeFromParent();
    
    // Set Random Number
    randNum = rand() % 5;
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
    // TODO
    CCLabelTTF * label_monsters_host = (CCLabelTTF*)this->getChildByTag(_LABEL_MY_MONSTERID_);
    label_monsters_host->setColor(ccc3(25, 25, 25));
    label_monsters_host->setPosition(CCPointMake(visibleSize.width/2, visibleSize.height/10 * 4));
    label_monsters_host->setString(monsterAry[randNum]);
    
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
    pair[num++] = std::make_pair("fname",monsterAry[randNum]);
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
    request->setResponseCallback(this, httpresponse_selector(Farm::onHttpRequestCompleted));
    request->setRequestData(postData, strlen(postData));
    request->setHeaders(headers);
    request->setTag("POST Request");
    //cocos2d::extension::CCHttpClient::getInstance()->send(request);
    
    // Release memory
    request->release();
    delete[] pair;
    delete[] jsonData;
   
}

// Matching users
void Farm::onClick2()
{
  	// TODO Debug
	CCLog("Dev=> %s","onClick2");
    
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
    pair[num++] = std::make_pair("fname","Pikaho");
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
    request->setResponseCallback(this, httpresponse_selector(Farm::onHttpRequestCompleted2));
    request->setRequestData(postData, strlen(postData));
    request->setHeaders(headers);
    request->setTag("POST Request");
    cocos2d::extension::CCHttpClient::getInstance()->send(request);
    
    // Release memory
    request->release();
    delete[] pair;
    delete[] jsonData;
}

void Farm::onHttpRequestCompleted(cocos2d::CCNode *sender, void *data)
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
    const char * host = Json_getString(json, "host", "default");
    const char * friend1 = Json_getString(json, "friend1", "default");
    const char * friend2 = Json_getString(json, "friend2", "default");
    const char * friend3 = Json_getString(json, "friend3", "default");
    const char * friend4 = Json_getString(json, "friend4", "default");
    const char * monsters_host = Json_getString(json, "monsters_host", "default");
    const char * monsters_friend1 = Json_getString(json, "monsters_friend1", "default");
    const char * monsters_friend2 = Json_getString(json, "monsters_friend2", "default");
    const char * monsters_friend3 = Json_getString(json, "monsters_friend3", "default");
    const char * monsters_friend4 = Json_getString(json, "monsters_friend4", "default");
    const char * info = Json_getString(json, "info", "default");
    
    // Show JSON data
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
   
    // Show Friend MONSTER ID
    CCLabelTTF * text2 = (CCLabelTTF*)this->getChildByTag(_LABEL_MONSTERID_1_);
    text2->setColor(ccc3(25, 25, 25));
    text2->setPosition(CCPointMake(visibleSize.width/2, visibleSize.height/10 * 9));
    text2->setString(monsters_friend1);
    
    // Show Friend UUID
    CCLabelTTF * text3 = (CCLabelTTF*)this->getChildByTag(_LABEL_UUID_1_);
    text3->setColor(ccc3(25, 25, 25));
    text3->setPosition(CCPointMake(visibleSize.width/2, visibleSize.height/10 * 7));
    text3->setString(friend1);
    
    
    // Delete the JSON structure
    Json_dispose(json);
    
}

void Farm::onHttpRequestCompleted2(cocos2d::CCNode *sender, void *data)
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
    const char * host = Json_getString(json, "host", "default");
    const char * friend1 = Json_getString(json, "friend1", "default");
    const char * friend2 = Json_getString(json, "friend2", "default");
    const char * friend3 = Json_getString(json, "friend3", "default");
    const char * friend4 = Json_getString(json, "friend4", "default");
    const char * monsters_host = Json_getString(json, "monsters_host", "default");
    const char * monsters_friend1 = Json_getString(json, "monsters_friend1", "default");
    const char * monsters_friend2 = Json_getString(json, "monsters_friend2", "default");
    const char * monsters_friend3 = Json_getString(json, "monsters_friend3", "default");
    const char * monsters_friend4 = Json_getString(json, "monsters_friend4", "default");
    const char * info = Json_getString(json, "info", "default");
    
    // Show JSON data
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
   
    // Show Friend MONSTER ID
    CCLabelTTF * text2 = (CCLabelTTF*)this->getChildByTag(_LABEL_MONSTERID_1_);
    text2->setColor(ccc3(25, 25, 25));
    text2->setPosition(CCPointMake(visibleSize.width/2, visibleSize.height/10 * 9));
    text2->setString(monsters_friend1);
    
    // Show Friend UUID
    CCLabelTTF * text3 = (CCLabelTTF*)this->getChildByTag(_LABEL_UUID_1_);
    text3->setColor(ccc3(25, 25, 25));
    text3->setPosition(CCPointMake(visibleSize.width/2, visibleSize.height/10 * 7));
    text3->setString(friend1);
    
    // Remove the sprite
    CCSprite * prepet = (CCSprite *)this->getChildByTag(_SPRITE_PET_1_);
    prepet->removeFromParent();
    
    // Set Random Number
    CCSpriteBatchNode * batchNode = CCSpriteBatchNode::create(monsters_friend1);
    CCSprite * pet = CCSprite::createWithTexture(batchNode->getTexture(), CCRect(0,0,128,128));
    pet->setPosition(CCPointMake(visibleSize.width/2, visibleSize.height/10 * 8));
    pet->setTag(_SPRITE_PET_1_);
    this->addChild(pet);
    
   
    // Delete the JSON structure
    Json_dispose(json);
    
}



