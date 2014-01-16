#ifndef _FRIENDSLIST_SCENE_H_
#define _FRIENDSLIST_SCENE_H_

#include "cocos2d.h"

class FriendsListScene : public cocos2d::CCLayerColor
{
protected:
    
private:
    
public:
    virtual bool init();
    
    static cocos2d::CCScene * scene();
    
    CREATE_FUNC(FriendsListScene);
    
    virtual void main();

    
};

#endif // _FRIENDSLIST_SCENE_H_