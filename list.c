#include <stdlib.h>
#include <stdio.h>

struct node { int i; struct node *next };

void print_list ( struct node *list ){
    printf("[ %s ", *list);
    while(list.next != 0 ){
        *list ++;
        printf(", %s ", *list);
    }
    printf("]");
}

int main(){
    return 0;
}
