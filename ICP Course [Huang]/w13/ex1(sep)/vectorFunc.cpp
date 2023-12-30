#include "vector.h"
#include <stdlib.h>

vector* vector_construct(int length) {
    vector* vec = (vector*)malloc(sizeof(vector));
    vec->length = length;
    vec->vec = (int*)malloc(length * sizeof(int));
    return vec;
}