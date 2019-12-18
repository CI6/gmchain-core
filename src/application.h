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
#include "app_log.h"
#include "command_line_parser.h"
#include "runtime_env.h"
#include "keypair_manage.h"
#include "crypto_manage.h"
#include "storage_manage.h"
#include "chain/block.h"
#include "chain/block_db.h"
#include "chain/hyper_node.h"
#include "network/p2p_networking.h"

typedef struct {
    CommandLineParser* config;
    RuntimeEnv* env;
} Application;

AppLog * initAppLog(void);
CommandLineParser* initCommandLineParser(int, const char**);
RuntimeEnv* initEnv(void);
KeyPairManage* initKeyPairManage(void);
CryptoManage* initCryptoManage(void);
StorageManage* initStorageManage(void);
Block* initBlock(void);
BlockDB* initBlockDB(void);
HyperNode* initHyperNode(void);
P2PNetworking* initP2PNetworking(void);
int checkReady(void);
void start(void);


#endif /* application_h */
