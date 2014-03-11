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
    
    // Background Set tiled image
    CCSpriteBatchNode* node = CCSpriteBatchNode::create("message_bg1.jpg");
    CCSprite* bgspr = CCSprite::createWithTexture(node->getTexture());
    CCSize bgsize = bgspr->getContentSize();
    this->addChild(node);
    int bgWidth = bgsize.width;
    int bgHeight = bgsize.height;
    int repeatX = visibleSize.width/bgWidth + 1;
    int repeatY = visibleSize.height/bgHeight + 1;
    CCSprite* spr[repeatX][repeatY];
    for(int y=0; y<=repeatY; y++){
        for(int x=0; x<=repeatX; x++){
            spr[x][y] = CCSprite::createWithTexture(node->getTexture());
            spr[x][y]->setPosition(ccp(bgWidth * x, bgHeight * y));
            node->addChild(spr[x][y]);
        }
    }
    
    
    // Position
    
    // Width and Height
    float menuBarHeight = visibleSize.height/10;
    
    // Background Image for menu bar
    CCScale9Sprite* scale9Sprite = CCScale9Sprite::create("menu_bg.png");
    scale9Sprite->setContentSize(ccp(visibleSize.width,visibleSize.height/10));
    scale9Sprite->setPosition(ccp(visibleSize.width/2,visibleSize.height - scale9Sprite->getContentSize().height/2));
    this->addChild(scale9Sprite);
    
    // Go back to privious scene
    CCMenuItemImage* menuBackItem = CCMenuItemImage::create("back_L_btm.png","back_L_btm.png",this,menu_selector(SendScene::goBackScene));
    float menuBackPosWidth = menuBackItem->getContentSize().width/2 + (menuBarHeight - menuBackItem->getContentSize().height)/2;
    float menuBackPosHeight = visibleSize.height - menuBackItem->getContentSize().height/2 - (menuBarHeight - menuBackItem->getContentSize().height)/2;
    menuBackItem->setPosition(ccp(menuBackPosWidth,menuBackPosHeight));
    CCMenu* menuBack = CCMenu::create(menuBackItem, NULL);
    menuBack->setPosition(CCPointZero);
    this->addChild(menuBack);
    
    // Send a message
    CCMenuItemImage* menuItemEdit = CCMenuItemImage::create("back_R_btm.png","back_R_btm.png",this,menu_selector(SendScene::goBackScene));
    float menuEditPosWidth = visibleSize.width - menuItemEdit->getContentSize().width/2 - (menuBarHeight - menuItemEdit->getContentSize().height)/2;
    float menuEditPosHeight = visibleSize.height - menuItemEdit->getContentSize().height/2 - (menuBarHeight - menuItemEdit->getContentSize().height)/2;
    menuItemEdit->setPosition(ccp(menuEditPosWidth,menuEditPosHeight));
    CCMenu* menuEdit = CCMenu::create(menuItemEdit, NULL);
    menuEdit->setPosition(CCPointZero);
    this->addChild(menuEdit);
    
    // Background image for Comments Board
    CCScale9Sprite* bgBoard = CCScale9Sprite::create("frame_g.png");
    float bgBoardWidth = visibleSize.width * 9 /10;
    float bgBoardHeight = visibleSize.height * 8 /10;
    float bgBoardPosX = visibleSize.width /2;
    float bgBoardPosY = visibleSize.height *9/20  ;
    bgBoard->setContentSize(ccp(bgBoardWidth,bgBoardHeight));
    bgBoard->setPosition(ccp(bgBoardPosX,bgBoardPosY));
    this->addChild(bgBoard);
    
    // Chat Board
    CCScrollView *scrollView = CCScrollView::create(CCSizeMake(200, 120));
    scrollView->setContentSize(CCSizeMake(400, 120));
    scrollView->setPosition(ccp(visibleSize.width/2, visibleSize.height/2));
    scrollView->setDirection(kCCScrollViewDirectionVertical);
    this->addChild(scrollView);
    
    // TODO font test
    CCLabelTTF *tapMessage = CCLabelTTF ::create("Tap on Screen", "T3NOWGB", 96);
    tapMessage->setPosition(ccp(visibleSize.width/2,visibleSize.height/2));
    tapMessage->setColor(ccc3(10,10,10));
    this->addChild(tapMessage,3);
   
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

