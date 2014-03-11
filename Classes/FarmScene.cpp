#include "FarmScene.h"
#include "FarmScene.h"
#include "MainMenuBarLayer.h"
#include "all_in_one.h"
#include "FSAlertLayer.h"

CCScene* FarmScene::scene()
{
    CCScene *scene = CCScene::create();
    FarmScene *layer = FarmScene::create();
    scene->addChild(layer,1);
    
    return scene;
}

bool FarmScene::init()
{
    
    if ( CCLayerColor::initWithColor(ccc4(255,255,255,255))) {}
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    
    //Setter::setBackground(this);
    
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
    firstPos = visibleSize.height * 15/20;
    secondPos = visibleSize.height * 9/20;
    thirdPos = visibleSize.height * 3/20;
    centerPosX = visibleSize.width/2;
    float editBoxPosX = visibleSize.width * 7/20;
    float editBoxPosY = visibleSize.height * 1/20;
    
    // Height of Text Box
    float heightOfBox = visibleSize.height *2/10;
    float editBoxWidth = visibleSize.width *5/10;
    float editBoxHeight = visibleSize.height *1/20;
    float menuBarHeight = visibleSize.height/10;
    
    // first text and onclick event
    CCScale9Sprite * s9s = CCScale9Sprite::create("message_frame_100.png");
    s9s->setContentSize(CCSizeMake(visibleSize.width *8/10,  heightOfBox));
    CCMenuItemSprite * ccMIS_first = CCMenuItemSprite::create(s9s, s9s, this, menu_selector(FarmScene::onTouchLabel_1));
    ccMIS_first->setPosition(ccp(visibleSize.width/2,firstPos));
    CCMenu* menu_first = CCMenu::create(ccMIS_first,NULL);
    menu_first->setPosition(CCPointZero);
    menu_first->setTag(_MESSAGEBOX_FIRST_);
    menu_first->setVisible(false);
    this->addChild(menu_first);
    
    // Text label
    const char* mes_str = "";
    CCLabelTTF* mes_label = CCLabelTTF::create(mes_str, "T3NOWGB", 48);
    mes_label->setColor(ccc3(255, 0, 127));
    mes_label->setDimensions(CCSize(visibleSize.width * 7/10,  heightOfBox));
    mes_label->setPosition(CCPointMake(visibleSize.width/2, firstPos));
    mes_label->setTag(_LABEL_MESSAGEBOX_FIRST_);
    addChild(mes_label,5);
    
    // second text
    CCScale9Sprite * s9s_2 = CCScale9Sprite::create("message_frame_100.png");
    s9s_2->setContentSize(CCSizeMake(visibleSize.width *8/10,  heightOfBox));
    CCMenuItemSprite * ccMIS_second = CCMenuItemSprite::create(s9s_2, s9s_2 , this, menu_selector(FarmScene::onTouchLabel_2));
    ccMIS_second->setPosition(ccp(visibleSize.width/2,secondPos));
    CCMenu* menu_second = CCMenu::create(ccMIS_second,NULL);
    menu_second->setPosition(CCPointZero);
    menu_second->setTag(_MESSAGEBOX_SECOND_);
    menu_second->setVisible(false);
    this->addChild(menu_second);
    // Text label
    const char* mes_str_2 = "";
    CCLabelTTF* mes_label_2 = CCLabelTTF::create(mes_str_2, "T3NOWGB", 48);
    mes_label_2->setColor(ccc3(255, 0, 127));
    mes_label_2->setDimensions(CCSize(visibleSize.width * 7/10,  heightOfBox));
    mes_label_2->setPosition(CCPointMake(visibleSize.width/2, secondPos));
    mes_label_2->setTag(_LABEL_MESSAGEBOX_SECOND_);
    addChild(mes_label_2,5);
    
    // third text
    CCScale9Sprite * s9s_3 = CCScale9Sprite::create("message_frame_100.png");
    s9s_3->setContentSize(CCSizeMake(visibleSize.width *8/10,  heightOfBox));
    CCMenuItemSprite * ccMIS_third = CCMenuItemSprite::create(s9s_3, s9s_3, this, menu_selector(FarmScene::onTouchLabel_3));
    ccMIS_third->setPosition(ccp(visibleSize.width/2,thirdPos));
    CCMenu* menu_third = CCMenu::create(ccMIS_third,NULL);
    menu_third->setPosition(CCPointZero);
    menu_third->setTag(_MESSAGEBOX_THIRD_);
    menu_third->setVisible(false);
    this->addChild(menu_third);
    // Text label
    const char* mes_str_3 = "";
    CCLabelTTF* mes_label_3 = CCLabelTTF::create(mes_str_3, "T3NOWGB", 48);
    mes_label_3->setColor(ccc3(255, 0, 127));
    mes_label_3->setDimensions(CCSize(visibleSize.width * 7/10,  heightOfBox));
    mes_label_3->setPosition(CCPointMake(visibleSize.width/2, thirdPos));
    mes_label_3->setTag(_LABEL_MESSAGEBOX_THIRD_);
    addChild(mes_label_3,5);
    
    // Add Menu bar
    // Background Image for menu bar
    CCScale9Sprite* scale9Sprite = CCScale9Sprite::create("menu_bg.png");
    scale9Sprite->setContentSize(ccp(visibleSize.width,menuBarHeight));
    scale9Sprite->setPosition(ccp(visibleSize.width/2,visibleSize.height - scale9Sprite->getContentSize().height/2));
    this->addChild(scale9Sprite,5);
    
    // Watched
    CCSprite* watch = CCSprite::create("visitor_152x108.png");
    float watchHeight = visibleSize.height - watch->getContentSize().height/2 - (menuBarHeight - watch->getContentSize().height)/2;
    watch->setPosition(ccp(visibleSize.width/2,watchHeight));
    this->addChild(watch,7);
    
    // Mail Box
    CCMenuItemImage* menuBackItem = CCMenuItemImage::create("post_126x108.png","post.png",this,menu_selector(FarmScene::moveToMailBox));
    float menuBackPosWidth = menuBackItem->getContentSize().width/2 + (menuBarHeight - menuBackItem->getContentSize().height)/2;
    float menuBackPosHeight = visibleSize.height - menuBackItem->getContentSize().height/2 - (menuBarHeight - menuBackItem->getContentSize().height)/2;
    menuBackItem->setPosition(ccp(menuBackPosWidth,menuBackPosHeight));
    CCMenu* menuBack = CCMenu::create(menuBackItem, NULL);
    menuBack->setPosition(CCPointZero);
    this->addChild(menuBack,7);
    
    // EditBox
    CCMenuItemImage* menuItemEdit = CCMenuItemImage::create("write_132x108.png","write.png",this,menu_selector(FarmScene::onClick1));
    float menuEditPosWidth = visibleSize.width - menuItemEdit->getContentSize().width/2 - (menuBarHeight - menuItemEdit->getContentSize().height)/2;
    float menuEditPosHeight = visibleSize.height - menuItemEdit->getContentSize().height/2 - (menuBarHeight - menuItemEdit->getContentSize().height)/2;
    menuItemEdit->setPosition(ccp(menuEditPosWidth, menuEditPosHeight));
    CCMenu* menuEdit = CCMenu::create(menuItemEdit, NULL);
    menuEdit->setPosition(CCPointZero);
    this->addChild(menuEdit,7);
    
    // Hide
    CCEditBox* editBox;
    CCSize editBoxSize = CCSizeMake(0,0);
    editBox = CCEditBox::create(editBoxSize, CCScale9Sprite::create("frame_g.png"));
    editBox->setPosition(ccp(-100,-100));
    editBox->setFontColor(ccBLUE);
    editBox->setPlaceHolder("");
    editBox->setMaxLength(100);
    editBox->setFontSize(24);
    editBox->setDelegate(this);
    editBox->setTag(_EDITBOX_);
    editBox->setInputMode(kEditBoxInputModeAny);
    editBox->setReturnType(kKeyboardReturnTypeSend);
    this->addChild(editBox,0);
    
    // Add swipe layer
    CCLayer * swipelayer = SwipeLayer::create();
    this->addChild(swipelayer, 99999);
    
    // Initial private variable
    mLoopCount = -1; // Wait for the schedule
    mNumberOfMessages = 0;
    inputText = "default";
    
    // call main logic
    this->schedule(schedule_selector(FarmScene::updateMessages), 5.0f);
    
    // load
    this->load();
    
    // TODO GAME LOGIC
    this->logic();
    
    // === End ===
    return true;
}


