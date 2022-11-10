#include "linkedListOfMusic.h"

void showElement(Element e)
{
  Music *m = (Music *)e;
  printf("------------------------\n");
  printf("Title: %s\n", m->name);
  printf("Artist: %s\n", m->artist);
  printf("Album: %s\n", m->album);
  printf("Genre: %s\n", m->genre);
  printf("Disc number: %d\n", m->discNumber);
  printf("Track number: %d\n", m->trackNumber);
  printf("Year: %d\n", m->year);
  printf("------------------------\n");
}

void destroyElement(Element e)
{
  Music *m = (Music *)e;
  free(m->name);
  free(m->artist);
  free(m->album);
  free(m);
}

bool equalsElement(Element e1, Element e2)
{
  Music *m1 = (Music *)e1;
  Music *m2 = (Music *)e2;

  if (strcmp(m1->name, m2->name) == 0 &&
      strcmp(m1->artist, m2->artist) == 0 &&
      strcmp(m1->album, m2->album) == 0 &&
      m1->discNumber == m2->discNumber &&
      m1->trackNumber == m2->trackNumber &&
      m1->year == m2->year)
  {
    return true;
  }
  else
  {
    return false;
  }
}

Music *createNewMusic(char *name, char *artist, char *album, char *genre, int discNumber, int trackNumber, int year)
{
  Music *e = malloc(sizeof(Music));
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

    Music *e = createNewMusic(name, artist, album, genre, discNumber, trackNumber, year);
    l = addTail_i(e, l);
  }

  fclose(sourceFile);
  return l;
}

void swap(Music **a, Music **b)
{
  Music *temp = *a;
  *a = *b;
  *b = temp;
}

List bubbleSortByYear(List l)
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
      if (((Music *)listA->element)->year > ((Music *)listA->next->element)->year)
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
