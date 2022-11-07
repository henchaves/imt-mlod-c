/* Henrique CHAVES */

#include <stdio.h>
#include <stdlib.h>

void repeat(int *t1, int *t2, int size)
{
  int count = 0;
  for (int i = 0; i < size; i++)
  {
    count += t1[i];
  }
  int *t3 = malloc(count * sizeof(int));

  int index = 0;

  for (int i = 0; i < size; i++)
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
  int t1[] = {1, 2, 4};
  int t2[] = {10, 3, 8};

  int arraySize = sizeof t1 / sizeof t1[0];

  repeat(t1, t2, arraySize);
  return 0;
}
