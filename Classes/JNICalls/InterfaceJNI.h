//  InterfaceJNI.cpp
//  Project Name : MessagePlus
//  Created at Oct 17, 2013.
//  Latest Updated at Dec 17, 2013.
//  Author : Tetsuro Takemoto
//  General Purpose : For Android, to call functions that are written in Java.

#ifndef __INTERFACEJNI__
#define __INTERFACEJNI__

#include <string.h>
#include "cocos2d.h"

using namespace std;
using namespace cocos2d;

class InterfaceJNI
{
public:
    static void func1();
    static std::string getUUID();
};
#endif
