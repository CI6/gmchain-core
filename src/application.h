//
//  application.h
//  gmchain-core
//
//  Created by AnonymityMaster on 2019/12/18.
//  Copyright © 2019 ci6. All rights reserved.
//

#ifndef application_h
#define application_h

#include <stdio.h>
#include <stdbool.h>
#include "app_log.h"
#include "command_line_parser.h"
#include "runtime_env.h"
#include "keypair_manage.h"
#include "crypto_manage.h"
#include "storage_manage.h"
#include "chain_manage.h"
#include "temp_manage.h"

typedef struct {
    AppLog* applog;
    CommandLineParser* command_line_parser;
    RuntimeEnv* env;
    KeyPairManage* key_pair_manage;
    CryptoManage* crypto_manage;
    StorageManage* storage_manage;
    TempManage* temp_manage;
    ChainManage* chain_manage;
} Application;

void initialize(int, const char**);

static AppLog * initAppLog(void);
static CommandLineParser* initCommandLineParser(int, const char**);
static RuntimeEnv* initEnv(void);
static KeyPairManage* initKeyPairManage(void);
static CryptoManage* initCryptoManage(void);
static StorageManage* initStorageManage(void);
static TempManage* initTempManage(void);
static ChainManage* initChainManage(void);

bool checkReady(void);
void start(void);
void appClear(void);

#endif /* application_h */
