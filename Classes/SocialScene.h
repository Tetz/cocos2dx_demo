#ifndef _SOCIALSCENE_SCENE_H_
#define _SOCIALSCENE_SCENE_H_

#include "cocos2d.h"
#include "all_in_one.h"

class SocialScene : public cocos2d::CCLayerColor
{
protected:
    
private:
    
public:
    virtual bool init();
    static CCScene * scene();
    CREATE_FUNC(SocialScene);
    virtual void main();
    
    // HTTP
    virtual void load();
    virtual void addFriend();
    virtual void removeFriend();
    virtual void onHttpRequestCompleted(CCNode *sender, void *data);

    
};

#endif // _SOCIALSCENE_SCENE_H_