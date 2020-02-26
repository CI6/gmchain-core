//
//  crypto_manage.c
//  gmchain-core
//
//  Created by AnonymityMaster on 2019/12/18.
//  Copyright © 2019 ci6. All rights reserved.
//

#include "crypto_manage.h"
#include <stdbool.h>

void createKeyPair(unsigned char* buf_public_key, unsigned char* buf_private_key ){
    
}

bool verify
(
    const unsigned char* public_key,
    const unsigned char* verify_data,
    const unsigned char* sign_value
){
    return false;
}

void sign(
    const unsigned char* private_key,
    const unsigned char* sign_data,
    const unsigned char* buf_sign_value
){

}

void loadCryptoManageModule(CryptoManage* ptr){
    ptr->createKeyPair = createKeyPair;
    ptr->sign = sign;
    ptr->verify = verify;
}
