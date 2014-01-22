#include "SocialScene.h"

enum SocialSceneTag{ _NumberOfFriends_ = 1};

CCScene * SocialScene::scene()
{
    CCScene * scene = CCScene::create();
    SocialScene * layer = SocialScene::create();
    scene->addChild(layer);
    return scene;
}

bool SocialScene::init()
{
    
    if ( CCLayerColor::initWithColor(ccc4(255,200,255,255)) )
    {
    }
    
    // Layout
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    
    // button1
    CCScale9Sprite * ccS9S_1 = CCScale9Sprite::create("Send.png");
    ccS9S_1->setContentSize(CCSizeMake(200, 120));
    CCScale9Sprite * ccS9S_on_1 = CCScale9Sprite::create("SendHighlighted.png");
    ccS9S_on_1->setContentSize(CCSizeMake(200, 120));
    
    // onClick1
    CCMenuItemSprite * ccMIS_1 = CCMenuItemSprite::create(ccS9S_1, ccS9S_on_1, this, menu_selector(SocialScene::addFriend));
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
    CCMenuItemSprite * ccMIS_2 = CCMenuItemSprite::create(ccS9S_2, ccS9S_on_2, this, menu_selector(SocialScene::removeFriend));
    ccMIS_2->setPosition(ccp(visibleSize.width/4*3,120));
    CCMenu* menu_2 = CCMenu::create(ccMIS_2,NULL);
    menu_2->setPosition(CCPointZero);
    this->addChild(menu_2,1);

    // title
    CCLabelTTF * title = CCLabelTTF::create(_NUMBER_OF_FRIENDS_, "arial", 96);
    title->setColor(ccc3(25, 25, 25));
    title->setPosition(CCPointMake(visibleSize.width/2, visibleSize.height/10 * 6));
    this->addChild(title);
    
    // Number of friends
    enum SocialSceneTag eTag;
    eTag = _NumberOfFriends_;
    CCLabelTTF * numFriends = CCLabelTTF::create("", "arial", 96);
    numFriends->setColor(ccc3(25, 25, 25));
    numFriends->setPosition(CCPointMake(visibleSize.width/2, visibleSize.height/10 * 5));
    numFriends->setTag(eTag);
    this->addChild(numFriends);
    
    // Main Logic
    SocialScene::load();
    this->main();
    
    return true;
}

void SocialScene::main()
{
    // Add swipe layer
    CCLayer * layer = SwipeLayer3::create();
    this->addChild(layer);
}

void SocialScene::load()
{
    CCLog("SocialScene::load %s","");
    
    // Set parameters
    string uuid_str = Getter::getUUID();
    const char * uuid = uuid_str.c_str();
    CCLog("Getter::getUUID : %s", uuid);
    
    // Set Key and Value
    int numberOfPair = 10;
    pair <const char *, const char *> * pairs;
    pairs = new pair <const char *, const char *> [numberOfPair];
    int num = 0;
    pairs[num++] = make_pair("uuid", uuid);
    pairs[num++] = make_pair("message","Hello, I am pikaho");
    pairs[num++] = make_pair("food","meat");
    pairs[num++] = make_pair("a","test1_value");
    pairs[num++] = make_pair("b","test2_value");
    pairs[num++] = make_pair("c","test3_value");
    pairs[num++] = make_pair("d","test4_value");
    pairs[num++] = make_pair("e","test5_value");
    pairs[num++] = make_pair("f","test6_value");
    
    // Array Initialization
    int count_char = 0;
    
    // Calculate Memory Size
    for (int cnt = 0; cnt < num; cnt++)
    {
        count_char += strlen(pairs[cnt].first);
        count_char += strlen(pairs[cnt].second);
    }
    int jsonDataSize = count_char + 6*numberOfPair + 2 + 100;
    
    // Allocate memory
    char * jsonData;
    jsonData = new char [jsonDataSize];
    
    // NULL-terminated character sequence
    *jsonData = '\0';
    
    // Set jsonData
    JsonGenerator * jsonGenerator = new JsonGenerator();
    jsonGenerator->generate(num, jsonData, pairs);
    jsonGenerator->DisposeObject();
    
    // Create Json Object
    const char * postData = jsonData;
    CCLog("Debug jsonGenerator : %s", postData);
    
    // HTTP Client
    vector<string> headers;
    headers.push_back("Content-Type: application/json; charset=utf-8");
    CCHttpRequest* request = new CCHttpRequest();
    request->setUrl("http://49.212.139.75:9000/loadSocialScene");
    request->setRequestType(CCHttpRequest::kHttpPost);
    request->setResponseCallback(this, httpresponse_selector(SocialScene::onHttpRequestCompleted));
    request->setRequestData(postData, strlen(postData));
    request->setHeaders(headers);
    request->setTag("POST Request");
    CCHttpClient::getInstance()->send(request);
    
    // Release memory
    request->release();
    delete[] pairs;
    delete[] jsonData;
    
}

