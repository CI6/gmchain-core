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
#include <stdbool.h>

typedef struct {
    int (*stringToInt)(char*);
    void (*nowTime)(char*);
    bool (*equals)(const char*, const char*);
} _Utils;

static int _stringToInt(char*);
static void _nowTime(char*);
static bool _equals(const char* str_a,const char* str_b);

void LoadUtilsModule(void);

#endif /* utils_h */
