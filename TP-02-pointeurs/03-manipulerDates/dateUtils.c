#include <stdio.h>
#include <stdlib.h>

#include "dateUtils.h"

void afficheDate(Date *date)
{
  printf("Date: %d/%d/%d\n", date->jour, date->mois, date->annee);
}

void initialiseDate(Date *date)
{
  printf("\nCreation d'une date\n");
  printf("Jour : ");
  scanf("%d", &date->jour);
  printf("Mois : ");
  scanf("%d", &date->mois);
  printf("Annee : ");
  scanf("%d", &date->annee);
}

Date creerDateParCopie(void)
{
  printf("\nCreation d'une date par copie\n");
  Date date;
  printf("Jour : ");
  scanf("%d", &date.jour);
  printf("Mois : ");
  scanf("%d", &date.mois);
  printf("Annee : ");
  scanf("%d", &date.annee);
  return date;
}

Date *newDate(void)
{
  printf("\nCreation d'une date en utilisant malloc\n");
  Date *date = malloc(sizeof(Date));
  printf("Jour : ");
  scanf("%d", &date->jour);
  printf("Mois : ");
  scanf("%d", &date->mois);
  printf("Annee : ");
  scanf("%d", &date->annee);
  return date;
}