#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/uio.h>

#define NUMBER_OF_BUFFER 5

struct employee_rec {
    int employee_id;
    char first_name[255];
    char last_name[255];
};

int main(int argc, char **argv)
{
    struct iovec iov[NUMBER_OF_BUFFER];
    int record_size = sizeof(struct employee_rec);
    int fd, i;
    ssize_t bytes_read, bytes_written = 0;

    if((fd = open("employee.db", O_RDWR | O_CREAT, S_IRWXU | S_IRWXG)) < 0) {
        perror("failed to open file");
        exit(1);
    }

    for (i = 0; i < NUMBER_OF_BUFFER; i++) {
        iov[i].iov_base = malloc(record_size);
        iov[i].iov_len = record_size;
    }

    if (argc == 2)
    {
        if (strcmp(argv[1], "fetch") == 0)
        {
            printf("fetch employee from db \n");
            while((bytes_read = readv(fd, iov, NUMBER_OF_BUFFER)) > 0)
            {
                printf("Read %ld bytes from db\n", bytes_read);
                for (i = 0; i < NUMBER_OF_BUFFER; i++) 
                {
                    struct employee_rec *rec = (struct employee_rec *)iov[i].iov_base;
                    printf("(iov buffer %d) [%d]: %s %s\n",
                            i,
                            rec->employee_id,
                            rec->first_name,
                            rec->last_name);
                }
            }
            if (bytes_read <=0)
                exit(1);
        } else if(strcmp(argv[1], "create") == 0) {
            struct employee_rec recs[NUMBER_OF_BUFFER] = {
                {1, "hello", "world"},
                {2, "hello1", "world"},
                {3, "hello2", "world"},
                {4, "hello3", "world"},
                {5, "hello4", "world"},
            };
            for (i =0; i < NUMBER_OF_BUFFER; i++) {
                memcpy(iov[i].iov_base, &recs[i], record_size);
            }

            bytes_written = writev(fd, iov, NUMBER_OF_BUFFER);
            printf("write %ld bytes \n", bytes_written);
        }
    }
    close(fd);
}
