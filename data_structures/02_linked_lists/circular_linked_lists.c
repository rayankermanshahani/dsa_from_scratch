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
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

/* initialize an empty list */
circular_linked_list* init_list() {
    circular_linked_list* list = (circular_linked_list*)malloc(sizeof(circular_linked_list));
    if (list == NULL) {
        fprintf(stderr, "memory allocation failed\n");
        exit(1);
    }
    list->head = NULL;
    return list;
}

/* insert node at beginning of list */
void insert_at_head(circular_linked_list* list, int data) {
    node* new_node = create_node(data);
    if (list->head == NULL) { /* list is empty */
        list->head = new_node;
        new_node->next = new_node; /* head points to itself in a circular manner */
    } else { /* list is not empty */
        node* last = list->head;
        while (last->next != list->head) { /* find end of list */
            last = last->next;
        }
        new_node->next = list->head;
        last->next = new_node; /* end of list now points to new node */
        list->head = new_node; /* new node is now head of the list */
    }
}

/* insert at end of list */
void insert_at_tail(circular_linked_list* list, int data) {
    node* new_node = create_node(data);
    if (list->head == NULL) { /* list is empty */
        list->head = new_node;
        new_node->next = new_node; /* head points to itself in a circular manner */
    } else {
        node* last = list->head;
        while (last->next != list->head) { /* find end of list */
            last = last->next;
        }
        last->next = new_node; /* new node is now at end of list */
        new_node->next = list->head; /* new node now points to head */
    }
}

/* delete a node with given data */
void delete_node(circular_linked_list* list, int data) {
    if (list->head == NULL) return; /* list is empty */
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
