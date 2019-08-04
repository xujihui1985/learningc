#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>


static pthread_once_t once = PTHREAD_ONCE_INIT;
static pthread_key_t strerrorKey;

#define MAX_ERROR_LEN 256

static void 
destructor(void *buf)
{
    free(buf);
}

static void    // one time key creation
createKey(void)
{
    int s;

    s = pthread_key_create(&strerrorKey, destructor);
    if (s != 0) 
    {
        perror("pthread key create");
        return;
    }
}

char* strerror(int err)
{
    int s;
    char *buf;

    s = pthread_once(&once, createKey);

    if (s != 0)
    {
        exit(EXIT_FAILURE);
    }

    buf = pthread_getspecific(strerrorKey);

    if (buf == NULL)
    {
        buf = malloc(MAX_ERROR_LEN);
        if (buf == NULL)
        {
            exit(EXIT_FAILURE);
        }

        s = pthread_setspecific(strerrorKey, buf);
        if(s != 0)
        {
            exit(EXIT_FAILURE);
        }
    }

    if (err < 0 || err >= _sys_nerr || _sys_errlist[err] == NULL)
    {
        snprintf(buf, MAX_ERROR_LEN, "Unknown error %d", err);
    } 
    else 
    {
        strncpy(buf, _sys_errlist[err], MAX_ERROR_LEN - 1);
        buf[MAX_ERROR_LEN - 1] = '\0';
    }

    return buf;
}
