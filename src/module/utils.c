//
//  utils.c
//  gmchain-core
//
//  Created by AnonymityMaster on 2019/12/20.
//  Copyright © 2019 ci6. All rights reserved.
//

#include "utils.h"
#include <stdbool.h>

int stringToInt(char *str)
{
    // 最终输出
    int n = 0;
    
    // 是否负数
    bool negative = false;
    
    // 首字母是 - 表示负数
    if(*str == '-')
    {
        negative = true;
        str++;
    }
    
    // 循环位数 每次 * 10
    while(*str >= '0' && *str <= '9')
    {
        n = n * 10 + (*str - '0');
        str++;
    }
    
    // 负数将结果反转
    if(negative == 1)
    {
        n = -n;
    }
    return n;
}
