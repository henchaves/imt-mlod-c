#include <stdio.h>
#include <stdint.h>
#include "matrixUtils.h"

void matrix_mult(int64_t *finalMatrix, int64_t *matrixA, int64_t *matrixB)
{
  int numberRows = sizeof(matrixB) / sizeof(matrixB[0]);
  int numberColumns = sizeof(matrixA[0]) / sizeof(matrixA[0][0]);

  if (numberColumns != numberRows)
  {
    printf("Les matrices ne peuvent pas être multipliées");
    return;
  }

  for (int i = 0; i < numberRows; i++)
  {
    for (int j = 0; j < numberColumns; j++)
    {
      for (int k = 0; k < numberColumns; k++)
      {
        finalMatrix[i][j] += matrixA[i][k] * matrixB[k][j];
      }
    }
  }
}

void matrix_print(int64_t *matrix)
{
  int numberColumns = sizeof(matrix[0]) / sizeof(matrix[0][0]);
  int numberRows = sizeof(matrix) / sizeof(matrix[0]);

  printf("Matrix: %d x %d", numberRows, numberColumns);
  for (int i = 0; i < numberRows; i++)
  {
    for (int j = 0; j < numberColumns; j++)
    {
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}
