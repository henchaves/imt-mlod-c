/**
 Compilation
 gcc --std=c99 -W -Wall -o prixTuring prixTuring.c

 Exécution
 ./prixTuring turingWinners.txt out.txt

 Tests
 diff out.txt turingWinners.txt

 Détection de fuites mémoires
 valgrind --leak-check=yes --leak-check=full --show-leak-kinds=all --show-reachable=no ./prixTuring < turingWinners.txt > out.txt
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BUFFER_SIZE 250

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

void printWinners(Winners *winners, char *targetFilename)
{
	FILE *targetFile = fopen(targetFilename, "w");
	if (targetFile == NULL)
	{
		fprintf(stderr, "Impossible d'ouvrir le fichier %s", targetFilename);
		exit(EXIT_FAILURE);
	}

	fprintf(targetFile, "%d\n", winners->size);

	for (int i = 0; i < winners->size; i++)
	{
		fprintf(targetFile, "%d\n", winners->winners[i].year);
		fprintf(targetFile, "%s\n", winners->winners[i].name);
		fprintf(targetFile, "%s\n", winners->winners[i].title);
	}

	fclose(targetFile);
}

Winners *readWinners(char *sourceFilename)
{
	Winners *winners = malloc(sizeof(Winners));
	FILE *sourceFile = fopen(sourceFilename, "r");

	char buffer[BUFFER_SIZE];
	size_t len;

	if (sourceFile == NULL)
	{
		fprintf(stderr, "Impossible d'ouvrir le fichier %s", sourceFilename);
		exit(EXIT_FAILURE);
	}
	else
	{
		// Size
		fgets(buffer, BUFFER_SIZE, sourceFile);
		buffer[(len = strcspn(buffer, "\n"))] = 0;
		winners->size = atoi(buffer);
		winners->winners = calloc(winners->size, sizeof(Winner));

		for (int i = 0; i < winners->size; i++)
		{
			fgets(buffer, BUFFER_SIZE, sourceFile);
			buffer[(len = strcspn(buffer, "\n"))] = 0;
			winners->winners[i].year = atoi(buffer);

			fgets(buffer, BUFFER_SIZE, sourceFile);
			buffer[(len = strcspn(buffer, "\n"))] = 0;
			winners->winners[i].name = malloc((len + 1) * sizeof(char));
			strcpy(winners->winners[i].name, buffer);

			fgets(buffer, BUFFER_SIZE, sourceFile);
			buffer[(len = strcspn(buffer, "\n"))] = 0;
			winners->winners[i].title = malloc((len + 1) * sizeof(char));
			strcpy(winners->winners[i].title, buffer);
		}
		fclose(sourceFile);
	}

	return winners;
}

void sortTuringWinnersByYear(Winners *winners)
{
	for (int i = 0; i < winners->size; i++)
	{
		for (int j = i + 1; j < winners->size; j++)
		{
			if (winners->winners[i].year > winners->winners[j].year)
			{
				Winner tmp = winners->winners[i];
				winners->winners[i] = winners->winners[j];
				winners->winners[j] = tmp;
			}
		}
	}
}

void addNewWinner(Winners *winners)
{
	char buffer[BUFFER_SIZE];
	size_t len;

	winners->winners = realloc(winners->winners, (winners->size + 1) * sizeof(Winner));

	printf("Entrer une année: ");
	fgets(buffer, BUFFER_SIZE, stdin);
	buffer[(len = strcspn(buffer, "\n"))] = 0;
	winners->winners[winners->size].year = atoi(buffer);

	printf("Entrer le(s) gagnant(s): ");
	fgets(buffer, BUFFER_SIZE, stdin);
	buffer[(len = strcspn(buffer, "\n"))] = 0;
	winners->winners[winners->size].name = malloc((len + 1) * sizeof(char));
	strcpy(winners->winners[winners->size].name, buffer);

	printf("Nature des travaux: ");
	fgets(buffer, BUFFER_SIZE, stdin);
	buffer[(len = strcspn(buffer, "\n"))] = 0;
	winners->winners[winners->size].title = malloc((len + 1) * sizeof(char));
	strcpy(winners->winners[winners->size].title, buffer);

	winners->size++;
}

int main(int argc, char *argv[])
{
	if (argc >= 3)
	{
		Winners *winners = readWinners(argv[1]);
		printWinners(winners, argv[2]);

		if (argc == 4)
		{
			if (strcmp(argv[3], "sort") == 0)
			{
				sortTuringWinnersByYear(winners);
				printWinners(winners, argv[2]);
			}
			else if (strcmp(argv[3], "addNewWinner") == 0)
			{
				addNewWinner(winners);
				printWinners(winners, argv[2]);
			}
			else
			{
				fprintf(stderr, "Commande inconnue : %s\n", argv[3]);
				return EXIT_FAILURE;
			}
		}

		for (int i = 0; i < winners->size; i++)
		{
			free(winners->winners[i].name);
			free(winners->winners[i].title);
		}
		free(winners->winners);
		free(winners);

		return EXIT_SUCCESS;
	}
	else
	{
		fprintf(stderr, "Usage: %s sourceFilename targetFilename [sort|addNewWinner]", argv[0]);
		return EXIT_FAILURE;
	}
}
