//
//  EWEnergyStorageModuleProfiles.h
//  EwayBLETools
//
//  Created by developer on 2025/9/5.
//

#ifndef EWEnergyStorageModuleProfiles_h
#define EWEnergyStorageModuleProfiles_h

#import <EWBluetoothSDK/EWBluetoothSDK.h>

typedef NS_ENUM(NSUInteger, EWESCommandType) {
    EWESCommandTypeStart = 22, //启动
    EWESCommandTypeStop = 44, //停止
    EWESCommandTypeProductID = 0x00, // 配置机型码
    EWESCommandTypeSN = 0x01, //配置SN
    EWESCommandTypeNetwork = 0x08, // 配置wifi
    EWESCommandTypeConfigURL = 0x0E, //配置服务器URL
    EWESCommandTypeMQTTAccount = 0x0F, // 配置MQTT账号密码
};

typedef NS_ENUM(NSUInteger, EWESWiFiStatus) {
    EWESWiFiStatusDisconnect = 0x00,     // 未连接
    EWESWiFiStatusConnecting = 0x01,     // 连接中
    EWESWiFiStatusConnected = 0x02,      // 已连接
    EWESWiFiStatusConnectFailed = 0x03,  // 连接失败
    EWESWiFiStatusDisabled = 0x04,       // 不可用
    EWESWiFiStatusUnknow = 0x99,         // 未知
};

typedef NS_ENUM(NSUInteger, EWESNetworkCommand) {
    EWESNetworkCommandReadStatus = 0x00, // 阅读状态
    EWESNetworkCommandWriteSSID = 0x01,  // 写入名称
    EWESNetworkCommandWritePW = 0x02,    // 写入密码
    EWESNetworkCommandControl = 0x03,    // 控制
    EWESNetworkCommandInformation = 0x04,// Wi-Fi名称
    EWESNetworkCommandClear = 0x05,      // 清除Wi-Fi
};

// 蓝牙状态回调
typedef void (^EWBluetoothDidUpdateStateHandler)(EWBluetoothState state);
// 发现ES回调(蓝牙广播号)
typedef void (^EWScanESModuleHandler)(NSString *_Nullable esModuleName);
// ES消失回调(蓝牙广播号)
typedef void (^EWESModuleDisappearHandler)(NSString *_Nullable esModuleName);
// 停止扫描ES回调(是否成功)
typedef void (^EWStopScanESModuleHandler)(BOOL success);
// ES成功失败结果回调(名称，成功否，错误)
typedef void (^EWESModuleResultHandler)(NSString * _Nullable esModuleName, BOOL result, NSError * _Nullable error);
// ES机型码回调(名称，机型码，错误)
typedef void (^EWESModuleProductIDHandler)(NSString * _Nullable esModuleName, NSString * _Nullable productID, NSError * _Nullable error);
// ES sn回调(名称，机型码，错误)
typedef void (^EWESModuleSNHandler)(NSString * _Nullable esModuleName, NSString * _Nullable sn, NSError * _Nullable error);
// 获取ES Wi-Fi 状态(名称，Wi-Fi 状态，错误信息)
typedef void (^EWESModuleWiFiStatusHandler)(NSString * _Nullable esModuleName, EWESWiFiStatus status, NSError * _Nullable error);
// 获取ES Wi-Fi信息(名称，Wi-Fi，错误信息)
typedef void (^EWESModuleWiFiInfoHandler)(NSString * _Nullable esModuleName, NSString * _Nullable wifiName,  NSError * _Nullable error);
// ES服务器地址回调(名称，服务器地址，错误)
typedef void (^EWESModuleUrlAddressHandler)(NSString * _Nullable esModuleName, NSString * _Nullable urlAddress, NSError * _Nullable error);
//配置mqtt账号密码回调 (名称，账号，密码，错误)
typedef void (^EWESModuleAccountAndPasswordHandler)(NSString * _Nullable esModuleName, NSString * _Nullable account, NSString * _Nullable password, NSError * _Nullable error);

#endif /* EWEnergyStorageModuleProfiles_h */
