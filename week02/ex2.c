#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char *input = NULL;
    size_t n = 0;
    printf("Enter line to be reversed:\n");
    getline(&input, &n, stdin);
    for(unsigned long i = strlen(input)-1; i>0; i--){
        printf("%c",  input[i]);
    }
    printf("%c\n", *input);
    return 0;
}

