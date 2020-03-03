//
//  crypto_manage.c
//  gmchain-core
//
//  Created by AnonymityMaster on 2019/12/18.
//  Copyright © 2019 ci6. All rights reserved.
//

#include "crypto_manage.h"
#include <stdbool.h>

#include "libs/secp256k1/secp256k1.h"
#include "libs/secp256k1/secp256k1_recovery.h"
#include "module/utils.h"
#include "global.h"

void createKeyPair(const unsigned char* seed, const size_t seed_size, secp256k1_pubkey public_key, unsigned char buf_private_key[32] ){
    
    // step 1. 生成 Context
    secp256k1_context* ctx_spec256k1 = createSecp256k1Context();
    
    // step 2. 生成32位私钥.
    Utils->sha256(seed, seed_size, buf_private_key);
    buf_private_key[32] = '\0';
    
    // step3. 生成64位公钥
    secp256k1_ec_pubkey_create(ctx_spec256k1, &public_key, buf_private_key);
        
}

bool verify
(
    const unsigned char* public_key,
    const unsigned char* verify_data,
    const unsigned char* sign_value
){
    return false;
}


bool sign(const unsigned char* sign_buffer, const size_t sign_buffer_size,
                       const unsigned char sign_private_key32[], unsigned char output_signature65[])
{
    //  获取上下文
    secp256k1_context* ctx_both = createSecp256k1Context();
    
    //  计算待签名buffer的sha256签名
    unsigned char digest32[32] = {0, };
    Utils->sha256(sign_buffer, sign_buffer_size, digest32);
    
    secp256k1_ecdsa_recoverable_signature sig = {0, };
    secp256k1_ecdsa_signature normal_sig = {0,};
    unsigned char output_der[128] = {0, };  //  REMARK：这个好像基本都只有70字节，网上有的参数是72。
    
    size_t output_der_len;
    int nonce = 0;
    int ret;
    
    //  循环计算签名，直到找到合适的 canonical 签名。
    while (1) {
        //  执行签名核心
        ret = secp256k1_ecdsa_sign_recoverable(ctx_both, &sig, digest32, sign_private_key32, NULL, &nonce);
        if (!ret){
            return false;
        }
        ++nonce;
        
        //  转换为普通签名
        (void)secp256k1_ecdsa_recoverable_signature_convert(ctx_both, &normal_sig, &sig);
        
        //  转换为der格式
        output_der_len = sizeof(output_der);
        ret = secp256k1_ecdsa_signature_serialize_der(ctx_both, output_der, &output_der_len, &normal_sig);
        if (!ret){
            return false;
        }
        
        //  判断是否是 canonical 签名
        unsigned char lenR = output_der[3];
        unsigned char lenS = output_der[5 + lenR];
        if (lenR == 32 && lenS == 32)
        {
            int recId = 0;
            (void)secp256k1_ecdsa_recoverable_signature_serialize_compact(ctx_both, &output_signature65[1], &recId, &sig);
            recId += 4;     //  compressed
            recId += 27;    //  compact  //  24 or 27 :( forcing odd-y 2nd key candidate)
            
            //  存储在第一个字节。
            output_signature65[0] = (unsigned char)recId;
            break;
        }
    }
    
    return true;
}


void loadCryptoManageModule(CryptoManage* ptr){
    ptr->createKeyPair = createKeyPair;
    ptr->sign = sign;
    ptr->verify = verify;
}


// [private] secp256k1 上下文
secp256k1_context* createSecp256k1Context(void){
    static secp256k1_context* ctx_both = 0;
    if (!ctx_both){
        ctx_both  = secp256k1_context_create(SECP256K1_CONTEXT_VERIFY | SECP256K1_CONTEXT_SIGN);
    }
    return ctx_both;
}
