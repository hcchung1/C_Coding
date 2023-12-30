#include "matrix.h"
#include "vector.h"
#include <stdio.h>
#include <stdlib.h>

matrix2D* matrix2D_construct(int m, int n) {
    matrix2D* mat = (matrix2D*)malloc(sizeof(matrix2D));
    mat->row = m;
    mat->column = n;
    mat->mat = (vector*)malloc(m * sizeof(vector));

    for (int i = 0; i < m; ++i) {
        mat->mat[i] = *vector_construct(n);
    }
    return mat;
}

void matrix2D_fillwith(matrix2D* A, int num) {
    for (int i = 0; i < A->row; ++i) {
        for (int j = 0; j < A->column; ++j) {
            A->mat[i].vec[j] = num;
        }
    }
}

matrix2D* matrix2D_multiple(matrix2D* A, matrix2D* B) {
    if (A->column != B->row) {
        printf("Shape Error\n");
        return NULL;
    }

    matrix2D* result = matrix2D_construct(A->row, B->column);

    for (int i = 0; i < A->row; ++i) {
        for (int j = 0; j < B->column; ++j) {
            int sum = 0;
            for (int k = 0; k < A->column; ++k) {
                sum += A->mat[i].vec[k] * B->mat[k].vec[j];
            }
            result->mat[i].vec[j] = sum;
        }
    }

    return result;
}

void print_matrix(matrix2D* A) {
    for (int i = 0; i < A->row; ++i) {
        for (int j = 0; j < A->column; ++j) {
            printf("%d ", A->mat[i].vec[j]);
        }
        printf("\n");
    }
}