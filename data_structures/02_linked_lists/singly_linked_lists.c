#include <stdio.h>
#include <stdlib.h>

/* node structure for singly linked list */
typedef struct node {
    int data;
    struct node* next;
} node;

/* singly linked list structure */
typedef struct {
    node* head;
} singly_linked_list;

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
singly_linked_list* init_list() {
    singly_linked_list* list = (singly_linked_list*)malloc(sizeof(singly_linked_list));
    if (list == NULL) {
        fprintf(stderr, "memory allocation failed\n");
        exit(1);
    }

    list->head = NULL;

    return list;
}

/* insert node at beginning of list */
void insert_at_head(singly_linked_list* list, int data) {
    node* new_node = create_node(data);
    new_node->next = list->head;
    list->head = new_node;
}

/* insert node at end of list */
void insert_at_tail(singly_linked_list* list, int data) {
    node* new_node = create_node(data);
    if (list->head == NULL) {
        list->head = new_node;
        return;
    }
    node* temp = list->head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

/* delete a node with given data */
void delete_node(singly_linked_list* list, int data) {
    if (list->head == NULL) return; /* uninitialized list */

    if (list->head->data == data) { /* head of list is to be deleted */
        node* temp = list->head;
        list->head = list->head->next;
        free(temp);
        return;
    }

    /* loop through to end of list or until data is found */
    node* current = list->head;
    while (current->next != NULL && current->next->data != data) {
        current = current->next;
    }
    if (current->next != NULL) { /* data is found */
        node* temp = current->next;
        current->next = current->next->next;
        free(temp);
    }
}

/* search for a node with given data */
node* search(singly_linked_list* list, int data) {
    node* current = list->head;
    while (current != NULL) {
        if (current->data == data) return current; /* node found */
        current = current->next;
    }
    return NULL; /* node not found */
}

/* print a list */
void print_list(singly_linked_list* list) {
    node* current = list->head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n"); /* end of list reached */
}

/* free an entire list from dynamically allocated memory */
void free_list(singly_linked_list* list) {
    node* current = list->head;
    while (current != NULL) {
        node* temp = current;
        current = current->next; 
        free(temp);
    }
    free(list);
}

/* test function */
void test_singly_linked_list() {
    singly_linked_list* list = init_list();

    insert_at_head(list, 3);
    insert_at_head(list, 3);
    insert_at_head(list, 1);
    insert_at_tail(list, 7);

    printf("initial list: ");
    print_list(list);
        
    /* TODO: complete test function */
}


/* driver program */
int main(void) {
    test_singly_linked_list();
    printf("SINGLY DONE\n");
    return 0;
}
