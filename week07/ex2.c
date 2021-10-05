#include <stdio.h>
#include <stdlib.h>

int main() {
    int N;
    printf("Enter number of numbers\n");
    scanf("%d", &N);
    int * array = (int*)malloc(sizeof(int)*N);
    for(int i = 0; i<N; i++) {
        array[i] = i;
    }
    for(int i = 0; i<N; i++) {
       printf("%d ", array[i]);
    }
    printf("\n");
    free(array);
}
