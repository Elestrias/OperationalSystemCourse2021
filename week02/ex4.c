#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int * a, int * b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main(){
   int a, b;
    printf("Enter nambers to be swapped:\n");
    scanf("%d %d", &a, &b);
    printf("a: %d, b: %d\n", a, b);
    swap(&a, &b);
    printf("a: %d, b: %d\n", a, b);
}


