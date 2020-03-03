//
//  test_unit.c
//  gmchain-core
//
//  Created by AnonymityMaster on 2019/12/26.
//  Copyright © 2019 ci6. All rights reserved.
//

#include "test_unit.h"

#include <assert.h>
#include "../libs/base58/libbase58.h"
#include "../libs/rmd160/rmd160.h"
#include "../libs/sha/sha1.h"
#include "../libs/sha/sha256.h"
#include "../libs/sha/sha512.h"
#include "../libs/aes/aes-cbc.h"
#include "../libs/lzma/LzmaLib.h"

#include "../libs/secp256k1/secp256k1.h"
#include "../libs/secp256k1/secp256k1_recovery.h"
#include "../module/utils.h"
#include "global.h"

const unsigned char TEST_DATA[10] = "hello gmc";
const unsigned char* TEST_DATA2 = "{\"a\":\"123\",\"b\":456,\"c\":\"你好\"}";

void testBase58(){
    char output[14 + 1] = {0, };
    size_t output_size = sizeof(output);
    b58enc(output, &output_size, TEST_DATA, 9);
    
    printf("%s\n",output);
}

void testRmd160(){
    unsigned char output[20] = {0, };
    size_t output_size = (size_t)20;
    Utils->rmd160(TEST_DATA, output_size, output);
    
    unsigned char hex_output[20 * 2 + 1] = {0, };
    Utils->hexEncode(output,20, hex_output);
    hex_output[40] = '\0';
    
    printf("%s\n",output);
}

void testAes(){
    
    uint8_t const* _key = "39lz9ywchlyfd3kanxcsufck18jruidi";
    uint8_t const _iv[AES_CBC_IV_SIZE] = {'3','9','l','z','9','y','w','c','h','l','y','f','d','3','k','a'};
    unsigned char output[32] = {0, };
    uint32_t key_size = strlen(_key);
    int error = AesCbcEncryptWithKey(_key, key_size, _iv, TEST_DATA2, output, (uint32_t)32);
    
    unsigned char output2[33] = {0, };
    AesCbcDecryptWithKey(_key, key_size, _iv, output, output2, (uint32_t)32);
    
    unsigned char* ptrOutput2 = output2;

    printf("%s\n",output);
    printf("%s\n",ptrOutput2);
}

void testLzma(){
    
    // 压缩
    unsigned char* dstBuffer = 0;
    size_t data_size = strlen(TEST_DATA2);
    const size_t compressHeaderSize = LZMA_PROPS_SIZE + sizeof(uint64_t);
    size_t destLen = data_size + 256;
    dstBuffer = malloc(compressHeaderSize + destLen);
    
    assert(dstBuffer);
    size_t nPropSize = LZMA_PROPS_SIZE;
    int result = LzmaCompress(&dstBuffer[compressHeaderSize], &destLen,
                              TEST_DATA2, data_size,
                              &dstBuffer[0], &nPropSize, 1, 1<<24, 3, 0, 2, 32, 2);
    assert(result == SZ_OK);
    printf("%s\n",dstBuffer);
    
    
    // 解压
    uint64_t uncompressed_size = 0;
    memcpy(&uncompressed_size, &dstBuffer[LZMA_PROPS_SIZE], sizeof(uint64_t));
    unsigned char* uncompressed_buffer = malloc(uncompressed_size + 1);
    assert(uncompressed_buffer);

    uncompressed_buffer[uncompressed_size] = 0;
    //  REMARK: 解压函数不太完善，这个 destLen 设置 buffer 的大小可能导致返回 SZ_ERROR_INPUT_EOF 错误，必须设置为 原始数据长度才可以。不能设置为 uncompressed_size + 1 !!
    size_t uncompressed_buffer_size = uncompressed_size;
    size_t compressed_size = strlen(dstBuffer) - LZMA_PROPS_SIZE - sizeof(uint64_t);
    
    result = LzmaUncompress(uncompressed_buffer, &uncompressed_buffer_size,
                              &dstBuffer[LZMA_PROPS_SIZE + sizeof(uint64_t)], &compressed_size,
                              dstBuffer, LZMA_PROPS_SIZE);
    
//    assert(result == SZ_OK);

    
    
    
}

void testHex(){
    const size_t size_wallet_json = 13;
    unsigned char hex_output[27] = {0, };
    Utils->hexEncode(TEST_DATA, size_wallet_json, hex_output);
    printf("%s\n",hex_output);
    
    unsigned char decode_output[14] = {0, };
    Utils->hexDecode(hex_output, sizeof(hex_output), decode_output);
    printf("%s\n",decode_output);
    decode_output[size_wallet_json] = '\0';
    
    int rst = strcmp(TEST_DATA, decode_output);
    
    assert(rst == 0);
}

