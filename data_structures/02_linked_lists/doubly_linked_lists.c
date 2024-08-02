#include <stdio.h>
#include <stdlib.h>

/* node structure for doubly linked list */
typedef struct node {
    int data; 
    struct node* prev; 
    struct node* next; 
} node;

/* doubly likned list structure */
typedef struct {
    node* head;
    node* tail;
} doubly_linked_list;

/* create a new node */
node* create_node(int data) {
    node* new_node = (node*)malloc(sizeof(node));
    if (new_node == NULL) {
        fprintf(stderr, "memory allocation failed\n");
        exit(1);
    }
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

/* initialize an empty list */
doubly_linked_list* init_list(){
    doubly_linked_list* list = (doubly_linked_list*)malloc(sizeof(doubly_linked_list));
    if (list == NULL) {
        fprintf(stderr, "memory allocation failed\n");
        exit(1);
    }
    list->head = NULL;
    list->tail = NULL;
    return list;
}

/* insert node at beginning of list */
void insert_at_head(doubly_linked_list* list, int data) {
    node* new_node = create_node(data);
    if (list->head == NULL) { /* list is empty */
        list->head = new_node;
        list->tail = new_node;
    } else {
        new_node->next = list->head;
        list->head->prev = new_node;
        list->head = new_node;
    }
}

/* insert node at end of list */
void insert_at_tail(doubly_linked_list* list, int data) {
    node* new_node = create_node(data);
    if (list->tail == NULL) { /* list is empty */
        list->head = new_node;
        list->tail = new_node;
    } else {
        new_node->prev = list->tail;
        list->tail->next = new_node;
        list->tail = new_node;
    }
}

/* delete a node with given data */
void delete_node(doubly_linked_list* list, int data) {
    if (list->head == NULL) return; /* uninitialized list */
    node* current = list->head;
    while (current != NULL) {
        if (current->data == data) { /* found node to be deleted */
            if (current->prev != NULL) { /* node to be deleted is not the head */
                current->prev->next = current->next; 
            } else { /*  node to be deleted is the head */
                list->head = current->next; 
            }
            if (current->next != NULL) { /* node to be deleted is not the tail */
                current->next->prev = current->prev; 
            } else { /* node to be deleted is the tail */
                list->tail = current->prev;
            }
            free(current);
            return;
        }
        current = current->next; /* node with data not found, traverse to next node  */
    }
}

/* search for a node with given data */
node* search(doubly_linked_list* list, int data) {
    node* current = list->head; /* start at beginning of the list */
    while (current != NULL) {
        if (current->data == data) return current; /* node found */
        current = current->next;
    }
    return NULL; /* node not found */
}

/* print the list via forward traversal */
void print_list_forward(doubly_linked_list* list) {
    node* current = list->head; /* start at beginning of list */
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->next; /* move forwards through list */
    }
    printf("NULL\n"); /* end of list reached */
}

/* print the list via backward traversal */
void print_list_backward(doubly_linked_list* list) {
    node* current = list->tail; /* start at end of list */
    while (current != NULL) {
        printf("%d <-> ", current->data);
        current = current->prev; /* move backwards through list */
    }
    printf("NULL\n");
}

/* free an entire list from dynamically allocated memory */
void free_list(doubly_linked_list* list) {
    node* current = list->head;
    while (current != NULL) {
        node* temp = current;
        current = current->next;
        free(temp);
    }
    free(list);
    
}

/* test function */
void test_doubly_linked_list() {
    doubly_linked_list* list = init_list();

    insert_at_head(list, 3);
    insert_at_head(list, 3);
    insert_at_head(list, 42);
    insert_at_head(list, 1);
    insert_at_tail(list, 7);

    printf("initial list forwards: ");
    print_list_forward(list);
    printf("initial list backwards: ");
    print_list_backward(list);

    delete_node(list, 42);
    printf("list after deleting 42 (forward): ");
    print_list_forward(list);

    node* found = search(list, 7);
    if (found) printf("found node with data: %d\n", found->data);
    else printf("node not found\n");

    free_list(list);
}

/* driver program */
int main(void) {
    test_doubly_linked_list();
    return 0;
}
