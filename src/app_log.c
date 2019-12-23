//
//  app_log.c
//  gmchain-core
//
//  Created by AnonymityMaster on 2019/12/18.
//  Copyright © 2019 ci6. All rights reserved.
//

#include "app_log.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <time.h>
#include "global.h"
#include "key_const.h"

void _trace(const char* fmt, ...){
    _writeLog(LOG_TRACE, fmt);
}
void _debug(const char* fmt, ...){
    
    _writeLog(LOG_DEBUG, fmt);
}
void _info(const char* fmt, ...){
    _writeLog(LOG_INFO, fmt);
}
void _warn(const char* fmt, ...){
    _writeLog(LOG_WARN, fmt);
}
void _error(const char* fmt, ...){
    _writeLog(LOG_ERROR, fmt);
}
void _fatal(const char* fmt, ...){
    _writeLog(LOG_FATAL, fmt);
}

//
// 输出日志核心
//
// - 格式:  [日期时间] 日志等级 - 内容
// - Todo: 多线程操作 & 线程安全
//
void _writeLog(enum ENUM_LOG_LEVEL level, const char* fmt, ...) {
    if (level > LOG_MAX_LEVEL) {
        return;
    }

    // 获取格式化时间
    char buf[32];
    Utils->nowTime(buf);

    // 获取等级和颜色
    const char* p_level = "";
    const char* p_color = "";
    switch(level){
        case LOG_TRACE:
            p_level = KCTRACE; p_color = COLOR_TRACE;
            break;
        case LOG_DEBUG:
            p_level = KCDEBUG; p_color = COLOR_DEBUG;
            break;
        case LOG_INFO:
            p_level = KCINFO;  p_color = COLOR_INFO;
            break;
        case LOG_WARN:
            p_level = KCWARN;  p_color = COLOR_WARN;
            break;
        case LOG_ERROR:
            p_level = KCERROR; p_color = COLOR_ERROR;
            break;
        case LOG_FATAL:
            p_level = KCFATAL; p_color = COLOR_FATAL;
            break;
    }
    
    // 后台运行输出文件
    if (App->isDaemonize()) {
        FILE* fp = App->applog->fp;
        va_list args;
        fprintf(fp, "[%s] %-5s - ", buf, p_level);
        va_start(args, fmt);
        vfprintf(fp, fmt, args);
        va_end(args);
        fprintf(fp, "\n");
        fflush(fp);
    } else {
        // 前台运行标准输出
        va_list args;
        fprintf(stderr, "[%s] %s%-5s\x1b[0m - ",buf, p_color, p_level);
        va_start(args, fmt);
        vfprintf(stderr, fmt, args);
        va_end(args);
        fprintf(stderr, "\n");
        fflush(stderr);
    }
}


void loadAppLogModule(AppLog* log){
    FILE* fp = fopen("gmchain.log", "ab");
    fseek(fp, 0, SEEK_END);
    
    log->fp = fp;
    log->trace = _trace;
    log->debug = _debug;
    log->info = _info;
    log->warn = _warn;
    log->error = _error;
    log->fatal = _fatal;
}
