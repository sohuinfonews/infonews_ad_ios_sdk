//
//  SINAdRelatedView.h
//  SINSSPADFramework
//
//  Created by 肖潇 on 2019/11/4.
//  Copyright © 2019 Sohu. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "SINNativeAd.h"
#import "SINSize.h"


NS_ASSUME_NONNULL_BEGIN

@protocol SINAdRelatedViewDelegate;


@interface SINAdRelatedView : NSObject
@property (nonatomic, weak, nullable) id<SINAdRelatedViewDelegate> delegate;


/// 初始化方法
/// @param adID 广告ID
/// @param adSize 图片尺寸 （目前没有用）
/// @param rootViewController 用于跳转
/// @param containerView 包含广告的view，RelatedView会填充满containerView，两者的frame需要设定成一致
- (instancetype)initWithAdID:(NSString *)adID
                        size:(SINSize *)adSize
          rootViewController:(UIViewController *)rootViewController
                   container:(UIView *)containerView;

- (void)loadAdData;

/**
 每次获得新数据时刷新数据，以便更好的显示广告。 (现在外部还获取不到，预留接口)
 */
- (void)refreshData:(SINNativeAd *)nativeAd;

/**
 Promotion label.Need to actively add to the view.
 */
@property (nonatomic, strong, readonly, nullable) UILabel *adLabel;
/**
 Ad logo.Need to actively add to the view.
 */
@property (nonatomic, strong, readonly, nullable) UIImageView *logoImageView;
/**
 Ad logo + Promotion label.Need to actively add to the view.
 */
@property (nonatomic, strong, readonly, nullable) UIImageView *logoADImageView;

@end


@protocol SINAdRelatedViewDelegate <NSObject>

@optional

/**
 This method is called when relatedView ad slot loaded successfully.
 @param relatedView : view for relatedView
 @param nativeAd : nativeAd for relatedView
 */
- (void)relatedViewDidLoad:(SINAdRelatedView *)relatedView WithAdmodel:(SINNativeAd *_Nullable)nativeAd;

/**
 This method is called when relatedView ad slot failed to load.
 @param error : the reason of error
 */
- (void)relatedView:(SINAdRelatedView *)relatedView didLoadFailWithError:(NSError *_Nullable)error;

/**
 This method is called when relatedView ad slot showed new ad.
 */
- (void)relatedViewDidBecomVisible:(SINAdRelatedView *)relatedView WithAdmodel:(SINNativeAd *_Nullable)nativeAd;

/**
 This method is called when relatedView is clicked.
 */
- (void)relatedViewDidClick:(SINAdRelatedView *)relatedView WithAdmodel:(SINNativeAd *_Nullable)nativeAd;

@end

NS_ASSUME_NONNULL_END
