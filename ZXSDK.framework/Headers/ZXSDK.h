//
//  ZXSDK.h
//  ZXSDK
//
//  Created by zx on 2021-03-10.
//  ZXSDK-Version: 1.2.1.5177

#import <Foundation/Foundation.h>

//! Project version number for ZXSDK.
FOUNDATION_EXPORT double ZXSDKVersionNumber;

//! Project version string for ZXSDK.
FOUNDATION_EXPORT const unsigned char ZXSDKVersionString[];
@class ZXSDKResultModel;
typedef void (^ZXSDKCallback)(ZXSDKResultModel *_Nullable model, NSError *_Nullable error);
typedef void (^ZXSDKVerifyCallback)(BOOL success, NSError *_Nullable error);

@interface ZXSDKResultModel : NSObject
@property (nonatomic, copy, nonnull) NSString *zxid;
@property (nonatomic, copy, nonnull) NSString *expireTime;
@end

@interface ZXSDK : NSObject

+ (void)startSdkWithAppId:(NSString * _Nonnull)appId callback:(ZXSDKCallback _Nonnull)callback;

+ (void)verify:(NSString * _Nonnull)zxid callback:(ZXSDKVerifyCallback _Nullable)callback;

/// 读取卓信ID开关
+ (BOOL)enable;

/// 设置卓信ID开关
/// @param enable YES:打开（默认）   NO:关闭
+ (void)setEnable:(BOOL)enable;

/// 设置是否提示权限弹窗
/// @param allow  YES:提示（默认）   NO:不提示
+ (void)allowPermissionDialog:(BOOL)allow;

/// sdk版本号
+ (NSString * _Nonnull)version;

@end
