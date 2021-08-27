#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char ** argv){
    int height = atoi(argv[1]);
    for(int i = 1; i<=height; i++){
        for(int j = 0; j<height - i; ++j){
            printf(" ");
        }
        for(int j = 0; j < 2 * i - 1; j++){
            printf("*");
        }
        printf("\n");
    }

}


