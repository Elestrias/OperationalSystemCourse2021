#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Proccess {
    int id;
    int AT;
    int BT;
    int TAT;
    int CT;
    int WT;
};

int main() {
    int x, at, bt, cur_time, ttat = 0, twt = 0;
    printf("Enter number of proccesses:\n");
    scanf("%d", &x);
    struct Proccess *Initial_List[x];
    struct Proccess Sorted_List[x];
    int **a = (int **)malloc(sizeof(int *) * x);
    for (int i = 0; i < x; i++) {
        a[i] = (int *)malloc(sizeof(int) * 2);
        printf("Enter ArrivalTime for proccess[%d]:\n", i + 1);
        scanf("%d", &at);
        printf("Enter BurstTime for proccess[%d]:\n", i + 1);
        scanf("%d", &bt);
        struct Proccess *new_proccess =
                (struct Proccess *)malloc(sizeof(struct Proccess));
        new_proccess->id = i;
        new_proccess->AT = at;
        new_proccess->BT = bt;
        Initial_List[i] = new_proccess;
        Sorted_List[i] = *(new_proccess);
    }
    int p = 0;
    int minBT = INT_MAX;
    int * completed = (int *)malloc(sizeof(int)*x);
    for (int i = 0; i < x; i++) {
        p = i;
        cur_time += Initial_List[i]->BT;
        for(int j = 0; j < x; j++){
            if(completed == 0 && Initial_List[0]->AT <= cur_time && Initial_List[i]->BT <=  minBT){
                p = j;
                minBT = Initial_List[i]->BT;
            }
        }
        completed[p] = 1;
        if (Initial_List[p]->AT > cur_time) {
            cur_time = Initial_List[p]->AT;
        }
        Initial_List[p]->CT = cur_time;
        Initial_List[p]->TAT = cur_time - Initial_List[p]->AT;
        Initial_List[p]->WT = Initial_List[i]->TAT - Initial_List[p]->BT;
        twt += Initial_List[p]->WT;
        ttat += Initial_List[p]->TAT;
    }

    printf("#P\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < x; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, Initial_List[i]->AT,
               Initial_List[i]->BT, Initial_List[i]->CT, Initial_List[i]->TAT,
               Initial_List[i]->WT);
    }
    printf("\nAverage turn around time = %f\nAverage waiting time = %f\n", (double)ttat / x, (double)twt / x);
}

