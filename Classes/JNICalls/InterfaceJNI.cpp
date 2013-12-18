#include "InterfaceJNI.h"
#include "platform/android/jni/JniHelper.h"
#include <jni.h>
#include <android/log.h>

#define  CLASS_NAME "dev/mplus/v1/MessagePlus"

void InterfaceJNI::func1()
{
    JniMethodInfo t;
    if (JniHelper::getStaticMethodInfo(t, CLASS_NAME, "func1", "()V")) {
        t.env->CallStaticVoidMethod(t.classID, t.methodID);
        t.env->DeleteLocalRef(t.classID);
    }
}

std::string InterfaceJNI::getUUID()
{
    std::string uuid;
    JniMethodInfo t;

    if (JniHelper::getStaticMethodInfo(t, CLASS_NAME, "getUUID", "()Ljava/lang/String;")) {
        jstring jStr = (jstring)t.env->CallStaticObjectMethod(t.classID, t.methodID);
        const char* str = t.env->GetStringUTFChars(jStr, NULL);
        uuid = str;

        t.env->ReleaseStringUTFChars(jStr,str);
        t.env->DeleteLocalRef(t.classID);
    }
    return uuid;
}
