/* implementation of a vector (dynamic array) object */
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;
    size_t size;
    size_t capacity;
} vector;

vector* create_vector(size_t initial_capacity) {
    /* allocate memory for the vector object itself */
    vector* vec = (vector*)malloc(sizeof(vector)); 
    if (vec == NULL)
        return NULL;

    /* allocate memory for the vector's data */
    vec->data = (int*)malloc(initial_capacity * sizeof(int));
    if (vec->data == NULL) {
        free(vec);
        return NULL;
    }

    vec->size = 0;
    vec->capacity = initial_capacity;
    return vec;
}

void free_vector(vector* vec) {
    if (vec) {
        free(vec->data);
        free(vec);
    }
}

int resize(vector* vec) {
    size_t new_capacity = vec->capacity * 2; /* double the vector's capacity */
    int* new_data = (int*)realloc(vec->data, new_capacity * sizeof(int));
    if (new_data == NULL)
        return 0; /* resize failed */

    vec->data = new_data;
    vec->capacity = new_capacity;
    return 1; /* resize successful */
}

int append(vector* vec, int elem) {
    if (vec->size == vec->capacity)
        if (!resize(vec)) 
            return 0; /* append failed */ 
    vec->data[vec->size++] = elem;
    return 1; /* append successful */
}

int delete(vector* vec, size_t index) {
    if (index < 0 || index >= vec->size) {
        printf("delete() error: invalid index\n");
        return 0; /* invalid index */
    }
    for (size_t i = index; i < vec->size-1; i++) {
        vec->data[i] = vec->data[i+1];
    }
    vec->size--;
    if (vec->size > 0 && vec->size == vec->capacity)
        resize(vec); 
    return 1;
}

int replace(vector* vec, size_t index, int elem) {
    if (index < 0 || index >= vec->size) {
        printf("replace() error: invalid index\n");
        return 0; /* invalid index */
    }
    vec->data[index] = elem;
    return 1; /* replace successful */
}

int get(vector* vec, size_t index, int* elem) {
    if (index < 0 || index >= vec->size) {
        printf("get() error: invalid index\n");
        return 0; /* invalid index */
    }
    *elem = vec->data[index];
    return 1; /* get successful */
}

void print_vector(vector* vec) {
    printf("vector (size: %zu, capacity: %zu): [ ", vec->size, vec->capacity);
    for (size_t i = 0; i < vec->size; i++) {
        printf("%d, ", vec->data[i]);
    }
    printf("]\n");
}

void test_vector() {
    vector* vec = create_vector(2); /* vec: [ , ,] */
    append(vec, 1); /* vec: [1, ,] */
    append(vec, 3); /* vec: [1, 3,] */
    append(vec, 3); /* vec: [1, 3, 3, ,]; triggers resize() */
    append(vec, 6); /* vec: [1, 3, 3, 6,] */
    replace(vec, 3, 4); /* vec: [1, 3, 3, 4,] */
    append(vec, 9); /* vec: [1, 3, 3, 4, 9, , , ,]; trigger resize() */
    append(vec, 7); /* vec: [1, 3, 3, 4, 9, 7, , ,] */
    delete(vec, 3); /* vec: [1, 3, 3, 9, 7, , , ,] */
    delete(vec, 3); /* vec: [1, 3, 3, 7, , , , ,] */

    print_vector(vec);

    int elem;
    if (get(vec, 0, &elem)) {
        printf("element at index 0: %d\n", elem);
    }
    if (get(vec, 1, &elem)) {
        printf("element at index 1: %d\n", elem);
    }
    if (get(vec, 2, &elem)) {
        printf("element at index 2: %d\n", elem);
    }
    if (get(vec, 3, &elem)) {
        printf("element at index 3: %d\n", elem);
    }

    free_vector(vec);
}

int main(void) {
    test_vector();
    printf("DONE\n");
    return 0;
}

