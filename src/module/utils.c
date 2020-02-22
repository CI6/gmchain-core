//
//  utils.c
//  gmchain-core
//
//  Created by AnonymityMaster on 2019/12/20.
//  Copyright © 2019 ci6. All rights reserved.
//

#include "utils.h"
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

_Utils* Utils;

int _stringToInt(char *str) {
    // 最终输出
    int n = 0;
    
    // 是否负数
    bool negative = false;
    
    // 首字母是 - 表示负数
    if(*str == '-') {
        negative = true;
        str++;
    }
    
    // 循环位数 每次 * 10
    while(*str >= '0' && *str <= '9') {
        n = n * 10 + (*str - '0');
        str++;
    }
    
    // 负数将结果反转
    if(negative == 1){
        n = -n;
    }
    return n;
}

void _nowTime(char* buf){
    time_t _time = time(NULL);
    struct tm *st_time = localtime(&_time);
    strftime(buf, 32, "%Y-%m-%d %H:%M:%S", st_time);
    return;
}

bool _equals(const char* str_a,const char* str_b){
  if(strlen(str_a) != strlen(str_b)){
    return false;
  }
  for(int i=0; i < strlen((char*)str_a); i++){
    if( str_a[i] != str_b[i]){
      return false;
    }
  }
  return true;
}

void LoadUtilsModule(){
    Utils = (_Utils*)malloc(sizeof(_Utils));
    Utils->stringToInt = _stringToInt;
    Utils->nowTime = _nowTime;
    Utils->equals = _equals;
}

