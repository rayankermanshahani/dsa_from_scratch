/* implementation of a vector (dynamic array) object */
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* elements;
    size_t size;
    size_t capacity;
} vector;

vector* create_vector(size_t initial_capacity) {
    /* allocate memory for the vector object itself */
    vector* vec = (vector*)malloc(sizeof(vector)); 
    if (vec == NULL) {
        return NULL;
    }

    /* allocate memory for the vector's elements */
    vec->elements = (int*)malloc(initial_capacity * sizeof(int));
    if (vec->elements == NULL) {
        free(vec);
        return NULL;
    }

    vec->size = 0;
    vec->capacity = initial_capacity;
    return vec;
}

void free_vector(vector* vec) {
    if (vec) {
        free(vec->elements);
        free(vec);
    }
}

int resize(vector* vec) {
    size_t new_capacity = vec->capacity * 2; /* double the vector's capacity */
    int* new_elements = (int*)realloc(vec->elements, new_capacity * sizeof(int));
    if (new_elements == NULL) {
        return 0; /* resize failed */
    }

    vec->elements = new_elements;
    vec->capacity = new_capacity;
    return 1; /* resize successful */
}

int insert(vector* vec, int elem) {
    if (vec->size == vec->capacity) {
        if (!resize(vec)) {
            return 0; /* insert failed */ 
        }
    }
    vec->elements[vec->size++] = elem;
    return 1; /* insert successful */
}

int get(vector* vec, size_t index, int* elem) {
    if (index >= vec->size) {
        return 0; /* invalid index */
    }
    *elem = vec->elements[index];
    return 1; /* get successful */
}

void print_vector(vector* vec) {
    printf("vector (size: %zu, capacity: %zu): [ ", vec->size, vec->capacity);
    for (size_t i = 0; i < vec->size; i++) {
        printf("%d, ", vec->elements[i]);
    }
    printf("]\n");
}

void test_vector() {
    vector* vec = create_vector(2);
    insert(vec, 1);
    insert(vec, 3); 
    insert(vec, 3); /* this insert() should trigger a call to resize() */
    insert(vec, 7);

    print_vector(vec);

    int elem;
    if (get(vec, 2, &elem)) {
        printf("element at index 2: %d\n", elem);
    }

    free_vector(vec);
}

int main(void) {
    test_vector();
    printf("DONE\n");
    return 0;
}

