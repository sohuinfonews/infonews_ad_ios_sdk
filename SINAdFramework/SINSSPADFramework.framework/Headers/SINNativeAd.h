//
//  SINNativeAd.h
//  SINSSPADFramework
//
//  Created by 肖潇 on 2019/10/21.
//  Copyright © 2019 Sohu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "SINAdMaterialModel.h"
#import "SINAdConfig.h"


NS_ASSUME_NONNULL_BEGIN
@protocol SINNativeAdDelegate;


@interface SINNativeAd : NSObject

// -----   测试代码  ------
@property (nonatomic, assign) NSInteger adType;
// todo:之后用 nativeAd 里面的loader 替换
@property (nonatomic, strong, nullable) SINAdMaterialModel *data;

/**
 Ad Config description.  AdConfig
 */
@property (nonatomic, strong, readwrite, nullable) SINAdConfig *adConfig;

/**
 Ad Config material.
 */
//@property (nonatomic, strong, readonly, nullable) SINAdMaterialModel *data;



/**
 The delegate for receiving state change messages.
 The delegate is not limited to viewcontroller.
 The delegate can be set to any object which conforming to <SINNativeAdDelegate>.
 */
@property (nonatomic, weak, readwrite, nullable) id<SINNativeAdDelegate> delegate;

/**
 required.
 Root view controller for handling ad actions.
 Action method includes 'pushViewController' and 'presentViewController'.
 */
@property (nonatomic, weak, readwrite) UIViewController *rootViewController;

/**
 Initializes native ad with ad config.
 @param adConfig : ad config description.
               including configID,adType,adPosition,etc.
 @return SINNativeAd
 */
- (instancetype)initWithAdConfig:(SINAdConfig *)adConfig;

/**
 Register clickable views in native ads view.
 @param containerView : required.
                        container view of the native ad.
 */
- (void)registerContainer:(__kindof UIView *)containerView;

/**
 Unregister ad view from the native ad.
 */
- (void)unregisterView;

/**
 Actively request nativeAd datas.
 */
- (void)loadAdData;

/**
 广告呈现时调用该方法，(支持重复上报，初期有，后期找替代方式)
 */
- (void)adPresented;

/**
 广告点击时调用该方法 (初期有，后期找替代方式)
 */
- (void)adClicked;


@end


@protocol SINNativeAdDelegate <NSObject>

@optional

/**
 This method is called when native ad material loaded successfully.
 */
- (void)nativeAdDidLoad:(SINNativeAd *)nativeAd;

/**
 This method is called when native ad materia failed to load.
 @param error : the reason of error
 */
- (void)nativeAd:(SINNativeAd *)nativeAd didFailWithError:(NSError *_Nullable)error;

/**
 This method is called when native ad slot has been shown.
 */
- (void)nativeAdDidBecomeVisible:(SINNativeAd *)nativeAd;

/**
 This method is called when another controller has been closed.
 
 */
- (void)nativeAdDidCloseOtherController:(SINNativeAd *)nativeAd;

/**
 This method is called when native ad is clicked.
 */
- (void)nativeAdDidClick:(SINNativeAd *)nativeAd withView:(UIView *_Nullable)view;

@end

NS_ASSUME_NONNULL_END
