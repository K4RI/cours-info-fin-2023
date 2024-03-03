#include <stdio.h>
#include <stdlib.h>

typedef struct s_List LinkedList;
struct s_List { LinkedList *next;
                int data ;
};

LinkedList *insert(int ndata, LinkedList *list){
    LinkedList *newlist = malloc(sizeof(newlist));    
    if (list->data == NULL){
        newlist->data = ndata;
        newlist->next = NULL;
    } else {
        newlist->data = ndata;
        newlist->next = list;
    }
    return newlist;
}

void print_list(LinkedList *list){
    printf(list->data);
    /*if (list){
        if (list->data){
        }        
        print_list(list->next);
    } */
}

int main() {
    LinkedList *list = NULL;
    LinkedList *nlist = insert(10, list);
    print_list(list);
    return 0;
}