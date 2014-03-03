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

    Setter::setBackground(this);
    
    
    // Position
    float firstPos = visibleSize.height * 15/20;
    float secondPos = visibleSize.height * 9/20;
    float thirdPos = visibleSize.height * 3/20;
    float editBoxPosX = visibleSize.width * 7/20;
    float editBoxPosY = visibleSize.height * 1/20;
    
    // Height of Text Box
    float heightOfBox = visibleSize.height *2/10;
    float editBoxWidth = visibleSize.width *5/10;
    float editBoxHeight = visibleSize.height *1/20;
    
    // first text and onclick event
    CCScale9Sprite * s9s = CCScale9Sprite::create("dialog_dark.png");
    s9s->setContentSize(CCSizeMake(visibleSize.width *8/10,  heightOfBox));
    CCMenuItemSprite * ccMIS_first = CCMenuItemSprite::create(s9s, s9s, this, menu_selector(FarmScene::onTouchLabel_1));
    ccMIS_first->setPosition(ccp(visibleSize.width/2,firstPos));
    CCMenu* menu_first = CCMenu::create(ccMIS_first,NULL);
    menu_first->setPosition(CCPointZero);
    this->addChild(menu_first);
    // Text label
    const char* mes_str = "";
    CCLabelTTF* mes_label = CCLabelTTF::create(mes_str, "arial", 48);
    mes_label->setColor(ccc3(255, 0, 127));
    mes_label->setDimensions(CCSize(visibleSize.width * 7/10,  heightOfBox));
    mes_label->setPosition(CCPointMake(visibleSize.width/2, firstPos));
    mes_label->setTag(_LABEL_MESSAGEBOX_FIRST_);
    addChild(mes_label);
   
    // second text
    CCScale9Sprite * s9s_2 = CCScale9Sprite::create("dialog_dark.png");
    s9s_2->setContentSize(CCSizeMake(visibleSize.width *8/10,  heightOfBox));
    CCMenuItemSprite * ccMIS_second = CCMenuItemSprite::create(s9s, s9s, this, menu_selector(FarmScene::onTouchLabel_2));
    ccMIS_second->setPosition(ccp(visibleSize.width/2,secondPos));
    CCMenu* menu_second = CCMenu::create(ccMIS_second,NULL);
    menu_second->setPosition(CCPointZero);
    this->addChild(menu_second);
    // Text label
    const char* mes_str_2 = "";
    CCLabelTTF* mes_label_2 = CCLabelTTF::create(mes_str_2, "arial", 48);
    mes_label_2->setColor(ccc3(255, 0, 127));
    mes_label_2->setDimensions(CCSize(visibleSize.width * 7/10,  heightOfBox));
    mes_label_2->setPosition(CCPointMake(visibleSize.width/2, secondPos));
    mes_label_2->setTag(_LABEL_MESSAGEBOX_SECOND_);
    addChild(mes_label_2);
    
    // third text
    CCScale9Sprite * s9s_3 = CCScale9Sprite::create("dialog_dark.png");
    s9s_3->setContentSize(CCSizeMake(visibleSize.width *8/10,  heightOfBox));
    CCMenuItemSprite * ccMIS_third = CCMenuItemSprite::create(s9s, s9s, this, menu_selector(FarmScene::onTouchLabel_3));
    ccMIS_third->setPosition(ccp(visibleSize.width/2,thirdPos));
    CCMenu* menu_third = CCMenu::create(ccMIS_third,NULL);
    menu_third->setPosition(CCPointZero);
    this->addChild(menu_third);
    // Text label
    const char* mes_str_3 = "";
    CCLabelTTF* mes_label_3 = CCLabelTTF::create(mes_str_3, "arial", 48);
    mes_label_3->setColor(ccc3(255, 0, 127));
    mes_label_3->setDimensions(CCSize(visibleSize.width * 7/10,  heightOfBox));
    mes_label_3->setPosition(CCPointMake(visibleSize.width/2, thirdPos));
    mes_label_3->setTag(_LABEL_MESSAGEBOX_THIRD_);
    addChild(mes_label_3);
    
   
    // Mail Box
    CCMenuItemImage* menuBackItem = CCMenuItemImage::create("frame_g.png","frame_p.png",this,menu_selector(FarmScene::moveToMailBox));
    menuBackItem->setPosition(ccp(menuBackItem->getContentSize().width/2, visibleSize.height - menuBackItem->getContentSize().height/2));
    CCMenu* menuBack = CCMenu::create(menuBackItem, NULL);
    menuBack->setPosition(CCPointZero);
    this->addChild(menuBack,7);
    
    // EditBox
    CCMenuItemImage* sendItemImg = CCMenuItemImage::create("frame_g.png","frame_p.png",this,menu_selector(MainMenuBarLayer::goBackScene));
    CCEditBox* editBox;
    CCSize editBoxSize = CCSizeMake(100, 100);
    editBox = CCEditBox::create(editBoxSize, CCScale9Sprite::create("frame_g.png"));
    editBox->setPosition(ccp(visibleSize.width - sendItemImg->getContentSize().width/2, visibleSize.height - sendItemImg->getContentSize().height/2));
    editBox->setFontColor(ccBLUE);
    editBox->setPlaceHolder("");
    editBox->setMaxLength(100);
    editBox->setFontSize(24);
    editBox->setDelegate(this);
    editBox->setTag(_EDITBOX_);
    editBox->setInputMode(kEditBoxInputModeAny);
    editBox->setReturnType(kKeyboardReturnTypeSend);
    this->addChild(editBox,7);
    
    // Add Menu bar
    // Background Image for menu bar
    CCScale9Sprite* scale9Sprite = CCScale9Sprite::create("frame_v.png");
    scale9Sprite->setContentSize(ccp(visibleSize.width,visibleSize.height/10));
    scale9Sprite->setPosition(ccp(visibleSize.width/2,visibleSize.height - scale9Sprite->getContentSize().height/2));
    this->addChild(scale9Sprite,5);
    // Add swipe layer
    CCLayer * swipelayer = SwipeLayer::create();
    this->addChild(swipelayer,99999);
   
    
    // Initial private variable
    mLoopCount = -1; // Wait for the schedule
    mNumberOfMessages = 0;
    inputText = "default";
    
    // call main logic
    this->schedule(schedule_selector(FarmScene::updateMessages), 5.0f);
    
    // TODO load
    this->load();

    
    // === End ===
    return true;
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
        switch(mLoopCount%3){
            case 0:
            {
                CCLabelTTF* mes_label = (CCLabelTTF*)this->getChildByTag(_LABEL_MESSAGEBOX_FIRST_);
                mes_label->setString(messageAry[mLoopCount].c_str());
                CCActionInterval* pFadeOutAction = CCFadeOut::create(10.0f);
                mes_label->runAction(pFadeOutAction);
               break;
            }
            case 1:
            {
                CCLabelTTF* mes_label_2 = (CCLabelTTF*)this->getChildByTag(_LABEL_MESSAGEBOX_SECOND_);
                mes_label_2->setString(messageAry[mLoopCount].c_str());
                CCActionInterval* pFadeOutAction = CCFadeOut::create(10.0f);
                mes_label_2->runAction(pFadeOutAction);
                break;
            }
            case 2:
            {
                CCLabelTTF* mes_label_3 = (CCLabelTTF*)this->getChildByTag(_LABEL_MESSAGEBOX_THIRD_);
                mes_label_3->setString(messageAry[mLoopCount].c_str());
                CCActionInterval* pFadeOutAction = CCFadeOut::create(10.0f);
                mes_label_3->runAction(pFadeOutAction);
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
        CCScene* scene = SocialScene::scene();
        CCTransitionMoveInR* tran = CCTransitionMoveInR::create(0.5, scene);
        CCDirector::sharedDirector()->pushScene(tran);
    }
}

void FarmScene::onTouchLabel_2()
{
    int onTouch = (mLoopCount-1)%3;
    if(onTouch == 1 || onTouch == -2){
        CCLog("onTouchLabel=> %s","Lable_second");
        CCScene* scene = SocialScene::scene();
        CCTransitionMoveInR* tran = CCTransitionMoveInR::create(0.5, scene);
        CCDirector::sharedDirector()->pushScene(tran);
    }
}

void FarmScene::onTouchLabel_3()
{
    int onTouch = (mLoopCount-1)%3;
    if(onTouch == 2 || onTouch == -2){
        CCLog("onTouchLabel=> %s","Label_third");
        CCScene* scene = SocialScene::scene();
        CCTransitionMoveInR* tran = CCTransitionMoveInR::create(0.5, scene);
        CCDirector::sharedDirector()->pushScene(tran);
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
    
}

void FarmScene::menuNGCallback()
{
    
}

void FarmScene::menuOKCallback()
{
	//TODO Debug
	CCLog("Dev=> %s","onClick1");
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

