#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdatomic.h>

static volatile int glob;

struct resource {
    int loop;
    pthread_mutex_t mtx;
};

static void *
thread_func(void *arg)
{
    struct resource *r = (struct resource *) arg;
    int loops = r->loop;

    int loc;

    for (int j = 0; j < loops; j++)
    {
        pthread_mutex_lock(&r->mtx);
        loc = glob;
        loc ++;
        glob = loc;
        pthread_mutex_unlock(&r->mtx);
    }
    return NULL;
}

int main(int argc, char *argv[])
{
    pthread_t t1, t2;
    int rc;

    struct resource r = {
        .loop=10000000
    };
    pthread_mutex_init(&r.mtx, NULL);

    rc = pthread_create(&t1, NULL, thread_func, &r);

    if (rc != 0)
    {
        printf("failed to create pthread\n");
        exit(EXIT_FAILURE);
    }

    rc = pthread_create(&t2, NULL, thread_func, &r);
    if (rc!= 0)
    {
        printf("failed to create pthread\n");
        exit(EXIT_FAILURE);
    }

    rc = pthread_join(t1, NULL);

    if (rc != 0)
    {
        printf("failed to join pthread t1\n");
        exit(EXIT_FAILURE);
    }

    rc = pthread_join(t2, NULL);

    if (rc!= 0)
    {
        printf("failed to join pthread t2\n");
        exit(EXIT_FAILURE);
    }

    printf("glob = %d\n", glob);
    exit(EXIT_SUCCESS);


}
