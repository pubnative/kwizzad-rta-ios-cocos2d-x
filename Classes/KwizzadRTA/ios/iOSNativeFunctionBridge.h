//
//  iOSNativeFunctionBridge.h
//  RtaCocos
//
//  Created by Fares Ben Hamouda on 18.12.19.
//

#ifndef iOSNativeFunctionBridge_H
#define iOSNativeFunctionBridge_H

/* implement these functions with sdk api of different platforms */
#ifdef __cplusplus
extern "C" {
#endif

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)

        void iOSinitKwizzadRTA (const char *token);
        void iOSloadwizzadRTA (const char *placement);
        void iOSshowKwizzadRTA ();
        void iOSshowDebugScreen ();
        void iOSshowConsentScreen ();

    #endif

#ifdef __cplusplus
}
#endif


#endif //RTACOCOS_KWIZZADADSJNI
