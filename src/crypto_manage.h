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

typedef struct {
    void (*createKeyPair)(unsigned char*, unsigned char*);
    bool (*verify)(const unsigned char*,const unsigned char*,const unsigned char*);
    void (*sign)(const unsigned char*,const unsigned char*,const unsigned char*);
} CryptoManage;

void loadCryptoManageModule(CryptoManage*);

#endif /* crypto_manage_h */


