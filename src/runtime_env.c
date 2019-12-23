//
//  runtime_env.c
//  gmchain-core
//
//  Created by AnonymityMaster on 2019/12/18.
//  Copyright © 2019 ci6. All rights reserved.
//

#include "runtime_env.h"
#include <stdbool.h>
#include "global.h"
#include "key_const.h"

bool _isProuction(){
    return strcmp(KCEnvProduction, App->command_line_parser->setting->env) == CMP_SUCCESS;
};

bool _isTest(){
    return strcmp(KCEnvTest, App->command_line_parser->setting->env) == CMP_SUCCESS;
};

bool _isDevelopment(){
    return strcmp(KCEnvDevelopment, App->command_line_parser->setting->env) == CMP_SUCCESS;
};

void loadRuntimeEnvModule(RuntimeEnv* env){
    env->isProduction = _isProuction;
    env->isTest = _isTest;
    env->isDevelopment = _isDevelopment;
};
