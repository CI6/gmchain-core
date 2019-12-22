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

const char *KCType = "type";                                     // => 类型
const char *KCPath = "path";                                     // => 路径
const char *KCDatabase = "database";                             // => 数据库
const char *KCHost = "host";                                     // => 主机
const char *KCPort = "port";                                     // => 端口
const char *KCUser = "user";                                     // => 用户
const char *KCPassword = "password";                             // => 密码
const char *KCProposal = "proposal";                             // => 提案
const char *KCDelay = "delay";                                   // => 延时
const char *KCVoteDelay = "vote";                                // => 投票
const char *KCEnable = "enable";                                 // => 启用
const char *KCLog = "log";                                       // => 日志
const char *KCLevel = "level";                                   // => 级别
const char *KCAddress = "address";                               // => 地址
const char *KCPublicKey = "public_key";                          // => 公钥
const char *KCPrivateKey = "private_key";                        // => 私匙

const char *KCEnvDevelopment = "development";                    // => 开发环境
const char *KCEnvTest = "test";                                  // => 测试环境
const char *KCEnvProduction = "production";                      // => 生产环境


const char *KCBlockStorePath = "block_store_path";               // => 区块存储路径

#endif /* key_const_h */
