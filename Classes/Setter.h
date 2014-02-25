//
//  Setter.h
//  MessagePlus
//
//  Created by ted on 1/8/14.
//
//

#ifndef _Setter_
#define _Setter_

#include "cocos2d.h"
#include "cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include "JNICalls/InterfaceJNI.h"
#endif


class Setter : public cocos2d::CCLayerColor
{
public:
    static void setBackground(cocos2d::CCLayerColor * context);
    static void setBackground_list(cocos2d::CCLayerColor * context);
};

#endif /* defined(_Setter_) */
