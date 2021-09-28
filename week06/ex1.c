#include <stdio.h>
#include <stdlib.h>

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


  for (int i = 0; i < x; i++) {
    cur_time += Initial_List[i]->BT;
    if (Initial_List[i]->AT > cur_time) {
      cur_time = Initial_List[i]->AT;
    }
    Initial_List[i]->CT = cur_time;
    Initial_List[i]->TAT = cur_time - Initial_List[i]->AT;
    Initial_List[i]->WT = Initial_List[i]->TAT - Initial_List[i]->BT;
    twt += Initial_List[i]->WT;
    ttat += Initial_List[i]->TAT;
  }

  printf("#P\tAT\tBT\tCT\tTAT\tWT\n");
  for (int i = 0; i < x; i++) {
    printf("P%d\t%d\t%d\t%d\t%d\t%d\n", i + 1, Initial_List[i]->AT,
           Initial_List[i]->BT, Initial_List[i]->CT, Initial_List[i]->TAT,
           Initial_List[i]->WT);
  }
  printf("\nAverage turn around time = %f\nAverage waiting time = %f\n", (double)ttat / x, (double)twt / x);
}
