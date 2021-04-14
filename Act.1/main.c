/*
 * main.c
 *
 *  Created on: 12 d’abr. 2021
 *      Author: alumne_1r
 */


#include <stdio.h>
#include <stdlib.h>

void main(){
	FILE *file;
	char name[100];
	file=fopen("nombres.txt","a");
	if (file == 0) {
		perror("Error: ");
		exit(0);
	}
	else {
		printf("¿Cual es tu nombre?: ");
		fflush(stdout);
		scanf("%s", name);
		fprintf(file, "%s\n", name);
	}
	fclose(file);
}
