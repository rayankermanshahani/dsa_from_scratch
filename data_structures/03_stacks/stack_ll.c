#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/* node structure for stack elements */
typedef struct node {
    int data;
    struct node* next;
} node;

/* stack structure */
typedef struct {
    node* top;
} stack;

/* initialize stack */
void init_stack(stack* s) {
    s->top = NULL;
}

/* check if stack is empty */
int is_empty(stack* s) {
    return s->top == NULL;
}

/* push element to stack */
void push(stack* s, int value) {
    node* new_node = (node*)malloc(sizeof(node));
    if (new_node == NULL) {
        fprintf(stderr, "memory allocation failed. can not push %d to stack\n", value);
        return;
    }
    new_node->data = value;
    new_node->next = s->top;
    s->top = new_node;
}

/* pop element from stack */
int pop(stack* s) {
    if (is_empty(s)) {
        printf("stack underflow! can not pop from an empty stack\n");
        return -1;
    } else {
        node* temp = s->top;
        int value = temp->data;
        s->top = s->top->next;
        free(temp);
        return value;
    }
}

/* access value at top of stack */
int peek(stack *s) {
    if (is_empty(s)) {
        printf("stack is empty\n");
        return -1;
    } else {
        return s->top->data;
    }
}

/* free stack data from dynamically allocated memory */
void free_stack(stack* s) {
    while (!is_empty(s))
        pop(s);
}

 
void test_stack() {
    stack* s = (stack*)malloc(sizeof(stack));
    init_stack(s);

    /* empty stack */
    assert(is_empty(s) == 1);
    assert(peek(s) == -1);

    /* pushing elements */
    push(s, 10);
    push(s, 11);
    push(s, 20);
    push(s, 24);
    assert(is_empty(s) == 0);
    assert(peek(s) == 24);

    /* popping elements */
    assert(pop(s) == 24);
    assert(pop(s) == 20);
    assert(pop(s) == 11);

    /* pushing many elements */
    for (int i = 0; i < 1000; i++) {
        push(s, i);
    }
    assert(peek(s) == 999);

    /* popping many elements */
    for (int i = 999; i >= 0; i--) {
        assert(pop(s) == i);
    }
    pop(s);
    assert(is_empty(s) == 1);

    /* popping from an empty stack */
    assert(pop(s) == -1); /* should print underflow message */

    printf("all tests passed for linked list-based stack\n");

    free_stack(s);
}

int main(void) {
    test_stack();
    return 0;
}
