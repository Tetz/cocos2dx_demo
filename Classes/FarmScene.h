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
    int mLoopCount;
    // EditBox
    virtual void editBoxEditingDidBegin(CCEditBox* editBox);
    virtual void editBoxEditingDidEnd(CCEditBox* editBox);
    virtual void editBoxTextChanged(CCEditBox* editBox, const std::string& text);
    virtual void editBoxReturn(CCEditBox* editBox);
    
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
    
   
};

#endif // _FARM_SCENE_H_