void FarmScene::logic()
{
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    // My Pet
    CCSpriteBatchNode * batchNode = CCSpriteBatchNode::create("kopute.png");
    CCSprite * pet = CCSprite::createWithTexture(batchNode->getTexture(), CCRect(0,0,128,128));
    pet->setPosition(CCPointMake(visibleSize.width, visibleSize.height/2));
    pet->setTag(_SPRITE_MY_PET_);
    this->addChild(pet,10);

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
    
}



void FarmScene::load()
{
    
    CCLog("FarmScene::load ======> %s", "");
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
    pairs[num++] = make_pair("info","FarmScene::load");
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
    request->setUrl("http://49.212.139.75:9000/loadFarmScene");
    request->setRequestType(CCHttpRequest::kHttpPost);
    request->setResponseCallback(this, httpresponse_selector(FarmScene::onHttpRequestCompleted));
    request->setRequestData(postData, strlen(postData));
    request->setHeaders(headers);
    request->setTag("POST Request");
    CCHttpClient::getInstance()->send(request);
    
    // Release memory
    request->release();
    delete[] pairs;
    delete[] jsonData;
    
}

void FarmScene::updateMessages()
{
    // Init
    if(mLoopCount<0){mLoopCount=0;}
    // update
    if(mNumberOfMessages  > 0){
        CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
        int cnt = 0;
        const int numberOfFoods = 3;
        int cntRand = rand() % numberOfFoods;
        const char* foods[numberOfFoods];
        foods[cnt++] = "food_meat.png";
        foods[cnt++] = "food_fruit_gold.png";
        foods[cnt++] = "food_medicine_blue.png";
        foods[cnt++] = "food_medicine_purple.png";
        // Switch
        switch(mLoopCount%3){
            case 0:
            {
                // Label
                CCLabelTTF* mes_label = (CCLabelTTF*)this->getChildByTag(_LABEL_MESSAGEBOX_FIRST_);
                mes_label->setString(messageAry[mLoopCount].c_str());
                CCActionInterval* pFadeOutAction = CCFadeOut::create(_FADEOUT_TIME_);
                mes_label->runAction(pFadeOutAction);
                // Frame
                CCActionInterval* pFadeOutFrame = CCFadeOut::create(_FADEOUT_TIME_);
                CCMenu* menu_first = (CCMenu*)this->getChildByTag(_MESSAGEBOX_FIRST_);
                menu_first->runAction(pFadeOutFrame);
                menu_first->setVisible(true);
                // Foods
                CCSprite* food = CCSprite::create(foods[cntRand]);
                float foodPosX = visibleSize.width/2;
                float foodPosY = visibleSize.height/2;
                food->setPosition(ccp(foodPosX,firstPos));
                food->setTag(_FOOD_FIRST_);
                this->addChild(food);
                CCActionInterval* pFadeOutFood = CCFadeOut::create(_FADEOUT_TIME_);
                CCSequence* seq = CCSequence::create(pFadeOutFood,CCCallFunc::create(food, callfunc_selector(CCSprite::removeFromParent)),NULL);
                food->runAction(seq);
                
                // End of the case
                break;
            }
            case 1:
            {
                // Label
                CCLabelTTF* mes_label_2 = (CCLabelTTF*)this->getChildByTag(_LABEL_MESSAGEBOX_SECOND_);
                mes_label_2->setString(messageAry[mLoopCount].c_str());
                CCActionInterval* pFadeOutAction = CCFadeOut::create(_FADEOUT_TIME_);
                mes_label_2->runAction(pFadeOutAction);
                // Frame
                CCActionInterval* pFadeOutFrame = CCFadeOut::create(_FADEOUT_TIME_);
                CCMenu* menu_second = (CCMenu*)this->getChildByTag(_MESSAGEBOX_SECOND_);
                menu_second->runAction(pFadeOutFrame);
                menu_second->setVisible(true);
                // Foods
                CCSprite* food = CCSprite::create(foods[cntRand]);
                float foodPosX = visibleSize.width/2;
                float foodPosY = visibleSize.height/2;
                food->setPosition(ccp(foodPosX,secondPos));
                food->setTag(_FOOD_SECOND_);
                this->addChild(food);
                CCActionInterval* pFadeOutFood = CCFadeOut::create(_FADEOUT_TIME_);
                CCSequence* seq = CCSequence::create(pFadeOutFood,CCCallFunc::create(food, callfunc_selector(CCSprite::removeFromParent)),NULL);
                food->runAction(seq);
                
                // End of the case
                break;
            }
            case 2:
            {
                // Label
                CCLabelTTF* mes_label_3 = (CCLabelTTF*)this->getChildByTag(_LABEL_MESSAGEBOX_THIRD_);
                mes_label_3->setString(messageAry[mLoopCount].c_str());
                CCActionInterval* pFadeOutAction = CCFadeOut::create(_FADEOUT_TIME_);
                mes_label_3->runAction(pFadeOutAction);
                // Frame
                CCActionInterval* pFadeOutFrame = CCFadeOut::create(_FADEOUT_TIME_);
                CCMenu* menu_third = (CCMenu*)this->getChildByTag(_MESSAGEBOX_THIRD_);
                menu_third->runAction(pFadeOutFrame);
                menu_third->setVisible(true);
                // Foods
                CCSprite* food = CCSprite::create(foods[cntRand]);
                float foodPosX = visibleSize.width/2;
                float foodPosY = visibleSize.height/2;
                food->setPosition(ccp(foodPosX,thirdPos));
                food->setTag(_FOOD_THIRD_);
                this->addChild(food);
                CCActionInterval* pFadeOutFood = CCFadeOut::create(_FADEOUT_TIME_);
                CCSequence* seq = CCSequence::create(pFadeOutFood,CCCallFunc::create(food, callfunc_selector(CCSprite::removeFromParent)),NULL);
                food->runAction(seq);
                
                // End of the case
                break;
            }
            default:
                break;
        }
        
        // Messages
        mLoopCount++;
        if(mLoopCount >= mNumberOfMessages){
            mLoopCount = -1;
            this->load();
        }
    }
}


