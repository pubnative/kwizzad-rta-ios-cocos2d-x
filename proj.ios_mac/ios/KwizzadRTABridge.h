//
//  KwizzadRTABridge.h
//  RtaCocos-mobile
//
//  Created by Fares Ben Hamouda on 17.12.19.
//

#import <KwizzadRTA/KwizzadRTA-Swift.h>
#import <Foundation/Foundation.h>

@interface KwizzadRTABridge : UIViewController<KwizzadRTADelegate>

+ (UIViewController* ) viewController;
+ (KwizzadRTA*) kwizzad;

@end


