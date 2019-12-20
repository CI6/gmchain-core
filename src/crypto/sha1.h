#ifndef SHA1_H
#define SHA1_H

//
//  runtime_env.c
//  gmchain-core
//
//  Created by Tom on 2019/12/18.
//  Copyright © 2019 ci6. All rights reserved.
//

#include "stdint.h"

typedef struct
{
    uint32_t state[5];
    uint32_t count[2];
    unsigned char buffer[64];
} SHA1_CTX;

void Sha1Transform(
    uint32_t state[5],
    const unsigned char buffer[64]
    );

void Sha1Init(
    SHA1_CTX * context
    );

void Sha1Update(
    SHA1_CTX * context,
    const unsigned char *data,
    uint32_t len
    );

void Sha1Final(
    unsigned char digest[20],
    SHA1_CTX * context
    );

void Sha1(
    char *hash_out,
    const char *str,
    int len
    );

char* Sha1Hex(
    char *hex_out,
    const char *str 
    );
#endif /* SHA1_H */