#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>


struct employee_rec {
    int employee_id;
    char first_name[255];
    char last_name[255];
};

int main(int argc, char **argv)
{
    int fd, i;
    size_t dbsize;
    struct employee_rec *records;
    int record_size = sizeof(struct employee_rec);

    if((fd = open("employee.db", O_RDWR | O_CREAT, S_IRWXU | S_IRWXG)) < 0) {
        perror("failed to open file");
        exit(1);
    }

    dbsize = lseek(fd, 0, SEEK_END);

    if(argc == 2) {
        if(strcmp(argv[1], "fetch") == 0) {
            records = (struct employee_rec *)mmap(NULL, dbsize,
                    PROT_READ,
                    MAP_PRIVATE, fd, 0);

            for(i = 0; i < (int)dbsize / record_size; i++) {
                struct employee_rec record = records[i];
                printf("[%d]: %s, %s \n", record.employee_id, record.first_name, record.last_name);
            }

            if (munmap(records, dbsize) < 0) {
                perror("failed to umap");
                exit(1);
            }
        } else if(strcmp(argv[1], "modify") == 0) {
            records = (struct employee_rec *)mmap(NULL, dbsize,
                                                 PROT_READ + PROT_WRITE,
                                                 MAP_SHARED, fd, 0);
            for (i = 0; i <(int)dbsize / record_size; i++) {
                records[i].employee_id = 999;
            }
            if(msync(records, dbsize, MS_SYNC) < 0) {
                perror("failed to write to db");
                exit(1);
            }
            printf("modify success");
            if (munmap(records, dbsize) < 0)
            {
                perror("failed to umap");
                exit(1);
            }
        }

    }
    exit(0);
    close(fd);
}
