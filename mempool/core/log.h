//
// Created by Sean on 2019-07-28.
//

#ifndef MEMPOOL_LOG_H
#define MEMPOOL_LOG_H

#define MAX_LOGLINE_SIZE 1000
#define DEBUG_FILE 0x80
#define DEBUG_SCREEN 0x40

void tprintf(const char *const flags, int dflag, const char *const format, ...);

#endif //MEMPOOL_LOG_H
