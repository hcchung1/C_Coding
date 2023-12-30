#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct _vector {
	int length;
	int* vec;
}vector;

typedef struct _matrix2D {
	int row, column;
	vector* mat;

}matrix2D;

vector* vector_construct(int length) {
    vector* vec = (vector*)malloc(sizeof(vector));
    vec->length = length;
    vec->vec = (int*)malloc(length * sizeof(int));
    return vec;
}

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

int main()
{
    matrix2D* A, * B;
    int A_row, A_column, B_row, B_column, A_number, B_number;
    scanf("%d %d %d %d %d %d", &A_row, &A_column, &B_row, &B_column, &A_number, &B_number);
    A = matrix2D_construct(A_row, A_column);
    B = matrix2D_construct(B_row, B_column);
    matrix2D_fillwith(A, A_number);
    matrix2D_fillwith(B, B_number);
    matrix2D* C = matrix2D_multiple(A, B);
    if (C) {
        print_matrix(C);
    }
    return 0;
}
