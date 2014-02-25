#ifndef _MenuBarLayer_
#define _MenuBarLayer_

#include "cocos2d.h"
#include "cocos-ext.h"
USING_NS_CC;
USING_NS_CC_EXT;

class MenuBarLayer : public CCLayer
{
public:
    virtual bool init();
    void menuCloseCallback(CCObject* pSender);
    virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    CREATE_FUNC(MenuBarLayer);
};

#endif /* defined(_MenuBarLayer_) */
