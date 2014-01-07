#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class HelloWorld : public cocos2d::CCLayerColor
{
protected:
    
private:
    int randNum;
    const char * monsterAry[4];
    
public:
    virtual bool init();
    
    static cocos2d::CCScene * scene();
    
    void menuCloseCallback(CCObject * pSender);
    
    CREATE_FUNC(HelloWorld);
    
    // This is button that puts monster
    virtual void onClick1();
    virtual void onClick2();
    
    // HTTP
    virtual void onHttpRequestCompleted(cocos2d::CCNode *sender, void *data);
    virtual void onHttpRequestCompleted2(cocos2d::CCNode *sender, void *data);
   
   
};

#endif // __HELLOWORLD_SCENE_H__
