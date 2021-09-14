#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(){
    for(int i = 0; i<5; i++) {
        fork();
        sleep(5);
    }
    return 0;
}