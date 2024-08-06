#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define MAX_SIZE 100

/* stack structure */
typedef struct {
    int items[MAX_SIZE]; /* array of data */
    int top; /* index of top element in array of data */
} stack;

/* initialize stack */
void init_stack(stack *s) {
    s->top = -1;
}

/* check if stack is empty */
int is_empty(stack *s) {
    return s->top == -1;
}

/* check if stack is full */
int is_full(stack *s) {
    return s->top == MAX_SIZE - 1;
}

/* push value to stack */
void push(stack *s, int value) {
    if (is_full(s)) {
        printf("stack overflow! can not push %d to a full stack\n", value);
        return;
    } else {
        s->items[++(s->top)] = value;
        printf("%d pushed to stack\n", value);
        return;
    }
}

/* pop value from stack */
int pop(stack *s) {
    if (is_empty(s)) {
        printf("stack underflow! can not pop from an empty stack\n");
        return -1; 
    } else {
        return s->items[(s->top)--]; /* retrieve top element and decrement stack ptr */
    }
}

/* access top element in stack */
int peek(stack *s) {
    if (is_empty(s)) {
        printf("stack is empty\n");
        return -1;
    } else {
        return s->items[s->top];
    }
}

/* test function */
void test_stack() {
    stack* s = (stack*)malloc(sizeof(stack));
    init_stack(s);

    /* empty stack */
    assert(is_empty(s) == 1);
    assert(is_full(s) == 0);
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

    /* pushing to full stack */
    for (int i = 0; i < MAX_SIZE-1; i++) {
        push(s, i);
    }
    assert(is_full(s) == 1);
    push(s, 111); /* should print overflow message */

    /* popping from empty stack */
    for (int i = 0; i < MAX_SIZE; i++) {
        pop(s);
    }

    assert(is_empty(s) == 1);
    assert(pop(s) == -1); /* should print underflow message */
    printf("all tests passed for array-based stack.\n");
}

int main(void) {
    test_stack();
    /* printf("array based stacks\n"); */
    return 0;
}
