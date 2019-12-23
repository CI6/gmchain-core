//
//  main.c
//  gmchain-core
//
//  Created by AnonymityMaster on 2019/12/17.
//  Copyright © 2019 ci6. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "application.h"
#include "basetypes.h"
#include "global.h"

#include "app_log.h"

int main(int argc, const char** argv) {
    
    initialize(argc, argv);
    App->parserCommandLine();
    
    bool result = App->env->isProduction();
    
    // TEST
    if (result){
        App->applog->debug("[gmchain] hello ci6~ current env -> production");
    } else {
        App->applog->debug("[gmchain] hello ci6~ current env -> development");
    }
    
    appClear();
    return EXIT_SUCCESS;
}
