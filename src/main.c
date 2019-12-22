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

int main(int argc, const char** argv) {
    
    initialize(argc, argv);
    App->parserCommandLine();
    
    bool result = App->env->isProduction();
    

//    bool result;
//    result = checkReady();
//
//    if (!result){
//        printf("initialize failed!\n");
//        appClear();
//        return EXIT_FAILURE;
//    }
//    start();
    
    printf("[gmchain] hello ci6~\n");
    appClear();
    return EXIT_SUCCESS;
}
