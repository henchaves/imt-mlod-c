#include "linkedListOfMusic.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

bool isEmpty(List l)
{
  return l == NULL;
}

List create(Element e)
{
  List l = malloc(sizeof(Node));
  if (isEmpty(l))
  {
    fprintf(stderr, "Error: malloc failed");
    exit(EXIT_FAILURE);
  }
  l->element = e;
  l->next = NULL;
  return l;
}

List addHead(Element e, List l)
{
  List new = create(e);
  new->next = l;
  return new;
}

void showElement(Element e)
{
  printf("------------------------\n");
  printf("Title: %s\n", e->name);
  printf("Artist: %s\n", e->artist);
  printf("Album: %s\n", e->album);
  printf("Disc number: %d\n", e->discNumber);
  printf("Track number: %d\n", e->trackNumber);
  printf("Year: %d\n", e->year);
  printf("------------------------\n");
}

void showList_i(List l)
{
  while (!isEmpty(l))
  {
    showElement(l->element);
    l = l->next;
  }
  printf("\n");
}

void showList_r(List l)
{
  if (!isEmpty(l))
  {
    showElement(l->element);
    showList_r(l->next);
  }
  else
  {
    printf("\n");
  }
}

void destroyElement(Element e)
{
  free(e->name);
  free(e->artist);
  free(e->album);
  free(e);
}

void destroyList_i(List l)
{
  while (!isEmpty(l))
  {
    List tmp = l;
    l = l->next;
    destroyElement(tmp->element);
    free(tmp);
  }
}

void destroyList_r(List l)
{
  if (!isEmpty(l))
  {
    destroyList_r(l->next);
    destroyElement(l->element);
    free(l);
  }
}

List addTail_i(Element e, List l)
{
  if (isEmpty(l))
  {
    return create(e);
  }
  else
  {
    List tmp = l;
    while (!isEmpty(tmp->next))
    {
      tmp = tmp->next;
    }
    tmp->next = create(e);
    return l;
  }
}

List addTail_r(Element e, List l)
{
  if (isEmpty(l))
  {
    return create(e);
  }
  else
  {
    l->next = addTail_r(e, l->next);
    return l;
  }
}

bool equalsElement(Element e1, Element e2)
{
  if (strcmp(e1->name, e2->name) == 0 &&
      strcmp(e1->artist, e2->artist) == 0 &&
      strcmp(e1->album, e2->album) == 0 &&
      e1->discNumber == e2->discNumber &&
      e1->trackNumber == e2->trackNumber &&
      e1->year == e2->year)
  {
    return true;
  }
  else
  {
    return false;
  }
}

List search_i(Element e, List l)
{
  while (!isEmpty(l))
  {
    if (equalsElement(l->element, e))
      return l;
    l = l->next;
  }
  return NULL;
}

List search_r(Element e, List l)
{
  if (isEmpty(l))
    return NULL;
  else if (equalsElement(l->element, e))
    return l;
  else
    return search_r(e, l->next);
}

List removeFirst_i(Element e, List l)
{
  List search = search_i(e, l);
  if (equalsElement(l, search))
  {
    l = l->next;
    search->next = NULL;
    destroyList_i(search);
  }
  else if (!isEmpty(search))
  {
    List tmp = l;
    while (!equalsElement(tmp->next, search))
    {
      tmp = tmp->next;
    }
    tmp->next = search->next;
    search->next = NULL;
    destroyList_i(search);
  }
  return l;
}

List removeFirst_r(Element e, List l)
{
  if (isEmpty(l))
    return NULL;
  else if (equalsElement(l->element, e))
  {
    List tmp = l->next;
    l->next = NULL;
    destroyList_r(l);
    return tmp;
  }
  else
  {
    l->next = removeFirst_r(e, l->next);
    return l;
  }
}

void showListReverse_r(List l)
{
  if (!isEmpty(l))
  {
    showListReverse_r(l->next);
    showElement(l->element);
  }
}
