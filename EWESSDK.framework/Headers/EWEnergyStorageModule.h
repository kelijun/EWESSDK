//
//  EWEnergyStorageModule.h
//  EwayBLETools
//
//  Created by developer on 2025/9/5.
//

#import <Foundation/Foundation.h>
#import "EWEnergyStorageModuleProfiles.h"

NS_ASSUME_NONNULL_BEGIN

@interface EWEnergyStorageModule : NSObject

/// 蓝牙状态发生变化
@property (nonatomic, copy) EWBluetoothDidUpdateStateHandler bluetoothDidUpdateStateHandler;

///单例
+ (instancetype)share;

/// 配置连接的ES模块（连接成功后传入连接的设备）
/// - Parameters:
///   - esModule: 连接的ES模块
///   - handler: 配置结果回调
- (void)ew_configureConnectedESModule: (EWPeripheral *)esModule
                               handler:(EWESModuleResultHandler)handler;

/// ES读写机型码
/// - Parameters:
///   - esModule: 连接的ES模块
///   - isWrite: 读/写
///   - productID: 机型码
///   - handler: 结果回调
- (void)ew_configProductIDWithESModule:(NSString *)esModuleName
                                isWrite:(BOOL)isWrite
                              productID:(nullable NSString *)productID
                                handler:(EWESModuleProductIDHandler)handler;

/// ES读写SN
/// - Parameters:
///   - esModule: 连接的ES模块
///   - isWrite: 读/写
///   - sn: sn
///   - handler: 结果回调
- (void)ew_configSNWithESModule:(NSString *)esModuleName
                                isWrite:(BOOL)isWrite
                              sn:(nullable NSString *)sn
                                handler:(EWESModuleSNHandler)handler;

/// 获取ES WiFi状态
/// - Parameters:
///   - esModuleName: ES蓝牙广播号
///   - handler: 获取ES Wi-Fi 状态回调
- (void)ew_getESModuleWiFiStatus:(NSString *)esModuleName
                          handler:(EWESModuleWiFiStatusHandler)handler;

/// 给ES传输 WiFi 信息
/// - Parameters:
///   - esModuleName: ES蓝牙广播号
///   - SSID: Wi-Fi名称
///   - password: Wi-Fi密码
///   - handler: 获取ES Wi-Fi 状态回调
- (void)ew_transmitWiFiInformationToESModule:(NSString *)esModuleName
                                         SSID:(NSString *)SSID
                                     password:(nullable NSString *)password
                                      handler:(EWESModuleWiFiStatusHandler)handler;

/// ES连接 WiFi
/// - Parameters:
///   - esModuleName: ES蓝牙广播号
///   - handler: 获取ES Wi-Fi 状态回调
- (void)ew_esModuleConnectWiFi:(NSString *)esModuleName
                        handler:(EWESModuleWiFiStatusHandler)handler;

/// 断开ES WiFi
/// - Parameters:
///   - esModuleName: ES蓝牙广播号
///   - handler: 获取ES Wi-Fi 状态回调
- (void)ew_disconnectESModuleWiFi:(NSString *)esModuleName
                          handler:(EWESModuleWiFiStatusHandler)handler;

/// 获取ES WiFi信息
/// - Parameters:
///   - esModuleName: ES蓝牙广播号
///   -  handler: 获取ES Wi-Fi 信息回调
- (void)ew_getESModuleWiFiInformation:(NSString *)esModuleName
                               handler:(EWESModuleWiFiInfoHandler)handler;

/// 重置ES WiFi
/// - Parameters:
///   - esModuleName: ES蓝牙广播号
///   -  handler: 重置回调
- (void)ew_resetESModuleWiFi:(NSString *)esModuleName
                      handler:(EWESModuleResultHandler)handler;

/// 配置服务器地址
/// - Parameters:
///   - esModuleName: ES名字
///   - isWrite: 是否写入
///   - urlAddress: 服务器地址
///   - handler: 回调
- (void)ew_configUrlAddressWithESModule:(NSString *)esModuleName
                                 isWrite:(BOOL)isWrite
                              urlAddress: (nullable NSString *)urlAddress
                                 handler:(EWESModuleUrlAddressHandler)handler;

/// 配置MQTT账号密码
/// - Parameters:
///   - esModuleName: ES蓝牙广播号
///   - isWrite: 是否写入
///   - account: mqtt账号
///   - password: mqtt密码
///   - handler: 回调
- (void)ew_configAccountAndPasswordWithESModule:(NSString *)esModuleName
                                           isWrite:(BOOL)isWrite
                                                account:(nullable NSString *)account
                                               password:(nullable NSString *)password
                                               handler:(EWESModuleAccountAndPasswordHandler)handler;


/// 获取储能在线状态
/// - Parameters:
///   - esModuleSN: 储能 SN
///   - handler: 回调
- (void)ew_getOnlineStatus:(NSString *)esModuleSN
                   handler:(EWESModuleResultHandler)handler;
@end

NS_ASSUME_NONNULL_END
