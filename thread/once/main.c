#include <pthread.h>
#include <thread.h>
#include <stdio.h>

#define N 1000

pthread_once_t once_var = PTHREAD_ONCE_INIT;
int glob;

void 
init(void)
{
    printf("should called only once\n");
}

static void do_once() 
{
    glob++;
    pthread_once(&once_var, init);
}


static void *
thread_func(void *arg)
{
    do_once();
    return NULL;
}

int main() 
{

    pthread_t *threads[N];
    pthread_t t;
    for(int i = 0; i < N; i++) 
    {
        pthread_create(&t, NULL,thread_func, NULL);
        threads[i] = &t;
    }

    for(int i = 0; i < N; i++)
    {
        pthread_join(*threads[i], NULL);
    }
    printf("done %d\n", glob);

}
