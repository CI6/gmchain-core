//
//  command_line_parser.h
//  gmchain-core
//
//  Created by AnonymityMaster on 2019/12/18.
//  Copyright © 2019 ci6. All rights reserved.
//

#ifndef command_line_parser_h
#define command_line_parser_h

#include <stdio.h>
#include "basetypes.h"

typedef struct {
    const char dbpath[240];
    const char env[16];
    uint16_t p2p_listen_port;
    uint16_t rpc_listen_port;
    const char auth_id[640];
    bool start;
    bool test;
    bool daemonize;
    
} CommandLineSetting;

void _printHelp(void);
void startCommandLineParser(int argc, const char ** argv, CommandLineSetting*);

typedef struct {
    CommandLineSetting* setting;
} CommandLineParser;

CommandLineParser* registerCommandLineInstance(CommandLineParser*);

#endif /* command_line_parser_h */
