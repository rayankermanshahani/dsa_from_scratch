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

int main(void) {
    printf("DONE\n");
    return 0;
}

