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
#include "../libs/rmd160/rmd160.h"


typedef struct {
    int (*stringToInt)(char*);
    void (*nowTime)(char*);
    bool (*equals)(const char*, const char*);
    
    void (*hexEncode)(const unsigned char*, const size_t, unsigned char[]);
    void (*hexDecode)(const unsigned char*, const size_t, unsigned char[]);
    void (*rmd160)(const unsigned char*, const size_t, unsigned char[]);
    void (*rmd160hex)(const byte*, const dword, byte[]);
    void (*sha1)(const unsigned char*, const size_t, unsigned char[]);
    void (*sha256)(const unsigned char*, const size_t, unsigned char[]);
    void (*sha512)(const unsigned char*, const size_t, unsigned char[]);
    void (*base58Encode)(const unsigned char*, const size_t, unsigned char[], size_t*);
    unsigned char* (*base58Decode)(const unsigned char*, const size_t, unsigned char[], size_t*);
} _Utils;

static int _stringToInt(char*);
static void _nowTime(char*);
static bool _equals(const char* str_a,const char* str_b);

void LoadUtilsModule(void);

#endif /* utils_h */
