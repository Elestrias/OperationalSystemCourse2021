#include <stdio.h>

void bubble_sort(int *array, const int sizer)
{
    for(int i = 0; i < sizer; ++i){
        for(int j = i + 1; j < sizer; ++j){
            if (array[i] > array[j])
            {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

int main(){
    int a[10] = {2, 1 , 3 ,5 , 3, 4, 8, 9, 10, 11};
    printf("Unsorted: \n");
    for(int i = 0; i<10; i++){
        printf("%d ", a[i]);
    }
    bubble_sort(a, 10);
    printf("\nSorted: \n");

    for(int i = 0; i<10; i++){
        printf("%d ", a[i]);
    }
    printf("\nDone!");
return 0;
}

