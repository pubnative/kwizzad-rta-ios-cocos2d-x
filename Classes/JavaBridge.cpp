//
// Created by TVSMILES on 2019-11-05.
//


#if (CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID)
#include "platform/android/jni/JniHelper.h"
#include "HelloWorldScene.h"
#include "../../../../Library/Android/sdk/ndk-bundle/toolchains/llvm/prebuilt/darwin-x86_64/sysroot/usr/include/jni.h"


extern "C" {

    JNIEXPORT void JNICALL Java_org_cocos2dx_cpp_CBridge_notifyAdPreloadedState(JNIEnv *env, jclass type, jboolean preloaded)
    {

        HelloWorld::setShowRtaEnabled(preloaded);
    }

}
#endif