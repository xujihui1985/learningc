#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

static pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

static int avail = 0;

static void *
producer_func(void *arg)
{
    int rc, exit_code;
    rc = pthread_mutex_lock(&mtx); // when success return 0
    if (rc != 0) 
    {
        perror("failed to lock");
        exit_code = EXIT_FAILURE;
        goto exit;
    }
    avail++;
    rc = pthread_mutex_unlock(&mtx);
    if (rc != 0) 
    {
        perror("failed to unlock");
        exit_code = EXIT_FAILURE;
        goto exit;
    }

    rc = pthread_cond_signal(&cond); // wake sleeping concumer
    if (rc != 0)
    {
        perror("failed to signal");
        exit_code = EXIT_FAILURE;
        goto exit;
    }
    exit_code = EXIT_SUCCESS;
    goto exit;
exit:
    exit(exit_code);
}

static void *
consumer_func(void *arg)
{
    int rc, ext_code;

    rc = pthread_mutex_lock(&mtx);
    if (rc != 0)
    {
        ext_code = EXIT_FAILURE;
        perror("failed to lock");
        goto exit;
    }

    while(avail == 0)
    {
        rc = pthread_cond_wait(&cond, &mtx);
        if (rc != 0)
        {
            ext_code = EXIT_FAILURE;
            perror("failed to cond wait");
            goto exit;
        }
    }

    while (avail > 0)
    {
        printf("consume available data %d remaind\n", avail);
        avail--;
    }

    rc = pthread_mutex_unlock(&mtx);
    if (rc != 0)
    {
        ext_code = EXIT_FAILURE;
        perror("failed to unlock");
        goto exit;
    }
    ext_code = EXIT_SUCCESS;
    goto exit;
exit:
    exit(ext_code);
}

int 
main(int argc, char** argv)
{
    int rc;
    int exit_code;
    rc = pthread_mutex_lock(&mtx); // when success return 0
    if (rc != 0) 
    {
        perror("failed to lock");
        exit_code = EXIT_FAILURE;
        goto exit;
    }

    avail ++;

exit:
    exit(exit_code);
}
