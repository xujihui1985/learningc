#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>


static jmp_buf savebuf;
static int exception_value = 0;

enum Error {
    InvalidArgs = 1
};

#define TRY \
    if (setjmp(savebuf) == 0)
 
#define CATCHALL else

#define CATCH(NUM) \
    else if (exception_value == NUM)

#define THROW(NUM) \
    do {\
      exception_value = NUM; \
      longjmp(savebuf, NUM); \
    } while(0)


double compute_avg(double *darr, size_t length) {
    double sum;
    size_t i;

    if (length <= 0) {
        THROW(InvalidArgs);
    }

    sum = 0;
    for (i = 0; i < length; i++) {
        sum += darr[i];
    }

    return sum / (double)length;
}

int main(int argc, char **argv) {
    int arrlength, i;
    arrlength = argc - 1;
    double *darr = (double *)malloc(sizeof(double) * arrlength);
    for (i = 1; i < argc; i++) {
        darr[i - 1] = atof(argv[i]);
    }

    TRY {
        double avg = compute_avg(darr, arrlength);
        printf("average = %1f\n", avg);
        return 0;
    } CATCH(InvalidArgs) {
        fprintf(stderr, "invalid args \n");
    }

    return 1;
}

