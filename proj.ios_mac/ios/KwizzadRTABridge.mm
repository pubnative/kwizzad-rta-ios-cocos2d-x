//
//  KwizzadRTABridge.m
//  RtaCocos-mobile
//
//  Created by Fares Ben Hamouda on 17.12.19.
//

#import "KwizzadRTABridgeNativeAPI.h"
#import "KwizzadRTABridge.h"
#import "AppController.h"
#import "HelloWorldScene.h"

@implementation KwizzadRTABridge
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
#pragma mark KwizzadRTABridge Native API Implementation

void initKwizzadRTA (const char *token) {
    [KwizzadRTA setTestMode:YES];
    [KwizzadRTA configureWith:[NSString stringWithFormat:@"%s", token] completion:^(BOOL finished) {
        NSLog(@"SDK configuration status: %@", finished ? @"success" : @"fail" );
    }];
}

void loadwizzadRTA (const char *placement) {
    KwizzadRTABridge* bridge = [[KwizzadRTABridge alloc]init];
    [KwizzadRTABridge.kwizzad loadWithPlacement:[NSString stringWithFormat:@"%s", placement]  delegate: bridge];
}

void showKwizzadRTA (){
    [KwizzadRTABridge.kwizzad showAdFrom: [KwizzadRTABridge viewController]];
}

void showDebugScreen (){
    [KwizzadRTA showDebugScreenFrom:[KwizzadRTABridge viewController] instances: [NSArray arrayWithObjects: KwizzadRTABridge.kwizzad, nil]];
}

void showConsentScreen (){
    [KwizzadRTA showConsentScreenFrom:[KwizzadRTABridge viewController] completion:^(BOOL consentGiven) {
    }];
}
