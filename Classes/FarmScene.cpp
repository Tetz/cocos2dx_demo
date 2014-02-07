#include "FarmScene.h"
#include "FriendsListScene.h"
#include "all_in_one.h"
#include "FSAlertLayer.h"

CCScene* FarmScene::scene()
{
    CCScene *scene = CCScene::create();
    FarmScene *layer = FarmScene::create();
    scene->addChild(layer);
    return scene;
}

bool FarmScene::init()
{
    if ( CCLayerColor::initWithColor(ccc4(255,255,255,255))) {}
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();

    Setter::setBackground(this);
    
    // Add swipe layer
    CCLayer * layer = SwipeLayer::create();
    this->addChild(layer);
    
    // Position
    float firstPos = visibleSize.height * 17/20;
    float secondPos = visibleSize.height * 11/20;
    float thirdPos = visibleSize.height * 5/20;
    float editBoxPosX = visibleSize.width * 7/20;
    float editBoxPosY = visibleSize.height * 1/20;
    
    // Height of Text Box
    float heightOfBox = visibleSize.height *2/10;
    float editBoxWidth = visibleSize.width *5/10;
    float editBoxHeight = visibleSize.height *1/20;
    
    // text
    CCScale9Sprite * s9s = CCScale9Sprite::create("dialog_dark.png");
    s9s->setContentSize(CCSizeMake(visibleSize.width *8/10,  heightOfBox));
    s9s->setPosition(CCPointMake(visibleSize.width/2, firstPos));
    addChild(s9s);
    const char* mes_str = "hoghoghohgoehgoehgoehgoehgoheooehogheogheohgoehgoehgoehogheogheoghoehgoehgoehgoehogheogheoghoehgoehgoehgoheogheohgoehs";
    CCLabelTTF* mes_label = CCLabelTTF::create(mes_str, "arial", 48);
    mes_label->setColor(ccc3(255, 0, 127));
    mes_label->setDimensions(CCSize(visibleSize.width * 7/10,  heightOfBox));
    mes_label->setPosition(CCPointMake(visibleSize.width/2, firstPos));
    addChild(mes_label);
   
    // text
    CCScale9Sprite * s9s_2 = CCScale9Sprite::create("dialog_dark.png");
    s9s_2->setContentSize(CCSizeMake(visibleSize.width *8/10,  heightOfBox));
    s9s_2->setPosition(CCPointMake(visibleSize.width/2, secondPos));
    addChild(s9s_2);
    const char* mes_str_2 = "hoghoghohgoehgoehgoehgoehgoheooehogheogheohgoehgoehgoehogheogheoghoehgoehgoehgoehogheogheoghoehgoehgoehgoheogheohgoehs";
    CCLabelTTF* mes_label_2 = CCLabelTTF::create(mes_str_2, "arial", 48);
    mes_label_2->setColor(ccc3(255, 0, 127));
    mes_label_2->setDimensions(CCSize(visibleSize.width * 7/10,  heightOfBox));
    mes_label_2->setPosition(CCPointMake(visibleSize.width/2, secondPos));
    addChild(mes_label_2);
    
    // text
    CCScale9Sprite * s9s_3 = CCScale9Sprite::create("dialog_dark.png");
    s9s_3->setContentSize(CCSizeMake(visibleSize.width *8/10,  heightOfBox));
    s9s_3->setPosition(CCPointMake(visibleSize.width/2, thirdPos));
    addChild(s9s_3);
    const char* mes_str_3 = "hoghoghohgoehgoehgoehgoehgoheooehogheogheohgoehgoehgoehogheogheoghoehgoehgoehgoehogheogheoghoehgoehgoehgoheogheohgoehs";
    CCLabelTTF* mes_label_3 = CCLabelTTF::create(mes_str_3, "arial", 48);
    mes_label_3->setColor(ccc3(255, 0, 127));
    mes_label_3->setDimensions(CCSize(visibleSize.width * 7/10,  heightOfBox));
    mes_label_3->setPosition(CCPointMake(visibleSize.width/2, thirdPos));
    addChild(mes_label_3);
    
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
    this->addChild(editBox);
    
    
    
    // === End ===
    return true;
}

void FarmScene::editBoxEditingDidBegin(CCEditBox* editBox){}
void FarmScene::editBoxEditingDidEnd(CCEditBox* editBox){}
void FarmScene::editBoxTextChanged(CCEditBox* editBox, const std::string& text){}
void FarmScene::editBoxReturn(CCEditBox* editBox){}


void FarmScene::animationLogic()
{
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    
}



void FarmScene::menuOKCallback()
{
    
}

void FarmScene::menuNGCallback()
{
    
}

void FarmScene::onClick1()
{
	//TODO Debug
	CCLog("Dev=> %s","onClick1");

}

void FarmScene::onClick2()
{
  	//TODO Debug
	CCLog("Dev=> %s","onClick2");

}

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
    string key;
    if(picoError.empty()) {
        picojson::object& o = picoValue.get<picojson::object>();
        key = o["key"].get<string>();
        string& info = o["info"].get<string>();
        picojson::array& picoArray = o["friends"].get<picojson::array>();
        int picoArraySize = picoArray.size();
        //id = new string[picoArraySize];
        int cnt = 0;
        for(picojson::array::iterator i = picoArray.begin(); i != picoArray.end(); i++){
            picojson::object& friendObject = i->get<picojson::object>();
            //id[cnt] = friendObject["id"].get<string>();
            //CCLog("pico id : %s", id[cnt].c_str());
            cnt++;
        }
    }

    
}



