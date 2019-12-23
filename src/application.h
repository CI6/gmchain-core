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
    int argc;
    const char** argv;
    AppLog* applog;
    CommandLineParser* command_line_parser;
    RuntimeEnv* env;
    KeyPairManage* key_pair_manage;
    CryptoManage* crypto_manage;
    StorageManage* storage_manage;
    TempManage* temp_manage;
    ChainManage* chain_manage;
    bool (*checkEnv)(void);
    void (*start)(void);
    void (*parserCommandLine)(void);
    bool (*isDaemonize)(void);
} Application;

void initialize(int, const char**);
void appClear(void);

static AppLog * initAppLog(void);
static CommandLineParser* initCommandLineParser(void);
static RuntimeEnv* initEnv(char*);
static KeyPairManage* initKeyPairManage(void);
static CryptoManage* initCryptoManage(void);
static StorageManage* initStorageManage(void);
static TempManage* initTempManage(void);
static ChainManage* initChainManage(void);

static void _parserCommandLine(void);
static bool _checkEnv(void);
static void _start(void);
static bool _isDaemonize(void);

#endif /* application_h */
