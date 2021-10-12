#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>

int main() {
    for(int i = 0; i<10; i++) {
        void *what = malloc(10 * 1024 * 1024);
        struct rusage usage;
        memset(what, 0, 10 * 1024 * 1024);
        getrusage(RUSAGE_SELF, &usage);
        printf("Memory usage at current stage: %ld\n", usage.ru_maxrss);
        sleep(1);
    }
}

