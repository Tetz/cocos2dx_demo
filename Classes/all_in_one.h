#include "cocos2d.h"
#include "cocos-ext.h"
#include "spine/Json.h"
#include "picojson.h"
#include "DefTags.h"
#include "Getter.h"
#include "Setter.h"
#include "JsonGenerator.h"
#include <string>
#include "SwipeLayer.h"
#include "SwipeLayer2.h"
#include "SwipeLayer3.h"

USING_NS_CC;
USING_NS_CC_EXT;

#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include "JNICalls/InterfaceJNI.h"
#endif

