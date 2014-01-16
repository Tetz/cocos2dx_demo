#ifndef _SWIPELAYER3_H_
#define _SWIPELAYER3_H_

#include "cocos2d.h"
#include "cocos-ext.h"
#include "XTLayer.h"

USING_NS_CC;
USING_NS_CC_EXT;

class SwipeLayer3 : public XTLayer
{
public:
    virtual bool init();
    static CCScene* scene();
    CREATE_FUNC(SwipeLayer3);
    
    virtual void xtTouchesBegan(cocos2d::CCSet* _touches, cocos2d::CCEvent* event);
    virtual void xtTouchesMoved(cocos2d::CCSet* _touches, cocos2d::CCEvent* event);
    virtual void xtTouchesEnded(cocos2d::CCSet* _touches, cocos2d::CCEvent* event);
    
    virtual void xtTouchesBegan(CCPoint position);
    virtual void xtTouchesMoved(CCPoint position);
    virtual void xtTouchesEnded(CCPoint position);
    
    virtual void xtTapGesture(CCPoint position);
    virtual void xtDoubleTapGesture(CCPoint position);
    virtual void xtLongTapGesture(CCPoint position);
    virtual void xtSwipeGesture(XTTouchDirection direction, float distance, float speed);
};

#endif /* __SWIPELAYER3_H__ */

