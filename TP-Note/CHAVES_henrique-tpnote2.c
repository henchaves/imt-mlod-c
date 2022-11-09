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

int main()
{
  String s = string_new("HELLO !");
  unsigned int size = string_size(s);
  printf("%s", s->chunk);
  printf("%d", size);
}
