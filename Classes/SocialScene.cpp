#include "SocialScene.h"

//enum SocialSceneTag{ _NumberOfFriends_ = 1};

CCScene * SocialScene::scene()
{
    CCScene * scene = CCScene::create();
    SocialScene * layer = SocialScene::create();
    scene->addChild(layer);
    return scene;
}

bool SocialScene::init()
{
    
    if ( CCLayerColor::initWithColor(ccc4(255,255,255,255)) )
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
    
    // button1
    CCScale9Sprite * ccS9S_1 = CCScale9Sprite::create("Send.png");
    ccS9S_1->setContentSize(CCSizeMake(200, 120));
    CCScale9Sprite * ccS9S_on_1 = CCScale9Sprite::create("SendHighlighted.png");
    ccS9S_on_1->setContentSize(CCSizeMake(200, 120));
    
    // onClick1
    CCMenuItemSprite * ccMIS_1 = CCMenuItemSprite::create(ccS9S_1, ccS9S_on_1, this, menu_selector(SocialScene::onClick1));
    ccMIS_1->setPosition(ccp(buttonPosX,buttonPosY));
    CCMenu* menu_1 = CCMenu::create(ccMIS_1,NULL);
    menu_1->setPosition(CCPointZero);
    this->addChild(menu_1,1);
    
    // EditBox
    CCEditBox* editBox;
    CCSize editBoxSize = CCSizeMake(editBoxWidth, editBoxHeight);
    editBox = CCEditBox::create(editBoxSize, CCScale9Sprite::create("editbox.png"));
    editBox->setPosition(ccp(editBoxPosX, editBoxPosY));
    editBox->setFontColor(ccBLUE);
    editBox->setPlaceHolder("Input");
    editBox->setMaxLength(100);
    editBox->setReturnType(kKeyboardReturnTypeDone);
    editBox->setFontSize(24);
    editBox->setDelegate(this);
    editBox->setTag(_EDITBOX_);
    this->addChild(editBox);
   
    // TextBox
    CCScale9Sprite * s9s = CCScale9Sprite::create("dialog_dark.png");
    s9s->setContentSize(CCSizeMake(visibleSize.width *8/10,  heightOfBox));
    s9s->setPosition(CCPointMake(visibleSize.width/2, firstPos));
    const char* mes_str = "afafejaioeafiasdfjkjoiasdfjoiasdfjoiasefjoiasdjfo;iajdfifjadisfj;iajsdf;jadsifj;ajifjiajidfitjaijfiajdljadjfakdjfadjfadfj;;jfhia";
    CCLabelTTF* mes_label = CCLabelTTF::create(mes_str, "arial", 48);
    mes_label->setColor(ccc3(255, 0, 127));
    mes_label->setDimensions(CCSize(visibleSize.width * 7/10,  heightOfBox));
    mes_label->setPosition(CCPointMake(visibleSize.width/2, firstPos));
    mes_label->setTag(_LABEL_MESSAGEBOX_FIRST_);
    //  Scroll View
    CCSize scrollSize = CCSizeMake(600, 800);
    CCScrollView *scrollView = CCScrollView::create(scrollSize);
    scrollView->setPosition(0,320);
    this->addChild(scrollView,2);
    scrollView->setContainer(mes_label);
    scrollView->setContentOffset(ccp(0,-800));
    scrollView->setContentSize(mes_label->getContentSize());
    scrollView->setDirection(kCCScrollViewDirectionVertical);
   
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

void SocialScene::editBoxEditingDidBegin(CCEditBox* editBox){}
void SocialScene::editBoxEditingDidEnd(CCEditBox* editBox){}
void SocialScene::editBoxTextChanged(CCEditBox* editBox, const std::string& text){}
void SocialScene::editBoxReturn(CCEditBox* editBox){
    inputText = editBox->getText();
}

