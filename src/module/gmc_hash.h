//
//  gmc_json.h
//  gmchain-core
//
//  Created by AnonymityMaster on 2019/12/18.
//  Copyright © 2019 ci6. All rights reserved.
//

#ifndef gmc_hash_h
#define gmc_hash_h

#include <stdio.h>
#include "../basetypes.h"

#define GMCHASH_MAX_LENGTH 1024

typedef struct {
    char key[32];
    char value[512];
} StringKeyValuePair512;

typedef struct {
    char* key[32];
    char* uint32_t[512];
} NumberKeyValuePair512;

typedef struct {
    char* key[32];
    char* uint64_t[512];
} LongNumberKeyValuePair512;

typedef struct _StringHash512 {
    StringKeyValuePair512 data[GMCHASH_MAX_LENGTH];
} StringHash512;

typedef struct _NumberHash512 {
    NumberKeyValuePair512* data[GMCHASH_MAX_LENGTH];
} NumberHash512;

typedef struct _LongNumberHash512 {
    NumberKeyValuePair512* data[GMCHASH_MAX_LENGTH];
} LongNumberHash512;

const char* GMCHashGetString(StringHash512*, const char*);
const uint32_t GMCHashGetNumber(NumberHash512*, const char*);
const uint64_t GMCHashGetLongNumber(LongNumberHash512*, const char*);

void GMCHashSetString512(StringHash512* self, char*, char*);
void GMCHashSetNumber512(NumberHash512* self, char*, uint32_t);
void GMCHashSetLongNumber512(LongNumberHash512* self, char*, uint64_t);

StringHash512* GMCStringHash512Create(void);
NumberHash512* GMCNumberHash512Create(void);
LongNumberHash512* GMCLongNumberHash512Create(void);

StringKeyValuePair512* _GMCFindStringKeyPair512(StringHash512* self,const char*);
NumberKeyValuePair512* _GMCFindNumberKeyPair512(NumberHash512* self,const char*);
LongNumberKeyValuePair512* _GMCFindLongNumberKeyPair512(LongNumberHash512* self,const char*);

#endif /* gmc_hash_h */
