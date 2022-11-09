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

String string_new(char string[CHUNK_SIZE_MAX])
{
  int stringSize = strlen(string);
  if (stringSize > CHUNK_SIZE_MAX)
    stringSize = CHUNK_SIZE_MAX;

  String newString = malloc(sizeof(Chunk));
  newString->chunkSize = stringSize;
  newString->next = NULL;
  newString->chunk = malloc(stringSize * sizeof(char));
  for (int i = 0; i < stringSize; i++)
    newString->chunk[i] = string[i];
  return newString;
}

int main()
{
  String s = string_new("HELLO !");
  printf("%s", s->chunk);
}
