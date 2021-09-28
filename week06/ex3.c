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
    int Change_BT;
};

int main() {
    int x, quant, at, bt, ttat = 0, twt = 0;
    printf("Enter number of proccesses:\n");
    scanf("%d", &x);
    printf("Enter quantum:\n");
    scanf("%d", &quant);
    struct Proccess *Initial_List = malloc(sizeof(struct Proccess) * x);
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
        new_proccess->Change_BT = bt;
        Initial_List[i] = *new_proccess;
        Sorted_List[i] = *(new_proccess);
    }
    int p = 0;
    int minBT = INT_MAX;
    int finished = 0;
    int * completed = (int *)malloc(sizeof(int)*x);
    for(int i = 0; i < x; i ++){
        completed[i] = 0;
    }
    int cur_time = Initial_List[0].AT;
    int o = 0;
    while(finished != x){
        if(completed[o] == 1){
            o = (o+1)%x;
        }
        if(Initial_List[o].BT <= quant){
            cur_time += Initial_List[o].BT;
            Initial_List[o].CT = cur_time;

            Initial_List[o].TAT = Initial_List[o].CT - Initial_List[o].AT;
            ttat += Initial_List[o].TAT;
            Initial_List[o].WT = Initial_List[o].TAT - Initial_List[o].Change_BT;
            twt += Initial_List[o].WT;
            completed[o] = 1;
            finished++;
            o = (o + 1)%x;
        }else{
            cur_time += quant;
            Initial_List[o].BT -= quant;
            o = (o+1)%x;
        }
    }

    printf("#P\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < x; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, Initial_List[i].AT,
               Initial_List[i].BT, Initial_List[i].CT, Initial_List[i].TAT,
               Initial_List[i].WT);
    }
    printf("\nAverage turn around time = %f\nAverage waiting time = %f\n", (double)ttat / x, (double)twt / x);
}