void SocialScene::addFriend()
{
    CCLog("SocialScene::addFriend %s","");
   
    // Set parameters
    string uuid_str = Getter::getUUID();
    const char * uuid = uuid_str.c_str();
    CCLog("Getter::getUUID : %s", uuid);
   
    // Set Key and Value
    int numberOfPair = 10;
    pair <const char *, const char *> * pairs;
    pairs = new pair <const char *, const char *> [numberOfPair];
    int num = 0;
    pairs[num++] = make_pair("uuid", uuid);
    pairs[num++] = make_pair("message","Hello, I am pikaho");
    pairs[num++] = make_pair("food","meat");
    pairs[num++] = make_pair("a","test1_value");
    pairs[num++] = make_pair("b","test2_value");
    pairs[num++] = make_pair("c","test3_value");
    pairs[num++] = make_pair("d","test4_value");
    pairs[num++] = make_pair("e","test5_value");
    pairs[num++] = make_pair("f","test6_value");
    
    // Array Initialization
    int count_char = 0;
   
    // Calculate Memory Size
    for (int cnt = 0; cnt < num; cnt++)
    {
        count_char += strlen(pairs[cnt].first);
        count_char += strlen(pairs[cnt].second);
    }
    int jsonDataSize = count_char + 6*numberOfPair + 2 + 100;
    
    // Allocate memory
    char * jsonData;
    jsonData = new char [jsonDataSize];
    
    // NULL-terminated character sequence
    *jsonData = '\0';
    
    // Set jsonData
    JsonGenerator * jsonGenerator = new JsonGenerator();
    jsonGenerator->generate(num, jsonData, pairs);
    jsonGenerator->DisposeObject();
    
    // Create Json Object
    const char * postData = jsonData;
    CCLog("Debug jsonGenerator : %s", postData);
    
    // HTTP Client
    vector<string> headers;
    headers.push_back("Content-Type: application/json; charset=utf-8");
    CCHttpRequest* request = new CCHttpRequest();
    request->setUrl("http://49.212.139.75:9000/addFriend");
    request->setRequestType(CCHttpRequest::kHttpPost);
    request->setResponseCallback(this, httpresponse_selector(SocialScene::onHttpRequestCompleted));
    request->setRequestData(postData, strlen(postData));
    request->setHeaders(headers);
    request->setTag("POST Request");
    CCHttpClient::getInstance()->send(request);
    
    // Release memory
    request->release();
    delete[] pairs;
    delete[] jsonData;
    
}

void SocialScene::onHttpRequestCompleted(CCNode *sender, void *data)
{
    CCHttpResponse *response = (CCHttpResponse*)data;
    
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
    vector<char> * buffer = response->getResponseData();
    char * concatenated = (char *) malloc(buffer->size() + 1);
    string s2(buffer->begin(), buffer->end());
    strcpy(concatenated, s2.c_str());
    CCLog("=====> JSON =====> : %s",concatenated);
    
    // JSON Parser
    Json * json = Json_create(concatenated);
    const char * friends_count = Json_getString(json, "friends_count", "default");
    const char * info = Json_getString(json, "info", "default");
    CCLog("HTTP_Response_info : %s", info);
    
    // Show JSON data
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    
    // Show Friend MONSTER ID
    enum SocialSceneTag eTag;
    eTag = _NumberOfFriends_;
    CCLabelTTF * friends_count_text = (CCLabelTTF*)this->getChildByTag(eTag);
    friends_count_text->setColor(ccc3(25, 25, 25));
    friends_count_text->setPosition(CCPointMake(visibleSize.width/2, visibleSize.height/10 * 5));
    friends_count_text->setString(friends_count);
   
    // Delete the JSON structure
    Json_dispose(json);
}

void SocialScene::removeFriend()
{
    CCLog("SocialScene::removeFriend %s","");
    
    // Set parameters
    string uuid_str = Getter::getUUID();
    const char * uuid = uuid_str.c_str();
    CCLog("Getter::getUUID : %s", uuid);
    
    // Set Key and Value
    int numberOfPair = 10;
    pair <const char *, const char *> * pairs;
    pairs = new pair <const char *, const char *> [numberOfPair];
    int num = 0;
    pairs[num++] = make_pair("uuid", uuid);
    pairs[num++] = make_pair("message","Hello, I am pikaho");
    pairs[num++] = make_pair("food","meat");
    pairs[num++] = make_pair("a","test1_value");
    pairs[num++] = make_pair("b","test2_value");
    pairs[num++] = make_pair("c","test3_value");
    pairs[num++] = make_pair("d","test4_value");
    pairs[num++] = make_pair("e","test5_value");
    pairs[num++] = make_pair("f","test6_value");
    
    // Array Initialization
    int count_char = 0;
    
    // Calculate Memory Size
    for (int cnt = 0; cnt < num; cnt++)
    {
        count_char += strlen(pairs[cnt].first);
        count_char += strlen(pairs[cnt].second);
    }
    int jsonDataSize = count_char + 6*numberOfPair + 2 + 100;
    
    // Allocate memory
    char * jsonData;
    jsonData = new char [jsonDataSize];
    
    // NULL-terminated character sequence
    *jsonData = '\0';
    
    // Set jsonData
    JsonGenerator * jsonGenerator = new JsonGenerator();
    jsonGenerator->generate(num, jsonData, pairs);
    jsonGenerator->DisposeObject();
    
    // Create Json Object
    const char * postData = jsonData;
    CCLog("Debug jsonGenerator : %s", postData);
    
    // HTTP Client
    vector<string> headers;
    headers.push_back("Content-Type: application/json; charset=utf-8");
    CCHttpRequest* request = new CCHttpRequest();
    request->setUrl("http://49.212.139.75:9000/removeFriend");
    request->setRequestType(CCHttpRequest::kHttpPost);
    request->setResponseCallback(this, httpresponse_selector(SocialScene::onHttpRequestCompleted));
    request->setRequestData(postData, strlen(postData));
    request->setHeaders(headers);
    request->setTag("POST Request");
    CCHttpClient::getInstance()->send(request);
    
    // Release memory
    request->release();
    delete[] pairs;
    delete[] jsonData;
}