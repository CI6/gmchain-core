//
//  main.c
//  gmchain-core
//
//  Created by AnonymityMaster on 2019/12/17.
//  Copyright © 2019 ci6. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "application.h"
#include "basetypes.h"

int main(int argc, char** argv) {
    AppLog* applog = initAppLog();
    CommandLineParser* command_line_parser = initCommandLineParser(argc, argv);
    RuntimeEnv* run_time_env = initEnv();
    KeyPairManage* keypair_manger = initKeyPairManage();
    CryptoManage* crypto_manage = initCryptoManage();
    StorageManage* storage_manage = initStorageManage();
    Block* block = initBlock();
    BlockDB* block_db = initBlockDB();
    HyperNode* hyper_node = initHyperNode();
    P2PNetworking* p2p_networking = initP2PNetworking();
    bool result = checkReady();
    if (result){
        start();
    }else{
        printf("initialize failed!\n");
        return EXIT_FAILURE;
    }
    
    printf("[gmchain] hello ci6~\n");
    return EXIT_SUCCESS;
}
