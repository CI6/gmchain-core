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
#include "global.h"
#include "app_log.h"
#include "test/test_unit.h"
#include "libs/secp256k1/secp256k1.h"

/**
 *  获取上下文
 */
static secp256k1_context* get_static_context()
{
    static secp256k1_context* ctx_both = 0;
    if (!ctx_both){
        ctx_both  = secp256k1_context_create(SECP256K1_CONTEXT_VERIFY | SECP256K1_CONTEXT_SIGN);
    }
    return ctx_both;
}

int main(int argc, const char** argv) {
    
    // 初始化 app
    initialize(argc, argv);
    
    // 解析命令行
    App->parserCommandLine();
    
    bool is_prod_env = App->env->isProduction();
    
    // 各种检测 bool
    bool check_init = true;
    
    // Todo 读取配置h文件
    
    // 初始化节点账号以及权限
    
    // 初始化 KeyPair 管理器,并加载本节点 public key, private key 和 游戏节点 public key, private key
    
    // 读取数据库配置并初始化连接
    
    // 读取 Block Storage 配置并初始化
    
    // 检查创世区块
    
    // 初始化检测通过, 启动rpc服务, 和p2p网络
    if (check_init){
        
        App->applog->info("Runing Server");
        
        // 启动rpc服务, 和p2p网络
        
        // 连接节点列表中的节点
        
        // 注册各种信号
        
    }
    
    // TEST
    if (is_prod_env){
        App->applog->debug("[gmchain] hello ci6~ current env -> production");
    } else {
        App->applog->debug("[gmchain] hello ci6~ current env -> development");
    }
    testMain();
    

    
    secp256k1_context* ctx_both = get_static_context();
    
    printf("secp256k1_context address -> %p\n",ctx_both);
    
    appClear();
    return EXIT_SUCCESS;
}