void FarmScene::onTouchLabel_1()
{
    int onTouch = (mLoopCount-1)%3;
    if(onTouch == 0 || onTouch == -2){
       	CCLog("onTouchLabel=> %s","Label_first");
        // Pet Action
        CCSprite* petSpr = (CCSprite*)this->getChildByTag(_SPRITE_MY_PET_);
        petSpr->runAction(CCMoveTo::create(1.0f, ccp(centerPosX,firstPos)));
        // The Eating Effect
        CCSprite* food = (CCSprite*)this->getChildByTag(_FOOD_FIRST_);
        CCDelayTime *delay = CCDelayTime::create(1.0f);
        CCScaleTo *disappear = CCScaleTo::create(1.0f, 0);
        CCSequence *seq = CCSequence::create(delay,disappear,NULL);
        food->runAction(seq);
    }
}

void FarmScene::onTouchLabel_2()
{
    int onTouch = (mLoopCount-1)%3;
    if(onTouch == 1 || onTouch == -2){
        CCLog("onTouchLabel=> %s","Lable_second");
        // Pet Action
        CCSprite* petSpr = (CCSprite*)this->getChildByTag(_SPRITE_MY_PET_);
        petSpr->runAction(CCMoveTo::create(1.0f, ccp(centerPosX,secondPos)));
        // The Eating Effect
        CCSprite* food = (CCSprite*)this->getChildByTag(_FOOD_SECOND_);
        CCDelayTime *delay = CCDelayTime::create(1.0f);
        CCScaleTo *disappear = CCScaleTo::create(1.0f, 0);
        CCSequence *seq = CCSequence::create(delay,disappear,NULL);
        food->runAction(seq);
    }
}

