//
//  KwizzadRTABridgeNativeAPI.h
//  RtaCocos
//
//  Created by Fares Ben Hamouda on 17.12.19.
//

#ifndef RTACOCOS_KWIZZADADSJNI_H
#define RTACOCOS_KWIZZADADSJNI_H

/* implement these functions with sdk api of different platforms */
#ifdef __cplusplus
extern "C" {
#endif

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    
        // Unity Ads required methods
        void initKwizzadRTA (const char *token);
        void loadwizzadRTA (const char *placement);
        void showKwizzadRTA ();
        void showDebugScreen ();
        void showConsentScreen ();

    #endif

#ifdef __cplusplus
}
#endif


#endif //RTACOCOS_KWIZZADADSJNI
