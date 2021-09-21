#include <stdio.h>
#include <stdint.h>
#include <pthread.h>


void* Thread(void * thread_data){
    int * number = (int*)(thread_data);
    printf("Hello from th %d\n", *number);
    pthread_exit(0);
}


int main(){
    pthread_t thread;
    int * thread_data;
    for(int i = 0; i < 5; i++) {
        thread_data = &i;
        if (pthread_create(&thread, NULL, Thread, (void *) thread_data)) {
            printf("ERROR IN CREATING NEW THREAD #!\n");
        } else {
            printf("Thread %d has been created\n", i);
            pthread_join(thread, NULL);
        }
    }

}