void FarmScene::onTouchLabel_3()
{
    int onTouch = (mLoopCount-1)%3;
    if(onTouch == 2 || onTouch == -2){
        CCLog("onTouchLabel=> %s","Label_third");
        // Pet Action
        CCSprite* petSpr = (CCSprite*)this->getChildByTag(_SPRITE_MY_PET_);
        petSpr->runAction(CCMoveTo::create(1.0f, ccp(centerPosX,thirdPos)));
        // The Eating Effect
        CCSprite* food = (CCSprite*)this->getChildByTag(_FOOD_THIRD_);
        CCDelayTime *delay = CCDelayTime::create(1.0f);
        CCScaleTo *disappear = CCScaleTo::create(1.0f, 0);
        CCSequence *seq = CCSequence::create(delay,disappear,NULL);
        food->runAction(seq);
    }
}

void FarmScene::animationLogic()
{
    
}

void FarmScene::update(float delta)
{
    // Get time
    struct cc_timeval now;
    CCTime::gettimeofdayCocos2d(&now,NULL);
    struct tm *tm;
    time_t timep = now.tv_sec;
    tm = localtime(&timep);
    int second = tm->tm_sec;
    ostringstream ostr;
    ostr << second;
    
}

void FarmScene::onClick1()
{
    CCEditBox* editBox = (CCEditBox*)this->getChildByTag(_EDITBOX_);
    editBox->touchDownAction(editBox, CCControlEventTouchUpInside);
}

