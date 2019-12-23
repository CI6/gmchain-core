//
//  const_string.h
//  gmchain-core
//
//  Created by AnonymityMaster on 2019/12/22.
//  Copyright © 2019 ci6. All rights reserved.
//

#ifndef key_const_h
#define key_const_h

#include <stdio.h>

static const char *KCType = "type";                                     // => 类型
static const char *KCPath = "path";                                     // => 路径
static const char *KCDatabase = "database";                             // => 数据库
static const char *KCHost = "host";                                     // => 主机
static const char *KCPort = "port";                                     // => 端口
static const char *KCUser = "user";                                     // => 用户
static const char *KCPassword = "password";                             // => 密码
static const char *KCProposal = "proposal";                             // => 提案
static const char *KCDelay = "delay";                                   // => 延时
static const char *KCVoteDelay = "vote";                                // => 投票
static const char *KCEnable = "enable";                                 // => 启用
static const char *KCLog = "log";                                       // => 日志
static const char *KCLevel = "level";                                   // => 级别
static const char *KCAddress = "address";                               // => 地址
static const char *KCPublicKey = "public_key";                          // => 公钥
static const char *KCPrivateKey = "private_key";                        // => 私匙

static const char *KCEnvDevelopment = "development";                    // => 开发环境
static const char *KCEnvTest = "test";                                  // => 测试环境
static const char *KCEnvProduction = "production";                      // => 生产环境

static const char *KCTRACE = "TRACE";                                   // => 日志[DEBUG]
static const char *KCDEBUG = "DEBUG";                                   // => 日志[DEBUG]
static const char *KCINFO = "INFO";                                     // => 日志[INFO]
static const char *KCWARN = "WARN";                                     // => 日志[WARN]
static const char *KCERROR = "ERROR";                                   // => 日志[ERROR]
static const char *KCFATAL = "FATAL";                                   // => 日志[FATAL]

static const char *KCBlockStorePath = "block_store_path";               // => 区块存储路径

#endif /* key_const_h */
