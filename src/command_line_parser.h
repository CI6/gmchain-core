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

void _printHelp(void);
int _startCommandLineParser(int argc, const char ** argv);


typedef struct {
    void (*printHelp)(void);
    int (*startCommandLineParser)(int, const char**);
} CommandLineParser;

CommandLineParser* registerCommandLineMethods(CommandLineParser*);

#endif /* command_line_parser_h */
