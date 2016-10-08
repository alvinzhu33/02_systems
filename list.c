#include <stdlib.h>
#include <stdio.h>

struct node { int i; struct node *next; };

void print_list ( struct node *list ){
    printf("[ %i ", list->i);
    while(list->next){
        list = list->next;
        printf(", %i ", list->i);
    }
    printf("]\n");
}

struct node * insert_front (struct node *list, int data){
    struct node *new = malloc(sizeof(struct node));
    new->i = data;
    new->next = list;
    return new;
}

struct node * free_list (struct node *list){
    struct node *start = list;
    struct node *nextList = malloc(sizeof(struct node));
    while(list->next){
        nextList = list->next;
        free(list);
        list = nextList;
    }
    return start;
}

int main(){
    struct node *try;
    try = (struct node *)malloc(sizeof(struct node));
    try->i = 10;
    try->next = 0;

    printf("try: ");
    print_list(try);

    int i;
    for(i=9; i>0; i--){
        try = insert_front(try, i);
        print_list(try);
    }

    free_list(try);
    print_list(try);

    return 0;
}
