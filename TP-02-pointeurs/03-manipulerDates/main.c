#include <stdio.h>
#include <stdlib.h>
#include "dateUtils.h"

int main(void)
{
  Date d1;
  initialiseDate(&d1);
  afficheDate(&d1);

  Date d2;
  d2 = creerDateParCopie();
  afficheDate(&d2);

  Date *d3;
  d3 = newDate();
  afficheDate(d3);
  free(d3);

  return 0;
}
