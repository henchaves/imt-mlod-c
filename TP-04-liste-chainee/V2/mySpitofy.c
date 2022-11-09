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

List readMusics(char *sourceFilename, int numberOfMusics)
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

    l = addHead(e, l);
  }

  fclose(sourceFile);
  return l;
}

int main()
{
  List l = readMusics("music.csv", 10);
  showList_r(l);
  return 0;
}
