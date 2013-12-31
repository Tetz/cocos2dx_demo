//
//  Getter.cpp
//  MessagePlus
//
//  Created by ted on 12/31/13.
//
//

#include "Getter.h"

// Getter
std::string Getter::getUUID()
{
    // Java Native Interface
    static std::string uuid;
    #if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
    InterfaceJNI::func1();
    uuid = InterfaceJNI::getUUID();
    #endif
    return uuid;
}

const char * Getter::getName()
{
    const char * name = "Miky";
    return name;
}

const char * Getter::getMessages()
{
    const char * uuid = "Hello, I am Miky! How are you doing?";
    return uuid;
}

const char * Getter::getFood()
{
    CCString ccstr = "test";
    const char * uuid = "meat";
    return uuid;
}