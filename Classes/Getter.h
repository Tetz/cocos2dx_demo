//
//  Getter.h
//  MessagePlus
//
//  Created by ted on 12/31/13.
//
//

#ifndef _Getter_
#define _Getter_

#include "cocos2d.h"
#include "cocos-ext.h"
#include "spine/Json.h"

USING_NS_CC;
USING_NS_CC_EXT;

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include "JNICalls/InterfaceJNI.h"
#endif


class Getter : public cocos2d::CCLayerColor
{
public:
    
    static std::string getUUID();
    virtual const char * getName();
    virtual const char * getMessages();
    virtual const char * getFood();
    
    
};

#endif /* defined(_Getter_) */
