#include "SocialScene.h"

//enum SocialSceneTag{ _NumberOfFriends_ = 1};

CCScene * SocialScene::scene()
{
    CCScene * scene = CCScene::create();
    SocialScene * layer = SocialScene::create();
    scene->addChild(layer);
    // Add swipe layer
    CCLayer * swipelayer = SwipeLayer3::create();
    scene->addChild(swipelayer);
    
    return scene;
}

bool SocialScene::init()
{
    
    if ( CCLayerColor::initWithColor(ccc4(200,255,255,255)) )
    {
    }
    
    // Layout
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    // Position
    float firstPos = visibleSize.height * 17/20;
    float buttonPosX = visibleSize.width/4*3;
    float buttonPosY = visibleSize.height/20;
    float editBoxPosX = visibleSize.width * 7/20;
    float editBoxPosY = visibleSize.height * 1/20;
    // Height of Text Box
    float heightOfBox = visibleSize.height *2/10;
    float editBoxWidth = visibleSize.width *5/10;
    float editBoxHeight = visibleSize.height *1/20;
    
    
    // Background Image for menu bar
    CCScale9Sprite* scale9Sprite = CCScale9Sprite::create("frame_v.png");
    scale9Sprite->setContentSize(ccp(visibleSize.width,visibleSize.height/10));
    scale9Sprite->setPosition(ccp(visibleSize.width/2,visibleSize.height - scale9Sprite->getContentSize().height/2));
    this->addChild(scale9Sprite);
    
    // Go back to privious scene
    CCMenuItemImage* menuBackItem = CCMenuItemImage::create("frame_g.png","frame_p.png",this,menu_selector(SendScene::goBackScene));
    menuBackItem->setPosition(ccp(menuBackItem->getContentSize().width/2, visibleSize.height - menuBackItem->getContentSize().height/2));
    CCMenu* menuBack = CCMenu::create(menuBackItem, NULL);
    menuBack->setPosition(CCPointZero);
    this->addChild(menuBack);
    
    // Send a message
    CCMenuItemImage* sendItemImg = CCMenuItemImage::create("frame_g.png","frame_p.png",this,menu_selector(SendScene::goBackScene));
    sendItemImg->setPosition(ccp(visibleSize.width - sendItemImg->getContentSize().width/2, visibleSize.height - sendItemImg->getContentSize().height/2));
    CCMenu* menuSend = CCMenu::create(sendItemImg, NULL);
    menuSend->setPosition(CCPointZero);
    this->addChild(menuSend);
   
    // Main Logic
    SocialScene::load();
    this->main();
    
    return true;
}

void SocialScene::main()
{

}

void SocialScene::onClick1()
{
    
}
                                                          
void SocialScene::onClick2()
{
    
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



void SocialScene::onHttpRequestCompleted(CCNode *sender, void *data)
{
}

void SocialScene::editBoxEditingDidBegin(CCEditBox* editBox){
    //CCDirector::sharedDirector()->replaceScene(CCTransitionMoveInB::create(2.0f,SendScene::scene()));
}
void SocialScene::editBoxEditingDidEnd(CCEditBox* editBox){}
void SocialScene::editBoxTextChanged(CCEditBox* editBox, const std::string& text){}
void SocialScene::editBoxReturn(CCEditBox* editBox){
    inputText = editBox->getText();
}

