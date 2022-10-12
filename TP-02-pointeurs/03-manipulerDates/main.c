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

Date creerDateParCopie(void)
{
  Date date;
  printf("Jour : ");
  scanf("%d", &date.jour);
  printf("Mois : ");
  scanf("%d", &date.mois);
  printf("Annee : ");
  scanf("%d", &date.annee);
  return date;
}

int main(void)
{
  Date d1;
  initialiseDate(&d1);
  afficheDate(&d1);

  Date d2;
  d2 = creerDateParCopie();
  afficheDate(&d2);

  return 0;
}
