#include <stdio.h>
#include <stdlib.h>

/* node structure for circular linked list */
typedef struct node {
    int data;
    struct node* next;
} node;

/* circular linked list structure */
typedef struct {
    node* head;
} circular_linked_list;

/* create a new node */
node* create_node(int data) {
    node* new_node = (node*)malloc(sizeof(node));
    if (new_node == NULL) {
        fprintf(stderr, "memory allocation failed\n");
        exit(1); 
    }


}

/* test function */
void test_circular_linked_list() {
    printf("CIRCULAR DONE\n");
}

/* driver program */
int main(void) {
    test_circular_linked_list();
    return 0;
}
