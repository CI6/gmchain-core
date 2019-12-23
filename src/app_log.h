//
//  app_log.h
//  gmchain-core
//
//  Created by AnonymityMaster on 2019/12/18.
//  Copyright © 2019 ci6. All rights reserved.
//

#ifndef app_log_h
#define app_log_h

#include <stdio.h>
#include <stdarg.h>

#define COLOR_TRACE "\x1b[94m"
#define COLOR_DEBUG "\x1b[36m"
#define COLOR_INFO "\x1b[32m"
#define COLOR_WARN "\x1b[33m"
#define COLOR_ERROR "\x1b[31m"
#define COLOR_FATAL "\x1b[35m"

#define LOG_MAX_LEVEL 6
#define LOG_FMT_PARAMS (const char*, ...)

typedef void(*TYPE_LOG_FN)(const char* fmt, ...);

typedef struct {
    FILE *fp;
    TYPE_LOG_FN trace;
    TYPE_LOG_FN debug;
    TYPE_LOG_FN info;
    TYPE_LOG_FN warn;
    TYPE_LOG_FN error;
    TYPE_LOG_FN fatal;
} AppLog;

enum ENUM_LOG_LEVEL { LOG_TRACE, LOG_DEBUG, LOG_INFO, LOG_WARN, LOG_ERROR, LOG_FATAL };

//#define log_trace(...) writeLog(LOG_TRACE, __VA_ARGS__)
//#define log_debug(...) writeLog(LOG_DEBUG, __VA_ARGS__)
//#define log_info(...)  writeLog(LOG_INFO,  __VA_ARGS__)
//#define log_warn(...)  writeLog(LOG_WARN,  __VA_ARGS__)
//#define log_error(...) writeLog(LOG_ERROR, __VA_ARGS__)
//#define log_fatal(...) writeLog(LOG_FATAL, __VA_ARGS__)

static void _trace LOG_FMT_PARAMS;
static void _debug LOG_FMT_PARAMS;
static void _info LOG_FMT_PARAMS;
static void _warn LOG_FMT_PARAMS;
static void _error LOG_FMT_PARAMS;
static void _fatal LOG_FMT_PARAMS;

static void _writeLog(enum ENUM_LOG_LEVEL, const char*, ...);

void loadAppLogModule(AppLog*);

#endif /* app_log_h */
