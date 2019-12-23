//
//  command_line_parser.c
//  gmchain-core
//
//  Created by AnonymityMaster on 2019/12/18.
//  Copyright © 2019 ci6. All rights reserved.
//
#include <stdlib.h>
#include <stdbool.h>
#include "command_line_parser.h"
#include "basetypes.h"
#include "module/utils.h"
#include "global.h"


void _printHelp()
{
    static const char *const help_msg[] = {
        "switches:",
        "-v                           print the version number (打印版本号)",
        "--version                    print the version number (打印版本号)",
        "--data-path=<path>           save block data to dir (区块保存路径)",
        "--p2p-listen-port=<port>     set the listen port for other hyper nodes connect (P2P端口用于其他节点连接)",
        "--rpc-listen-port=<port>     set the listen port for client connect (RPC端口用于客户端连接)",
        "--auth-id=<id1,id2,id3>      bind the users of run this server (用于授权运行此服务的用户列表,可指定多个)",
        "--daemonize                  run at the background (进程后台daemonize化运行)",
        "start                        start the game master chain (启动GM链)",
        "--env=<env>                  starting env params, eg: development,test,production"
        "test                         run the unit test (运行单元测试)",
        "--copyright                  print the copyright (打印 copyright)",
        NULL
    };
    const char *const *ptr_help_msg = help_msg;
    printf("Welcome to use the game master chain\n");
    while(*ptr_help_msg){
        printf("  %s\n", *ptr_help_msg++);
    }
}

// 命令行解析
void startCommandLineParser(int argc, const char** argv, CommandLineSetting* setting){
    
    // 主循环索引序号
    int index = 0;
    
    // 单个参数长度
    size_t len = 0;
    
    // 单个参数缓冲区 len = (key + value)
    static char buf[690];
    
    // 用户命令行参数 = 分割 key,value
    char key[48];
    char value[640];
    
    // 单个[未处理]参数字符串 此处可能包含 = 的参数
    char ptr_argv[690];
    
    // 标记已读取关键分隔符 '='
    bool is_load_args;
    
    // 主循环遍历参数
    for (argc--; argc >= 0; argc--) {
        
        // REMARK: 每次循环清空共享buf
        memset(ptr_argv,'\0',690);
        memset(key,'\0',48);
        memset(value,'\0',640);
        
        strlcpy(ptr_argv, *argv, strlen(*argv)+1);
        len = strlen(ptr_argv);
        
        // 处理无分隔符参数 并 continue or break
        if (strcmp(*argv,"--help") == CMP_SUCCESS ){
            _printHelp();
            exit(EXIT_SUCCESS);
            break;
        }
        if (strcmp(*argv,"-v") == 0 || strcmp(*argv,"--version") == CMP_SUCCESS){
            printf("[gmc chain] v0.1.0-debug \n");
            exit(EXIT_SUCCESS);
            break;
        }
        if (strcmp(*argv,"--daemonize") == 0){
            setting->daemonize = true;
            argv++;
            index++;
            continue;
        }
        if (strcmp(*argv,"start") == 0){
            setting->start = true;
            argv++;
            index++;
            continue;
        }
        if (strcmp(*argv,"test") == 0){
            setting->test = true;
            argv++;
            index++;
            continue;
        }
        if (strcmp(*argv,"--copyright") == 0){
            printf("Copyright Ci6 Team \n");
            exit(EXIT_SUCCESS);
            break;
        }
        
        // 处理 = 分隔符参数 -> 并读取 key=value 参数
        is_load_args = false;
        for (size_t i = 0; i < len; i++){
            if (ptr_argv[i] == '='){
                is_load_args = true;
                continue;
            }
            if (is_load_args){
                value[strlen(value)] = ptr_argv[i];
            } else {
                // 防止 buf 溢出
                if (i >= 47){
                    break;
                }
                key[strlen(key)] = ptr_argv[i];
            }
        }

        // 生成配置
        if (is_load_args){
            if (strcmp(key,"--data-path") == CMP_SUCCESS){
                strlcpy(setting->dbpath, value, strlen(value)+1);
                printf("gaga");
            }
            if (strcmp(key,"--p2p-listen-port") == CMP_SUCCESS){
                setting->p2p_listen_port = Utils->stringToInt(value);
            }
            if (strcmp(key,"--rpc-listen-port") == CMP_SUCCESS){
                setting->rpc_listen_port = Utils->stringToInt(value);
            }
            if (strcmp(key,"--auth-id") == CMP_SUCCESS){
                strlcpy(setting->auth_id,value,strlen(value)+1);
            }
            if (strcmp(key,"--env") == CMP_SUCCESS){
                strlcpy(setting->env,value,strlen(value)+1);
            }
        }
        argv++;
        index++;
    }
    return;
}

// 初始化成员
CommandLineParser* LoadCommandLineParserModule(CommandLineParser* obj){
    obj->setting = (CommandLineSetting*)malloc(sizeof(CommandLineSetting));
    memset(obj->setting->auth_id,'\0',640);
    memset(obj->setting->env,'\0',16);
    memset(obj->setting->dbpath,'\0',240);
    obj->setting->p2p_listen_port = 0;
    obj->setting->rpc_listen_port = 0;
    obj->setting->start = false;
    obj->setting->test = false;
    obj->setting->daemonize = false;
    return obj;
}
