#include <stdio.h>
#include <stdlib.h>
#include <memory.h>


void * Myrealloc(void * data, int size, int old_size){
    void * new_store = malloc(size);
    if(data == NULL){
        return new_store;
    }else if (size == 0){
        free(data);
        free(new_store);
        return NULL;
    }else{
        memmove(new_store, data, old_size<size ? old_size: size);
        free(data);
        return new_store;
    }

}

int main(){
    int * a = (int *)malloc(sizeof(int) * 10);
    for(int i = 0; i < 10; i++){
        a[i] = i;
        printf("%d ", a[i]);
    }
    printf("\n");
    a = Myrealloc(a, 15*sizeof(int), 10*sizeof(int));
    for(int i = 0; i < 15; i++){
        a[i] = i;
        printf("%d ", a[i]);
    }
    printf("\n");
    a = Myrealloc(a, 10*sizeof(int), 15*sizeof(int));
    for(int i = 0; i < 10; i++){
        a[i] = i;
        printf("%d ", a[i]);
    }
    printf("\n");
    a = Myrealloc(a, 0, 10*sizeof(int));
    if(a == NULL){
        printf("IT is NULL\n");
    }
    int * new_a = Myrealloc(a, 10*sizeof(int), 0);
    for(int i = 0; i < 10; i++){
        new_a[i] = i;
        printf("%d ", new_a[i]);
    }
    printf("\n");
    free(a);
}