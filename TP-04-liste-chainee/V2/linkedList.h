#pragma once

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef void *Element;

typedef struct Node
{
  Element element;
  struct Node *next;
} Node;

typedef Node *List;

bool isEmpty(List l);

List create(Element e);

List addHead(Element e, List l);

extern void showElement(Element e);

void showList_i(List l);

void showList_r(List l);

extern void destroyElement(Element e);

void destroyList_i(List l);

void destroyList_r(List l);

List addTail_i(Element e, List l);

List addTail_r(Element e, List l);

extern bool equalsElement(Element e1, Element e2);

List search_i(Element e, List l);

List search_r(Element e, List l);

List removeFirst_i(Element e, List l);

List removeFirst_r(Element e, List l);

void showListReverse_r(List l);
