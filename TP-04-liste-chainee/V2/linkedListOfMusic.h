#pragma once

#include <stdbool.h>

typedef Music Element;

typedef struct
{
  char *name;
  char *artist;
  char *album;
  char *genre;
  int discNumber;
  int trackNumber;
  int year;
} Music;

typedef struct Node
{
  Element element;
  struct Node *next;
} Node;

typedef Node *List;

bool isEmpty(List l);

List create(Element e);

List addHead(Element e, List l);

void showElement(Element e);

void showList_i(List l);

void showList_r(List l);

void destroyElement(Element e);

void destroyList_i(List l);

void destroyList_r(List l);

List addTail_i(Element e, List l);

List addTail_r(Element e, List l);

bool equalsElement(Element e1, Element e2);

List search_i(Element e, List l);

List search_r(Element e, List l);

List removeFirst_i(Element e, List l);

List removeFirst_r(Element e, List l);

void showListReverse_r(List l);
