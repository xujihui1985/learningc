#include <sys/shm.h>
#include <sys/ipc.h>
#include <stdio.h>
#include <string.h>
#include <stdint.h>

int main() {

    key_t key = ftok("./shmfile", 'a');

    if (key == -1) {
        printf("failed to generate key\n");
        return -1;
    }

    printf("genereated key %d\n", key);

    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);

    uint8_t *str = (uint8_t *) shmat(shmid, NULL, 0);


    memcpy(str, "aaaa", 2);

    shmdt(str);

    return 0;
    
}
