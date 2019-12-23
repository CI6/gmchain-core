//
//  utils.h
//  gmchain-core
//
//  Created by AnonymityMaster on 2019/12/20.
//  Copyright © 2019 ci6. All rights reserved.
//

#ifndef utils_h
#define utils_h

#include <stdio.h>

typedef struct {
    int (*stringToInt)(char*);
    char* (*nowTime)(char*);
} _Utils;

static int _stringToInt(char*);
static char* _nowTime(char*);

void LoadUtilsModule(void);

#endif /* utils_h */
