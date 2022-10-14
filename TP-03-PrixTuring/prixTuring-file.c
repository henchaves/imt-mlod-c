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

	unsigned int bufferMaxSize = 250;
	char buffer[bufferMaxSize];
	size_t len;

	if (sourceFile == NULL)
	{
		fprintf(stderr, "Impossible d'ouvrir le fichier %s", sourceFilename);
		exit(EXIT_FAILURE);
	}
	else
	{
		// Size
		fgets(buffer, bufferMaxSize, sourceFile);
		buffer[(len = strcspn(buffer, "\n"))] = 0;
		winners->size = atoi(buffer);
		winners->winners = calloc(winners->size, sizeof(Winner));

		for (int i = 0; i < winners->size; i++)
		{
			// Year
			fgets(buffer, bufferMaxSize, sourceFile);
			buffer[(len = strcspn(buffer, "\n"))] = 0;
			winners->winners[i].year = atoi(buffer);

			// Name
			fgets(buffer, bufferMaxSize, sourceFile);
			buffer[(len = strcspn(buffer, "\n"))] = 0;
			winners->winners[i].name = malloc((len + 1) * sizeof(char));
			strcpy(winners->winners[i].name, buffer);

			// Title
			fgets(buffer, bufferMaxSize, sourceFile);
			buffer[(len = strcspn(buffer, "\n"))] = 0;
			winners->winners[i].title = malloc((len + 1) * sizeof(char));
			strcpy(winners->winners[i].title, buffer);
		}
		fclose(sourceFile);
	}

	return winners;
}

void sortByYear(Winners *winners)
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

int main(int argc, char *argv[])
{
	// printf("Nombre d'arguments : %d\n", argc);
	// printf("Nom du programme : %s\n", argv[0]);
	// printf("Nom du fichier source : %s\n", argv[1]);
	// printf("Nom du fichier cible : %s\n", argv[2]);

	if (argc >= 3)
	{
		Winners *winners = readWinners(argv[1]);
		printWinners(winners, argv[2]);

		if (argc == 4)
		{
			if (strcmp(argv[3], "sort") == 0)
			{
				sortByYear(winners);
				printWinners(winners, argv[2]);
			}
			else if (strcmp(argv[3], "addNewWinner") == 0)
			{
				// TODO
			}
			else
			{
				fprintf(stderr, "Commande inconnue : %s", argv[3]);
				exit(EXIT_FAILURE);
			}
		}

		return EXIT_SUCCESS;
	}
	else
	{
		printf("Usage: %s sourceFilename targetFilename [method]", argv[0]);
		return EXIT_FAILURE;
	}
}
