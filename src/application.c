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

Application* App;

void initialize(int argc, const char** argv){

    App = (Application *)malloc(sizeof(Application));
    App->argc = argc;
    App->argv = argv;
    App->applog = initAppLog();
    App->command_line_parser = initCommandLineParser();
    App->env = initEnv(argv[0]);
    App->key_pair_manage = initKeyPairManage();
    App->crypto_manage = initCryptoManage();
    App->storage_manage = initStorageManage();
    App->temp_manage = initTempManage();
    App->chain_manage = initChainManage();
    App->parserCommandLine = _parserCommandLine;
    App->checkEnv = _checkEnv;
    App->start = _start;
    return;
}

AppLog* initAppLog(void){
    AppLog* ptr;
    ptr = (AppLog *)malloc(sizeof(AppLog));
    return ptr;
};

CommandLineParser* initCommandLineParser(){
    CommandLineParser* ptr;
    ptr = (CommandLineParser *)malloc(sizeof(CommandLineParser));
    registerCommandLineInstance(ptr);
    return ptr;
};

RuntimeEnv* initEnv(char* root){
    RuntimeEnv* ptr;
    ptr = (RuntimeEnv *)malloc(sizeof(RuntimeEnv));
    strlcpy(ptr->root,root,256);
    registerRuntimeEnvInstance(ptr);
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

TempManage* initTempManage(){
    TempManage* ptr;
    ptr = (TempManage *)malloc(sizeof(TempManage));
    return ptr;
}

ChainManage* initChainManage(){
    ChainManage* ptr;
    ptr = (ChainManage *)malloc(sizeof(ChainManage));
    return ptr;
}

void _parserCommandLine(){
    startCommandLineParser(App->argc, App->argv, App->command_line_parser->setting);
}

bool _checkEnv(void){
    return true;
}

void _start(void){
    
}

void appClear(){
    free(App->applog);
    free(App->command_line_parser);
    free(App->env);
    free(App->key_pair_manage);
    free(App->crypto_manage);
    free(App->storage_manage);
    free(App->temp_manage);
    free(App->chain_manage);
    free(App);
}