void testSha1(){
    unsigned char output[20 + 1] = {0, };
    Utils->sha1(TEST_DATA, 9, output);
    
    printf("%s\n",output);
    
    unsigned char hex_output[20 * 2 + 1] = {0, };
    Utils->hexEncode(output,20, hex_output);
    hex_output[40] = '\0';
    
    printf("%s\n",hex_output);
    
    int rst = strcmp(hex_output, "41517bcafe6e34f3e3c3f4d1d38024004f5eda99");
    assert(rst == 0);
    
}

void testSha256(){
    unsigned char output[32 + 1] = {0, };
    Utils->sha256(TEST_DATA, 9, output);
    
    printf("%s\n",output);
    
    unsigned char hex_output[32 * 2 + 1] = {0, };
    Utils->hexEncode(output,32, hex_output);
    hex_output[64] = '\0';
    
    printf("%s\n",hex_output);
    
    int rst = strcmp(hex_output, "940fbf7bd7c812d81da70baf9ffe26181ada52e4f306c1aedeed268784b2ae24");
    assert(rst == 0);
}

void testSha512(){
    unsigned char output[64 + 1] = {0, };
    Utils->sha512(TEST_DATA, 9, output);
    printf("%s\n",output);
    
    unsigned char hex_output[64 * 2 + 1] = {0, };
    Utils->hexEncode(output,64, hex_output);
    hex_output[128] = '\0';
    
    printf("%s\n",hex_output);
    
    int rst = strcmp(hex_output, "402a487a88346d39b6a743226ac0501c4fb4665553b48e5005e973289c7ae207fa2de34b0822a374cbcc7fd4009a3303bbe238799c6f5c68f8b15ba67f32d349");
    assert(rst == 0);
}

void testSecp256k1(){
    // step 1. 生成 Context
    secp256k1_context* ctx_spec256k1 = secp256k1_context_create(SECP256K1_CONTEXT_VERIFY | SECP256K1_CONTEXT_SIGN);
    
    // step 2. 生成32位私钥.
    unsigned char private_key[32+1] = {0, };
    Utils->sha256(TEST_DATA, strlen(TEST_DATA), private_key);
    
    // step3. 生成公钥
    secp256k1_pubkey public_key = {0, };
    secp256k1_ec_pubkey_create(ctx_spec256k1, &public_key, private_key);
    
    unsigned char hex_output_private_key[32 * 2 + 1] = {0, };
    unsigned char hex_output_public_key[64 * 2 + 1] = {0, };
    Utils->hexEncode(private_key,32, hex_output_private_key);
    Utils->hexEncode(public_key.data,64, hex_output_public_key);
    
    printf("%s\n",hex_output_private_key);
    printf("%s\n",hex_output_public_key);
}


/**
 *  (public) 签名
 */
void testSign()
{
    
    const unsigned char* sign_buffer = TEST_DATA;
    
    //  获取上下文
    secp256k1_context* ctx_both = secp256k1_context_create(SECP256K1_CONTEXT_VERIFY | SECP256K1_CONTEXT_SIGN);
    
    const size_t sign_buffer_size = strlen(sign_buffer);
    
    unsigned char sign_private_key32[32+1] = {0, };
    Utils->sha256(TEST_DATA, strlen(TEST_DATA), sign_private_key32);
    
    unsigned char output_signature65[65] = {0,};
    
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
            return;
        }
        ++nonce;
        
        //  转换为普通签名
        (void)secp256k1_ecdsa_recoverable_signature_convert(ctx_both, &normal_sig, &sig);
        
        //  转换为der格式
        output_der_len = sizeof(output_der);
        ret = secp256k1_ecdsa_signature_serialize_der(ctx_both, output_der, &output_der_len, &normal_sig);
        if (!ret){
            return;
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
    

    
    printf("output_signature65 -> \n");
    printf("%s\n",output_signature65);
    
    unsigned char hex_output[64 * 2 + 1] = {0, };
    Utils->hexEncode(output_signature65,64, hex_output);
    hex_output[128] = '\0';
    printf("output_signature65 hex -> \n");
    printf("%s\n",hex_output);
    
    return;
}



void beforeTest(){
    
}

void afterTest(){
    
}

void testCore(){
    testHex();
    testSha1();
    testSha256();
    testSha512();
    testBase58();
    testRmd160();
    testLzma();
    testAes();
    testSecp256k1();
    testSign();
    return;
}

void testMain(){
    beforeTest();
    testCore();
    afterTest();
}


