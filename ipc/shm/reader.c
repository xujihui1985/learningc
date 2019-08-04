#include <sys/shm.h>
#include <sys/ipc.h>
#include <stdio.h>
#include <string.h>

int main() {
    key_t key = ftok("./shmfile", 'a');

    int shmid = shmget(key, 1024, 0666 | IPC_CREAT);

    char *str = (char *)shmat(shmid, NULL, SHM_RDONLY);

    printf("read from memory %s\n", str);

    shmdt(str);

    shmctl(shmid, IPC_RMID, NULL);

    return 0;
}
