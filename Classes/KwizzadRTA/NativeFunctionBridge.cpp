//
//  NativeFunctionBridge.cpp
//  RtaCocos-mobile
//
//  Created by Fares Ben Hamouda on 18.12.19.
//

#include "NativeFunctionBridge.h"
#include "iOSNativeFunctionBridge.h"

void NativeFunctionBridge::initKwizzadRTA(const char *token) {
    #if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
        
        //Andorid
        
    #elif CC_TARGET_PLATFORM == CC_PLATFORM_IOS
        
        //iOS
        iOSinitKwizzadRTA(token);
    #endif
}

void NativeFunctionBridge::loadwizzadRTA(const char *placement) {
    #if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
        
        //Andorid
        
    #elif CC_TARGET_PLATFORM == CC_PLATFORM_IOS
        
        //iOS
        iOSloadwizzadRTA(placement);
    #endif
}

void NativeFunctionBridge::showKwizzadRTA() {
    #if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
        
        //Andorid
        
    #elif CC_TARGET_PLATFORM == CC_PLATFORM_IOS
        
        //iOS
        iOSshowKwizzadRTA();
    #endif
}

void NativeFunctionBridge::showDebugScreen() {
    #if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
        
        //Andorid
        
    #elif CC_TARGET_PLATFORM == CC_PLATFORM_IOS
        
        //iOS
        iOSshowDebugScreen();
    #endif
}

void NativeFunctionBridge::showConsentScreen() {
    #if CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
        
        //Andorid
        
    #elif CC_TARGET_PLATFORM == CC_PLATFORM_IOS
        
        //iOS
        iOSshowDebugScreen();
    #endif
}
