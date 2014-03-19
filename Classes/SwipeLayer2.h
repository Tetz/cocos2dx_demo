#ifndef __SWIPELAYER2_H__
#define __SWIPELAYER2_H__

#include "cocos2d.h"
#include "cocos-ext.h"
#include "XTLayer.h"


USING_NS_CC;
USING_NS_CC_EXT;

class SwipeLayer2 : public XTLayer
{
public:
    virtual bool init();
    static CCScene* scene();
    CREATE_FUNC(SwipeLayer2);
    
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

#endif /* __SWIPELAYER2_H__ */
