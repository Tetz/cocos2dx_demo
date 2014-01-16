#ifndef _FARM_SCENE_H_
#define _FARM_SCENE_H_

#include "cocos2d.h"

class FarmScene : public cocos2d::CCLayerColor
{
protected:
   
private:
    const char * monsterAry[4];
    cocos2d::CCSize visibleSize;
    // Animation
    int randNum;
    int mLoopCount;
    
public:
    virtual bool init();
    static cocos2d::CCScene * scene();
    void menuCloseCallback(CCObject * pSender);
    
    CREATE_FUNC(FarmScene);
    
    // This is button that puts monster
    virtual void onClick1();
    virtual void onClick2();
    
    // HTTP
    virtual void onHttpRequestCompleted(cocos2d::CCNode *sender, void *data);
    virtual void onHttpRequestCompleted2(cocos2d::CCNode *sender, void *data);
    
    // Animation
    virtual void animationLogic();
    
    // Change Scene
    virtual void toFriendsListScene();
   
};

#endif // _FARM_SCENE_H_
