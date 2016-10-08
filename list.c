#include <stdlib.h>
#include <stdio.h>

struct node { int i; struct node *next; };

void print_list ( struct node *list ){
    printf("[ %s ", list.i);
    while(list.next != 0 ){
        printf(", %s ", list.next);
    }
    printf("]");
}

struct node * insert_front (struct node *list, int data){
    struct node *new = malloc(sizeof(struct node));
    new.i = data;
    new.next = list;
    return new;
}

struct node * free_list (struct node *list){
    struct node *start = *list;
    while(list.next!=0){
        free(list.i);
    }
    return start;
}

int main(){
    struct node *try;
    try = (struct node *)malloc(sizeof(struct node));
    try.i = 10;
    try.next = 0;

    printf("try: ");
    print_list(try);

    return 0;
}
