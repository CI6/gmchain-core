//
//  gmc_json.c
//  gmchain-core
//
//  Created by AnonymityMaster on 2019/12/18.
//  Copyright © 2019 ci6. All rights reserved.
//

#include "gmc_hash.h"
#include <string.h>

StringKeyValuePair512* _GMCFindStringKeyPair512(StringHash512* self, const char* key){
    StringKeyValuePair512* ptrData = self->data;
    size_t index = 0;
    char* tmp_key;
    for( ; index < GMCHASH_MAX_LENGTH; index++){
        tmp_key = ptrData[index].key;
        if (strcmp(tmp_key,"") == 0){
            break;
        }
        if (strcmp(tmp_key,key) == 0){
            break;
        }
    }
    return &ptrData[index];
};

const char* GMCHashGetString(StringHash512* self, const char* key){
    return 0;
};

const uint32_t GMCHashGetNumber(NumberHash512* self, const char* key){
    return 0;
};

const uint64_t GMCHashGetLongNumber(LongNumberHash512* self, const char* key){
    return 0;
};

void GMCHashSetString512(StringHash512* self, char* key, char* value){
    StringKeyValuePair512* ptrData = _GMCFindStringKeyPair512(self, key);
    if (ptrData){
        memcpy(ptrData->key,key,strlen(key));
        memcpy(ptrData->value,value,strlen(value));
    }
    return;
};

void GMCHashSetNumber512(NumberHash512* self, char* key, uint32_t value){

};

void GMCHashSetLongNumber512(LongNumberHash512* self, char* key, uint64_t value){

};

StringHash512* GMCStringHash512Create(){
    static StringHash512 obj = {
        .data = {}
    };
    return &obj;
}

NumberHash512* GMCNumberHash512Create(){
    static NumberHash512 obj = {
        .data = {}
    };
    return &obj;
}

LongNumberHash512* GMCLongNumberHash512Create(){
    static LongNumberHash512 obj = {
        .data = {}
    };
    return &obj;
}
