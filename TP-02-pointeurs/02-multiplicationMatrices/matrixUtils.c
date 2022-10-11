#include <stdio.h>
#include <stdint.h>
#include "matrixUtils.h"

#define SIZE 5

void matrix_mult(int64_t finalMatrix[SIZE][SIZE], int64_t matrixA[SIZE][SIZE], int64_t matrixB[SIZE][SIZE])
{
  for (int i = 0; i < SIZE; i++)
  {
    for (int j = 0; j < SIZE; j++)
    {
      for (int k = 0; k < SIZE; k++)
      {
        finalMatrix[i][j] += matrixA[i][k] * matrixB[k][j];
      }
    }
  }
}

void matrix_print(int64_t matrix[SIZE][SIZE])
{
  printf("Matrix: %d x %d\n", SIZE, SIZE);
  for (int i = 0; i < SIZE; i++)
  {
    for (int j = 0; j < SIZE; j++)
    {
      printf("%lld ", matrix[i][j]);
    }
    printf("\n");
  }
}
