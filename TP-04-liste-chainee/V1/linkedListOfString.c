// gcc -W -Wall -Wno-unused-parameter -std=c99 linkedList.c linkedListOfString.c -o linkedListOfString

#include "linkedList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void showElement(Element e)
{
  printf("%s ", e);
}

void destroyElement(Element e)
{
  free(e);
}

bool equalsElement(Element e1, Element e2)
{
  return strcmp(e1, e2) == 0;
}

int main()
{
  List l;
  l = NULL;
  printf("isEmpty(l) = %s\n", isEmpty(l) ? "TRUE" : "FALSE");
  l = addHead("!", l);
  l = addHead("!", l);
  l = addHead("!", l);
  l = addHead("Jedi", l);
  l = addHead("est", l);
  l = addHead("un", l);
  l = addHead("Luke", l);
  showList_i(l);
  destroyList_r(l);
  return 0;
}
