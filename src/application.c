//
//  application.c
//  gmchain-core
//
//  Created by AnonymityMaster on 2019/12/18.
//  Copyright © 2019 ci6. All rights reserved.
//

#include "application.h"
#include <stdlib.h>
#include <stdbool.h>

#include "module/gmc_hash.h"

AppLog* initAppLog(void){
    AppLog* ptr;
    ptr = (AppLog *)malloc(sizeof(AppLog));
    return ptr;
};

CommandLineParser* initCommandLineParser(int argc, const char * argv[]){
    CommandLineParser* ptr;
    ptr = (CommandLineParser *)malloc(sizeof(CommandLineParser));
    return ptr;
};

RuntimeEnv* initEnv(){
    RuntimeEnv* ptr;
    ptr = (RuntimeEnv *)malloc(sizeof(RuntimeEnv));
    return ptr;
};

KeyPairManage* initKeyPairManage(){
    KeyPairManage* ptr;
    ptr = (KeyPairManage *)malloc(sizeof(KeyPairManage));
    return ptr;
}

CryptoManage* initCryptoManage(){
    CryptoManage* ptr;
    ptr = (CryptoManage *)malloc(sizeof(CryptoManage));
    return ptr;
}

StorageManage* initStorageManage(){
    StorageManage* ptr;
    ptr = (StorageManage *)malloc(sizeof(StorageManage));
    return ptr;
}

Block* initBlock(){
    Block* ptr;
    ptr = (Block *)malloc(sizeof(Block));
    return ptr;
}

BlockDB* initBlockDB(){
    BlockDB* ptr;
    ptr = (BlockDB *)malloc(sizeof(BlockDB));
    return ptr;
}

HyperNode* initHyperNode(){
    HyperNode* ptr;
    ptr = (HyperNode *)malloc(sizeof(HyperNode));
    return ptr;
}

P2PNetworking* initP2PNetworking(){
    P2PNetworking* ptr;
    ptr = (P2PNetworking *)malloc(sizeof(P2PNetworking));
    return ptr;
}

bool checkReady(void){
    return true;
}

void start(void){
    
}
