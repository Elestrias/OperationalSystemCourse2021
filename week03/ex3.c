#include <stdio.h>
#include <stdlib.h>

struct LinkedNode{
    int value;
    struct LinkedNode * next;
};

void print_list(struct LinkedNode * head){
    int flag = 0;
    printf("Your linked list content: \n");
    while (head->next != NULL){
        if (flag)
        {
            printf("%d ", head->value);
        }
        flag = 1;
        head = head->next;

    }
}

void insert_node(struct LinkedNode * head, int value, int index){
        for (int i = 0; i < index; i++) {
            head = head->next;
        }
        struct LinkedNode *new_node = (struct LinkedNode *) malloc(sizeof(struct LinkedNode));
        new_node->value = value;
        if (head->next != NULL) {
            struct LinkedNode *nextNext = head->next;
            head->next = new_node;
            new_node->next = nextNext;
        }
        head->next = new_node;
        new_node->next = NULL;
}

void delete_node(struct LinkedNode * head, int index){
    struct LinkedNode * previous;
    for(int i = 0; i<index;i++){
        previous = head;
        head = head->next;
    }
    if(head->next == NULL){
        previous->next = NULL;
        free(head);
    }
    else{
        struct LinkedNode * nextNext = head->next;
        previous->next = nextNext;
        free(head);
    }
}
int main(){
    struct LinkedNode *list = malloc(sizeof(struct LinkedNode));
    for(int i = 0; i < 10; ++i){
        insert_node(list, i, i);
    }
    print_list(list);
    delete_node(list, 3);
    printf("\n");
    print_list(list);
    return 0;
}


