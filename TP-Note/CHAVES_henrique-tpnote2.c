#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define CHUNK_SIZE_MAX 5

typedef struct Chunk
{
  int chunkSize;
  char *chunk;
  struct Chunk *next;
} Chunk;

typedef Chunk *String;

String string_new(char *string)
{
  String stringList = malloc(sizeof(Chunk));
  String stringListHead = stringList;
  int numberOfChunks = strlen(string) / CHUNK_SIZE_MAX;
  int lastChunkSize = strlen(string) % CHUNK_SIZE_MAX;
  if (lastChunkSize != 0)
    numberOfChunks++;

  for (int i = 0; i < numberOfChunks; i++)
  {
    if (i != 0)
    {
      stringList->next = malloc(sizeof(Chunk));
      stringList = stringList->next;
    }

    if (i != numberOfChunks - 1)
      stringList->chunkSize = CHUNK_SIZE_MAX;
    else
      stringList->chunkSize = lastChunkSize;

    stringList->chunk = calloc(stringList->chunkSize, sizeof(char));

    for (int j = 0; j < stringList->chunkSize; j++)
      stringList->chunk[j] = string[i * CHUNK_SIZE_MAX + j];
  }

  stringList->next = NULL;

  return stringListHead;
}

unsigned int string_size(String string)
{
  unsigned int size = 0;
  while (string != NULL)
  {
    size += string->chunkSize;
    string = string->next;
  }
  return size;
}

// String string_insert_at(String stringList, int index, char *stringToInsert)
// {
//   // recursive algorithm
//   index--;
//   if (index == 0)
//   {
//     String stringToInsertList = string_new(stringToInsert);
//     stringToInsertList->next = stringList;
//     return stringToInsertList;
//   }
//   else
//   {
//     stringList->next = string_insert_at(stringList->next, index, stringToInsert);
//     return stringList;
//   }
// }

int main()
{
  String s = string_new("HELLO !");
  unsigned int size = string_size(s);
  printf("%s", s->chunk);
  printf("%d", size);
}
