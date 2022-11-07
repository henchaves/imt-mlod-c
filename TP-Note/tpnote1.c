/* Henrique CHAVES */

#include <stdio.h>
#include <stdlib.h>

#define SIZE 3

void repeat(int *t1, int *t2)
{
  int count = 0;

  for (int i = 0; i < SIZE; i++)
  {
    count += t1[i];
  }

  int *t3 = malloc(count * sizeof(int));

  int index = 0;

  for (int i = 0; i < SIZE; i++)
  {
    for (int j = 0; j < t1[i]; j++)
    {
      t3[index] = t2[i];
      index++;
    }
  }

  for (int i = 0; i < count; i++)
  {
    printf("%d ", t3[i]);
  }
  printf("\n");
}

int main()
{
  int t1[SIZE] = {1, 2, 4};
  int t2[SIZE] = {10, 3, 8};
  repeat(t1, t2);
  return 0;
}
