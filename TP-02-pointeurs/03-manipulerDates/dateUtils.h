#pragma once

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

void afficheDate(Date *date);

void initialiseDate(Date *date);

Date creerDateParCopie(void);

Date *newDate(void);