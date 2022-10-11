#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>

typedef unsigned long long TypeEntier;

TypeEntier factorielle(TypeEntier number) {
    if (number == 0) return 1;
    return number * factorielle(number-1);
}


int main (void) {
    TypeEntier max_number = 15;

    for (TypeEntier i = 0; i <= max_number; i++) {
        TypeEntier result = factorielle(i);
        printf("Factorielle du %d est %d\n", i, result);
    }

    return 0;
}