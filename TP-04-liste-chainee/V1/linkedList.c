#include "linkedList.h"
#include <stdlib.h>
#include <stdio.h>

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
  printf("%i ", e);
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
  // nothing to do
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
  return e1 == e2;
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
    l->next = retirePremier_r(e, l->next);
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
