#ifndef _SOCIALSCENE_SCENE_H_
#define _SOCIALSCENE_SCENE_H_

#include "cocos2d.h"

class SocialScene : public cocos2d::CCLayerColor
{
protected:
    
private:
    
public:
    virtual bool init();
    
    static cocos2d::CCScene * scene();
    
    CREATE_FUNC(SocialScene);
    
    virtual void main();

    
};

#endif // _SOCIALSCENE_SCENE_H_