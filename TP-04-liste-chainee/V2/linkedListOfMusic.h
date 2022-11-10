#pragma once
#include "linkedList.h"
#define BUFFER_SIZE 500

typedef struct Music
{
  char *name;
  char *artist;
  char *album;
  char *genre;
  int discNumber;
  int trackNumber;
  int year;
} Music;

Music *createNewMusic(char *name, char *artist, char *album, char *genre, int discNumber, int trackNumber, int year);

List readMusics(char *sourceFilename);

void swap(Music **a, Music **b);

List bubbleSortByYear(List l);