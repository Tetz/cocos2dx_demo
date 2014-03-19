//
//  ModalLayer.h
//  MessagePlus
//
//  Created by ted on 1/30/14.
//
//

#ifndef _ModalLayer_
#define _ModalLayer_

#include "all_in_one.h"

class ModalLayer : public cocos2d::CCLayer
{
public:
    virtual bool init();
    void menuCloseCallback(CCObject* pSender);
    virtual bool ccTouchBegan(cocos2d::CCTouch *pTouch, cocos2d::CCEvent *pEvent);
    CREATE_FUNC(ModalLayer);
};

#endif /* defined(_ModalLayer_) */
