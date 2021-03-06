#ifndef _FARM_SCENE_H_
#define _FARM_SCENE_H_

#include "cocos2d.h"
#include "all_in_one.h"

class FarmScene : public cocos2d::CCLayerColor, public CCEditBoxDelegate
{
protected:
    // Position
    float firstPos;
    float secondPos;
    float thirdPos;
    float centerPosX;
    
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
    int mLoopCount;
    int mNumberOfMessages;
    virtual void load();
    // Reply
    virtual void onTouchLabel_1();
    virtual void onTouchLabel_2();
    virtual void onTouchLabel_3();
    // Dialog
    virtual void menuOKCallback();
    virtual void menuNGCallback();
    
    // GAME LOGIC
    virtual void logic();

    
    //JSON parser
    string* messageAry;
    string* userAry;
    
public:
    virtual bool init();
    static cocos2d::CCScene * scene();
    
    CREATE_FUNC(FarmScene);
    
    // This is button that puts monster
    virtual void onClick1();
    virtual void moveToMailBox();
    
    // HTTP
    virtual void onHttpRequestCompleted(cocos2d::CCNode *sender, void *data);
    virtual void onHttpRequestCompleted2(cocos2d::CCNode *sender, void *data);
    
    // Animation
    virtual void animationLogic();
    
   
    //Schedule Update
    virtual void update(float delta);
    virtual void updateMessages();
    
   
};

#endif // _FARM_SCENE_H_
