#include "linkedListOfMusic.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 500

Element createNewMusic(char *name, char *artist, char *album, char *genre, int discNumber, int trackNumber, int year)
{
  Element e = malloc(sizeof(Music));
  e->name = malloc(sizeof(char) * (strlen(name) + 1));
  strcpy(e->name, name);
  e->artist = malloc(sizeof(char) * (strlen(artist) + 1));
  strcpy(e->artist, artist);
  e->album = malloc(sizeof(char) * (strlen(album) + 1));
  strcpy(e->album, album);
  e->genre = malloc(sizeof(char) * (strlen(genre) + 1));
  strcpy(e->genre, genre);
  e->discNumber = discNumber;
  e->trackNumber = trackNumber;
  e->year = year;
  return e;
}

List readMusics(char *sourceFilename)
{
  List l = NULL;
  FILE *sourceFile = fopen(sourceFilename, "r");

  char buffer[BUFFER_SIZE];
  size_t len;

  if (sourceFile == NULL)
  {
    fprintf(stderr, "Impossible d'ouvrir le fichier %s", sourceFilename);
    exit(EXIT_FAILURE);
  }

  int numberOfMusics = 0;
  while (fgets(buffer, BUFFER_SIZE, sourceFile) != NULL)
  {
    numberOfMusics++;
  }

  rewind(sourceFile);

  for (int i = 0; i < numberOfMusics; i++)
  {
    fgets(buffer, BUFFER_SIZE, sourceFile);
    buffer[(len = strcspn(buffer, "\n"))] = 0;

    if (i == 0)
      continue;

    char *buffer_p = buffer;

    char *name = strsep(&buffer_p, ",");
    char *artist = strsep(&buffer_p, ",");
    char *album = strsep(&buffer_p, ",");
    char *genre = strsep(&buffer_p, ",");
    int discNumber = atoi(strsep(&buffer_p, ","));
    int trackNumber = atoi(strsep(&buffer_p, ","));
    int year = atoi(strsep(&buffer_p, ","));

    Element e = createNewMusic(name, artist, album, genre, discNumber, trackNumber, year);
    l = addTail_i(e, l);
  }

  fclose(sourceFile);
  return l;
}

void swap(Element *a, Element *b)
{
  Element temp = *a;
  *a = *b;
  *b = temp;
}

List bubbleSort(List l)
{
  int swapped;
  List listA;
  List listB = NULL;

  if (l == NULL)
    return NULL;

  do
  {
    swapped = 0;
    listA = l;

    while (listA->next != listB)
    {
      if (listA->element->year > listA->next->element->year)
      {
        swap(&listA->element, &listA->next->element);
        swapped = 1;
      }
      listA = listA->next;
    }
    listB = listA;
  } while (swapped);

  return l;
}

int main()
{
  List musicsList = readMusics("music.csv");
  // showList_r(musicsList);

  List sortedMusicsList = bubbleSort(musicsList);
  showList_i(sortedMusicsList);
  return 0;
}
