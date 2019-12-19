//
//  command_line_parser.c
//  gmchain-core
//
//  Created by AnonymityMaster on 2019/12/18.
//  Copyright © 2019 ci6. All rights reserved.
//

#include "command_line_parser.h"

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

int _startCommandLineParser(int argc, const char** argv){
    for (argc--; argc >= 0; argc--) {
        if (strcmp(*argv,"--help") == 0){
            _printHelp();
            break;
        }
        if (strcmp(*argv,"-v") == 0){
            printf("[gmc chain] v0.1.0-debug \n");
            break;
        }
        argv++;
    }
    return 0;
}

CommandLineParser* registerCommandLineMethods(CommandLineParser* obj){
    obj->printHelp = _printHelp;
    obj->startCommandLineParser = _startCommandLineParser;
    return obj;
}
