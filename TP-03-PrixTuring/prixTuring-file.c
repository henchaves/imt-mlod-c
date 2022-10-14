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

#define MAX_LINE_LENGTH 255

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
		printf("%d\n", winners->winners[i].year);
		fprintf(targetFile, "%d\n", winners->winners[i].year);

		printf("%s\n", winners->winners[i].name);
		fprintf(targetFile, "%s\n", winners->winners[i].name);

		printf("%s\n", winners->winners[i].title);
		fprintf(targetFile, "%s\n", winners->winners[i].title);
	}

	fclose(targetFile);
}

Winners *readWinners(char *sourceFilename)
{
	Winners *winners = malloc(sizeof(Winners));
	FILE *sourceFile = fopen(sourceFilename, "r");
	char line[MAX_LINE_LENGTH] = {0};

	if (sourceFile == NULL)
	{
		fprintf(stderr, "Impossible d'ouvrir le fichier %s", sourceFilename);
		exit(EXIT_FAILURE);
	}
	else
	{
		fgets(line, MAX_LINE_LENGTH, sourceFile);
		winners->size = atoi(line);
		winners->winners = calloc(winners->size, sizeof(Winner));

		for (int i = 0; i < winners->size; i++)
		{
			fgets(line, MAX_LINE_LENGTH, sourceFile);
			winners->winners[i].year = atoi(line);

			fgets(line, MAX_LINE_LENGTH, sourceFile);
			if (line[strlen(line) - 1] == '\n')
				line[strlen(line) - 1] = '\0';
			winners->winners[i].name = calloc(strlen(line), sizeof(char));
			strcpy(winners->winners[i].name, line);

			fgets(line, MAX_LINE_LENGTH, sourceFile);
			if (line[strlen(line) - 1] == '\n')
				line[strlen(line) - 1] = '\0';
			winners->winners[i].title = calloc(strlen(line), sizeof(char));
			strcpy(winners->winners[i].title, line);
		}

		fclose(sourceFile);
	}

	return winners;
}

int main(int argc, char *argv[])
{
	// printf("Nombre d'arguments : %d\n", argc);
	// printf("Nom du programme : %s\n", argv[0]);
	// printf("Nom du fichier source : %s\n", argv[1]);
	// printf("Nom du fichier cible : %s\n", argv[2]);

	Winners *winners = readWinners(argv[1]);
	printWinners(winners, argv[2]);
	return EXIT_SUCCESS;
}
