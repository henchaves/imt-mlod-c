/**
 Compilation
 gcc --std=c99 -W -Wall -o prixTuring prixTuring.c

 Exécution
 ./prixTuring < turingWinners.txt > out.txt

 Tests
 diff out.txt turingWinners.txt

 Détection de fuites mémoires
 valgrind --leak-check=yes --leak-check=full --show-leak-kinds=all --show-reachable=no ./prixTuring < turingWinners.txt > out.txt
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* This function scans a line of text (until \n) and returns a char* that contains all characters on the line (up to 255) excluding \n.
It also ensures the \0 termination.
**WARNING**: The result of this function has been allocated (calloc) by the function */
char *scanLine()
{
	int maxLineSize = 255;
	char c, *line = calloc(maxLineSize + 1, sizeof(char));

	scanf("%250[^\n]", line);

	if ((c = getchar()) != '\n')
	{
		/* we did not get all the line */
		line[250] = '[';
		line[251] = line[252] = line[253] = '.';
		line[254] = ']';
		// line[255] = '\0'; // useless because already initialized by calloc

		// let's skip all chars untli the end of line
		while (((c = getchar()) != '\n') && c != EOF)
			;
	}

	return line;
}

/* This function scans a line of text (until \n), converts it as an integer and returns this integer */
int scanLineAsInt()
{
	int buf;
	scanf("%i\n", &buf);
	return buf;
}

typedef struct
{
	int year;
	char *name;
	char *title;
} Winner;

typedef struct
{
	int size;
	Winner *winners;
} Winners;

void printWinners(Winners *winners)
{
	printf("%d\n", winners->size);

	for (int i = 0; i < winners->size; i++)
	{
		printf("%d\n", winners->winners[i].year);
		printf("%s\n", winners->winners[i].name);
		printf("%s\n", winners->winners[i].title);
	}
}

Winners *readWinners(void)
{
	Winners *winners = malloc(sizeof(Winners));
	winners->size = scanLineAsInt();
	winners->winners = calloc(winners->size, sizeof(Winner));

	for (int i = 0; i < winners->size; i++)
	{
		winners->winners[i].year = scanLineAsInt();
		winners->winners[i].name = scanLine();
		winners->winners[i].title = scanLine();
	}

	return winners;
}

void infosAnnee(int year, Winners *winners)
{
	for (int i = 0; i < winners->size; i++)
	{
		if (winners->winners[i].year == year)
		{
			printf("L'annee %d, le(s) ganant(s) ont été : %s)\n", year, winners->winners[i].name);
			printf("Nature des travaux : %s\n", winners->winners[i].title);
			return;
		}
	}

	printf("Pas de gagnant pour cette annee\n");
}

int main(int argc, char *argv[])
{
	Winners *winners = readWinners();

	switch (argc)
	{
	case 1:
		printWinners(winners);
		break;
	case 3:
		infosAnnee(atoi(argv[2]), winners);
		break;
	default:
		printf("Not implemented yet");
	}
}
