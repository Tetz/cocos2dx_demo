#include "cocos2d.h"
#include "cocos-ext.h"
#include "spine/Json.h"
#include "picojson.h"
#include "DefTags.h"
#include "Getter.h"
#include "Setter.h"
#include "JsonGenerator.h"
#include "SwipeLayer.h"
#include "SwipeLayer2.h"
#include "SwipeLayer3.h"
#include "Database.h"
#include "allScene.h"
#include "MenuBarLayer.h"

//Langage
#include "lang_ja.h"


#include <iostream>
#include <fstream>
#include <sstream>
#include <string>


USING_NS_CC;
USING_NS_CC_EXT;
using namespace std;

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include "JNICalls/InterfaceJNI.h"
#endif

