LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := cocos2dcpp_shared

LOCAL_MODULE_FILENAME := libcocos2dcpp

LOCAL_SRC_FILES := hellocpp/main.cpp \
                   ../../Classes/AppDelegate.cpp \
                   ../../Classes/JNICalls/InterfaceJNI.cpp \
                   ../../Classes/Network.cpp \
                   ../../Classes/MyTableViewCell.cpp \
                   ../../Classes/SwipeLayer.cpp \
                   ../../Classes/SwipeLayer2.cpp \
                   ../../Classes/SwipeLayer3.cpp \
                   ../../Classes/MenuBarLayer.cpp \
                   ../../Classes/MainMenuBarLayer.cpp \
                   ../../Classes/StatusLayer.cpp \
                   ../../Classes/sqlite/sqlite3.c \
                   ../../Classes/Database.cpp \
                   ../../Classes/XTLayer.cpp \
                   ../../Classes/Getter.cpp \
                   ../../Classes/Setter.cpp \
                   ../../Classes/JsonGenerator.cpp \
                   ../../Classes/FriendsListScene.cpp \
                   ../../Classes/FSAlertLayer.cpp \
                   ../../Classes/SocialScene.cpp \
                   ../../Classes/SendScene.cpp \
                   ../../Classes/FarmScene.cpp

LOCAL_C_INCLUDES := $(LOCAL_PATH)/../../Classes

LOCAL_WHOLE_STATIC_LIBRARIES += cocos2dx_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocosdenshion_static
LOCAL_WHOLE_STATIC_LIBRARIES += box2d_static
LOCAL_WHOLE_STATIC_LIBRARIES += chipmunk_static
LOCAL_WHOLE_STATIC_LIBRARIES += cocos_extension_static

include $(BUILD_SHARED_LIBRARY)

$(call import-module,cocos2dx)
$(call import-module,cocos2dx/platform/third_party/android/prebuilt/libcurl)
$(call import-module,CocosDenshion/android)
$(call import-module,extensions)
$(call import-module,external/Box2D)
$(call import-module,external/chipmunk)
