#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class HelloWorld : public cocos2d::CCLayerColor
{
protected:
    
private:
    
public:
    virtual bool init();
    
    static cocos2d::CCScene* scene();
    
    void menuCloseCallback(CCObject* pSender);
    
    CREATE_FUNC(HelloWorld);
    
    // Send Messages
    virtual void sendOnclick();
    
    // HTTP
    virtual void onHttpRequestCompleted(cocos2d::CCNode *sender, void *data);
    
    // UUID Getter
    virtual const char* getUUID();
    virtual const char* getName();
    virtual const char* getMessages();
    virtual const char* getFood();
    
    // JSON Generator
    virtual void jsonGenerator(int, char*, std::pair<const char*, const char*>[]);
    
    
};

#endif // __HELLOWORLD_SCENE_H__
