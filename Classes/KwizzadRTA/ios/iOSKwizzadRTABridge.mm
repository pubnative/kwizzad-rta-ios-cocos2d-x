//
//  KwizzadRTABridge.m
//  RtaCocos-mobile
//
//  Created by Fares Ben Hamouda on 17.12.19.
//

#import "iOSKwizzadRTABridge.h"
#import "iOSNativeFunctionBridge.h"
#import "AppController.h"
#import "HelloWorldScene.h"

@implementation iOSKwizzadRTABridge
+ (UIViewController* ) viewController {
    
    UIApplication* app = [UIApplication sharedApplication];
    AppController* controller = (AppController*)[app delegate];
    UIViewController* rootController = [controller.window rootViewController];
    return rootController;
}

// Single KwizzadRTA Instance.
+ (KwizzadRTA *)kwizzad {
    static KwizzadRTA *sharedInstance = nil;

    if (sharedInstance == nil) {
        sharedInstance = [[KwizzadRTA alloc] init];
    }

    return sharedInstance;
}

#pragma mark -
#pragma mark KwizzadRTA delegate

- (void)onAdAvailableWithPlacementId:(NSString * _Nonnull)placementId {
    auto scene = cocos2d::Director::getInstance()->getRunningScene();
    if (typeid(*scene) == typeid(HelloWorld)) {
        HelloWorld* gameScene = static_cast<HelloWorld*>(scene);
        gameScene->setShowRtaEnabled(true);
    }
}

- (void)onAdCanceledWithPlacementId:(NSString * _Nonnull)placementId params:(NSDictionary<NSString *,id> * _Nullable)params {
    
}

- (void)onAdErrorWithPlacementId:(NSString * _Nonnull)placementId error:(NSString * _Nonnull)error params:(NSDictionary<NSString *,id> * _Nullable)params {
    
}

- (void)onAdFailedToLoadWithPlacementId:(NSString * _Nonnull)placementId {
    auto scene = cocos2d::Director::getInstance()->getRunningScene();
    if (typeid(*scene) == typeid(HelloWorld)) {
        HelloWorld* gameScene = static_cast<HelloWorld*>(scene);
        gameScene->setShowRtaEnabled(false);
    }
}

- (void)onAdFinishedWithPlacementId:(NSString * _Nonnull)placementId params:(NSDictionary<NSString *,id> * _Nullable)params {
    
}

- (void)onAdPassbackWithPlacementId:(NSString * _Nonnull)placementId params:(NSDictionary<NSString *,id> * _Nullable)params {
    
}

@end



#pragma mark -
#pragma mark iOSKwizzadRTABridge Native API Implementation

void iOSinitKwizzadRTA (const char *token) {
    [KwizzadRTA setTestMode:YES];
    [KwizzadRTA configureWith:[NSString stringWithFormat:@"%s", token] completion:^(BOOL finished) {
        NSLog(@"SDK configuration status: %@", finished ? @"success" : @"fail" );
    }];
}

void iOSloadwizzadRTA (const char *placement) {
    iOSKwizzadRTABridge* bridge = [[iOSKwizzadRTABridge alloc]init];
    [iOSKwizzadRTABridge.kwizzad loadWithPlacement:[NSString stringWithFormat:@"%s", placement]  delegate: bridge];
}

void iOSshowKwizzadRTA (){
    [iOSKwizzadRTABridge.kwizzad showAdFrom: [iOSKwizzadRTABridge viewController]];
}

void iOSshowDebugScreen (){
    [KwizzadRTA showDebugScreenFrom:[iOSKwizzadRTABridge viewController] instances: [NSArray arrayWithObjects: iOSKwizzadRTABridge.kwizzad, nil]];
}

void iOSshowConsentScreen (){
    [KwizzadRTA showConsentScreenFrom:[iOSKwizzadRTABridge viewController] completion:^(BOOL consentGiven) {
    }];
}
