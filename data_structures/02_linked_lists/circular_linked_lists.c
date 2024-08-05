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

/* delete node with given data */
void delete_node(circular_linked_list* list, int data) {
    if (list->head == NULL) return;

    node* current = list->head;
    node* prev = NULL;

    do {
        if (current->data == data) {
            if (prev == NULL) { /* head is to be deleted */
                if (current->next == list->head) { /* only one node in list */
                    free(current);
                    list->head = NULL;
                } else {
                    node* last = list->head;
                    while (last->next != list->head) { /* find last node in the list */
                        last = last->next;
                    }
                    list->head = current->next; 
                    last->next = list->head;
                    free(current);
                }
            }
        }
    } while (current != list->head); /* loop until head we circle back to the head */
}


/* search for node with given data */
node* search(circular_linked_list* list, int data) {
    if (list->head == NULL) return NULL; /* empty list */

    node* current = list->head;
    do {
        if (current->data == data) return current; /* node found */
        current = current->next;
    } while (current != list->head); /* loop until head we circle back to the head */

    return NULL; /* node not found */
}

/* print a list */
void print_list(circular_linked_list* list) {
    if (list->head == NULL) { /* empty list */
        printf("empty list\n");
        return;
    }
    node* current = list->head;
    do {
        printf("%d -> ", current->data);
        current = current->next;
    } while (current != list->head);
    printf("(back to start)\n");
}

/* free an entire list from dynamically allocated memory */
void free_list(circular_linked_list* list) {
    if (list->head == NULL) { /* empty list */
        free(list);
        return;
    }

    node* current = list->head->next; /* start at the second node */
    while (current != list->head) { /* loop through every node */
        node* temp = current;
        current = temp->next;
        free(temp);
    }
    free(list->head); /* return back to the head of list */
    free(list);
}

/* test function */
void test_circular_linked_list() {
    circular_linked_list* list = init_list();

    insert_at_head(list, 3);
    insert_at_head(list, 3);
    insert_at_head(list, 42);
    insert_at_head(list, 1);
    insert_at_tail(list, 7);

    printf("initial list: ");
    print_list(list);

    delete_node(list, 42);
    printf("list after deleting 42: ");
    print_list(list);

    node* found = search(list, 7);
    if (found) printf("found node with data: %d\n", found->data);
    else printf("node not found\n");

    free_list(list);
}

/* driver program */
int main(void) {
    test_circular_linked_list();
    return 0;
}