void FarmScene::menuNGCallback()
{
    
}

void FarmScene::menuOKCallback()
{
	//TODO Debug
    CCLog("FarmScene::load ======> %s", "");
    
    if (strlen(inputText)){
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
        pairs[num++] = make_pair("message",inputText);
        pairs[num++] = make_pair("info","FarmScene::onClick");
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
        request->setUrl("http://49.212.139.75:9000/saveMessage");
        request->setRequestType(CCHttpRequest::kHttpPost);
        request->setResponseCallback(this, httpresponse_selector(FarmScene::onHttpRequestCompleted2));
        request->setRequestData(postData, strlen(postData));
        request->setHeaders(headers);
        request->setTag("POST Request");
        CCHttpClient::getInstance()->send(request);
        
        // Display posted message
        CCLabelTTF* mes_label_2 = (CCLabelTTF*)this->getChildByTag(_LABEL_MESSAGEBOX_SECOND_);
        mes_label_2->setString(inputText);
        CCActionInterval* pFadeOutAction = CCFadeOut::create(10.0f);
        mes_label_2->runAction(pFadeOutAction);
        // TODO
        CCActionInterval* pFadeOutFrame = CCFadeOut::create(10.0f);
        CCMenu* menu_second = (CCMenu*)this->getChildByTag(_MESSAGEBOX_SECOND_);
        menu_second->runAction(pFadeOutFrame);
        menu_second->setVisible(true);
        
        // Reset EditBox
        CCEditBox* editbox = (CCEditBox*)this->getChildByTag(_EDITBOX_);
        editbox->setText("");
        
        // Release memory
        request->release();
        delete[] pairs;
        delete[] jsonData;
    }
}

void FarmScene::moveToMailBox()
{
  	// Debug
	CCLog("Dev=> %s","moveToMailBox");
    CCScene* scene = SocialScene::scene();
    CCTransitionMoveInR* tran = CCTransitionMoveInR::create(0.5, scene);
    CCDirector::sharedDirector()->pushScene(tran);
}

void FarmScene::onHttpRequestCompleted2(cocos2d::CCNode *sender, void *data){}

void FarmScene::onHttpRequestCompleted(cocos2d::CCNode *sender, void *data)
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
    std::vector<char> * buffer = response->getResponseData();
    char * concatenated = (char *) malloc(buffer->size() + 1);
    std::string s2(buffer->begin(), buffer->end());
    strcpy(concatenated, s2.c_str());
    CCLog("JSON : %s",concatenated);
    CCLog("===");
    
    // JSON Parser
    string picoError;
    picojson::value picoValue;
    picojson::parse(picoValue,concatenated,concatenated+strlen(concatenated),&picoError);
    if(picoError.empty()) {
        picojson::object& o = picoValue.get<picojson::object>();
        string& info = o["info"].get<string>();
        picojson::array& picoArray = o["messages"].get<picojson::array>();
        int picoArraySize = picoArray.size();
        mNumberOfMessages = picoArraySize;
        userAry = new string[picoArraySize];
        messageAry = new string[picoArraySize];
        int cnt = 0;
        for(picojson::array::iterator i = picoArray.begin(); i != picoArray.end(); i++){
            picojson::object& messageObject = i->get<picojson::object>();
            userAry[cnt] = messageObject["user_id"].get<string>();
            messageAry[cnt] = messageObject["message"].get<string>();
            CCLog("pico user_id : %s", userAry[cnt].c_str());
            CCLog("pico message : %s", messageAry[cnt].c_str());
            cnt++;
        }
    }
    
}


void FarmScene::editBoxEditingDidBegin(CCEditBox* editBox){
    //CCDirector::sharedDirector()->replaceScene(CCTransitionMoveInB::create(2.0f,SendScene::scene()));
}
void FarmScene::editBoxEditingDidEnd(CCEditBox* editBox){}
void FarmScene::editBoxTextChanged(CCEditBox* editBox, const std::string& text){}
void FarmScene::editBoxReturn(CCEditBox* editBox){
    inputText = editBox->getText();
    // call from Scene, Layer, etc
    FSAlertLayer *alertLayer = FSAlertLayer::create("CONFIRM SEND", this, callfuncN_selector(FarmScene::menuOKCallback), callfuncN_selector(FarmScene::menuNGCallback));
    this->addChild(alertLayer, 100001);
}

