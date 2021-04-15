/*
 * functions.c
 *
 *  Created on: 14 d’abr. 2021
 *      Author: alumne_1r
 */

#include <stdio.h>
#include <stdlib.h>

void ask_name(char *name) {
	printf("¿Cual es el nombre del fichero?: ");
	fflush(stdout);
	scanf("%s", name);
}

void create(char *name) {
	FILE *file;
	file=fopen(name, "a");
	if (file == 0) {
		perror("Error");
		exit(0);
	}
	fclose(file);
}

void print (char *name) {
	FILE *file;
	char c;
	fflush(stdout);
	file=fopen(name, "r");
	if (file == 0) {
		perror("Error");
		exit(0);
	}
	else {
		c = fgetc(file);
		while (c != EOF) {
			printf ("%c", c);
			c = fgetc(file);
		};
	}
	fclose(file);
}

void modify(char *name) {
	FILE *file;
	char modifier[1000];
	fflush(stdout);
	file=fopen(name, "w");
	if (file == 0) {
		perror("Error");
		exit(0);
	}
	else {
		printf("El fichero esta listo para modificarlo: ");
		fflush(stdout);
		fscanf(file, "%s", modifier);
		fprintf(file, "%s", modifier);
		fflush(stdout);
	}
	fclose(file);
}

int verify(int option) {
	while(option < 0 || option > 4) {
		printf("Introduce el número de nuevo: ");
		fflush(stdout);
		scanf("%d", &option);
	}
	return option;
}
