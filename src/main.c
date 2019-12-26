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

    appClear();
    return EXIT_SUCCESS;
}

