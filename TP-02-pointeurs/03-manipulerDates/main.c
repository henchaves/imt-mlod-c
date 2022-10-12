#include <stdio.h>
#include <stdlib.h>

typedef enum
{
  JANVIER = 1,
  FEVRIER,
  MARS,
  AVRIL,
  MAI,
  JUIN,
  JUILLET,
  AOUT,
  SEPTEMBRE,
  OCTOBRE,
  NOVEMBRE,
  DECEMBRE
} Mois;

typedef struct
{
  int jour;
  Mois mois;
  int annee;
} Date;

void initialiseDate(Date *date)
{
  printf("Jour : ");
  scanf("%d", &date->jour);
  printf("Mois : ");
  scanf("%d", &date->mois);
  printf("Annee : ");
  scanf("%d", &date->annee);
}

void afficheDate(Date *date)
{
  printf("Date: %d/%d/%d\n", date->jour, date->mois, date->annee);
}

int main(void)
{
  Date d;
  initialiseDate(&d);
  afficheDate(&d);
  return 0;
}
