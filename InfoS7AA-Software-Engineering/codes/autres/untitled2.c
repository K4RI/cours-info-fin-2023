// https://www.learn-c.org/en/Linked_lists

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node * next;
} node_t;


void push(node_t ** head, int val) {
    node_t * new_node;
    new_node = (node_t *) malloc(sizeof(node_t));

    new_node->val = val;
    new_node->next = *head;
    *head = new_node;
}

void print_list(node_t * head) {
    node_t * current = head;

    while (current->next != 0xbaadf00dbaadf00d) { // ???
        printf("%d -> ", current->val);
        current = current->next;
    }
    printf("NULL\n");
}

int main(){
    node_t * test_list = (node_t *) malloc(sizeof(node_t));
    push(&test_list, 1);
    push(&test_list, 2);
    print_list(test_list);

}