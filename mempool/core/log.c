//
// Created by Sean on 2019-07-28.
//

#include <stdarg.h>
#include <string.h>
#include <stdint.h>
#include <pthread.h>
#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <unistd.h>

#include "log.h"

pthread_t get_pthread_id() {
    return pthread_self();
}

void tprintf(const char *const flags, int dflag, const char *const format, ...) {
    va_list arg_pointer;
    char buffer[MAX_LOGLINE_SIZE + 10] = {0};
    int len;
    struct tm Tm, *ptm;
    struct timeval timeSecs;
    time_t cur_time;

    gettimeofday(&timeSecs, NULL);
    cur_time = timeSecs.tv_sec;
    ptm = localtime_r(&cur_time, &Tm);
    len = sprintf(buffer, "%02d/%02d %02d:%02d:%02d.%06d (0x%ld) ", ptm->tm_mon + 1, ptm->tm_mday, ptm->tm_hour,
                  ptm->tm_min, ptm->tm_sec, (int) timeSecs.tv_usec, get_pthread_id());

    len += sprintf(buffer + len, "[%s] ", flags);
    va_start(arg_pointer, format);
    len += vsnprintf(buffer + len, 64 * 1024, format, arg_pointer);
    va_end(arg_pointer);

    if (len > 64 * 1024) {
        len = 64 * 1024;
    }

    buffer[len++] = '\n';
    buffer[len] = '\0';

    if ((dflag & DEBUG_FILE)) {
        //TODO: write to file
    }
    if (dflag & DEBUG_SCREEN) {
        write(1, buffer, (size_t) len);
    }
}