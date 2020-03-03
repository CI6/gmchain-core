//
//  crypto_manage.h
//  gmchain-core
//
//  Created by AnonymityMaster on 2019/12/18.
//  Copyright © 2019 ci6. All rights reserved.
//

#ifndef crypto_manage_h
#define crypto_manage_h

#include <stdio.h>
#include <stdbool.h>
#include "secp256k1.h"
#include "secp256k1_recovery.h"

typedef struct {
    void (*createKeyPair)(const unsigned char*, const size_t, unsigned char*, unsigned char*);
    bool (*verify)(const unsigned char*,const unsigned char*,const unsigned char*);
    bool (*sign)(const unsigned char*, const size_t,
    const unsigned char[], unsigned char[]);
} CryptoManage;

void loadCryptoManageModule(CryptoManage*);

secp256k1_context* createSecp256k1Context(void);
bool sign(const unsigned char*, const size_t,
          const unsigned char[], unsigned char[]);

#endif /* crypto_manage_h */


