#ifndef _FARM_SCENE_H_
#define _FARM_SCENE_H_

#include "cocos2d.h"
#include "all_in_one.h"

class FarmScene : public cocos2d::CCLayerColor, public CCEditBoxDelegate
{
protected:
   
private:
    const char * monsterAry[4];
    cocos2d::CCSize visibleSize;
    // Animation
    int randNum;
    // EditBox
    virtual void editBoxEditingDidBegin(CCEditBox* editBox);
    virtual void editBoxEditingDidEnd(CCEditBox* editBox);
    virtual void editBoxTextChanged(CCEditBox* editBox, const std::string& text);
    virtual void editBoxReturn(CCEditBox* editBox);
    const char* inputText;
    CCEditBox* stateEditBox;
    // Messages
    string* messages;
    int mLoopCount;
    int mNumberOfMessages;
    virtual void load();
    //JSON parser
    string* messageAry;
    string* userAry;
    
public:
    virtual bool init();
    static cocos2d::CCScene * scene();
    
    CREATE_FUNC(FarmScene);
    
    // This is button that puts monster
    virtual void onClick1();
    virtual void onClick2();
    
    // HTTP
    virtual void onHttpRequestCompleted(cocos2d::CCNode *sender, void *data);
    
    // Animation
    virtual void animationLogic();
    
    // Popup
    virtual void menuOKCallback();
    virtual void menuNGCallback();
    
    //Schedule Update
    virtual void update(float delta);
    virtual void updateMessages();
    
   
};

#endif // _FARM_SCENE_H_
