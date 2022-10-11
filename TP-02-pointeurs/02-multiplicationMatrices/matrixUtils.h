#pragma once
#include <stdint.h>

#define SIZE 5

void matrix_mult(int64_t finalMatrix[SIZE][SIZE], int64_t matrixA[SIZE][SIZE], int64_t matrixB[SIZE][SIZE]);

void matrix_print(int64_t matrix[SIZE][SIZE]);