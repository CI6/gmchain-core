//
//  runtime_env.h
//  gmchain-core
//
//  Created by AnonymityMaster on 2019/12/18.
//  Copyright © 2019 ci6. All rights reserved.
//

#ifndef runtime_env_h
#define runtime_env_h

#include <stdio.h>
#include <stdbool.h>

typedef struct {
    char root[256];
    bool(*isProduction)(void);
    bool(*isTest)(void);
    bool(*isDevelopment)(void);
} RuntimeEnv;

inline bool _isProuction(void);
inline bool _isTest(void);
inline bool _isDevelopment(void);

void loadRuntimeEnvModule(RuntimeEnv*);

#endif /* runtime_env_h */
