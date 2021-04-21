/*
 * functions.c
 *
 *  Created on: 22 abr. 2021
 *      Author: Helios
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"

void ask_name(char *fileName) {
	printf("Com és el nom del fitxer?: ");
	fflush(stdout);
	scanf("%s", fileName);
}

void verify(char *fileName) {
	char subname[7];
	int i, j, y= 0;
	int len= strlen(fileName);
	while(strcmp(subname, ".txt") != 0) {
		printf("\n\n%s\n\n", fileName);
		fflush(stdout);
		for(i=0; i < len; i++) {
			if(fileName[i] == '.') {
				for(j=i; j < len; j++) {
					subname[y]= fileName[j];
					y++;
				}
			}
		}
		printf("\n\n%s\n\n", subname);
		fflush(stdout);
		if (strcmp(subname, ".txt") != 0) {
			printf("Torna a introduir el nom del fitxer amb .txt al final: ");
			fflush(stdout);
			scanf("%s", fileName);
		}
		i= 0, y= 0, j= 0;
	}
}

int existsFile(char *fileName){
	FILE *pf = NULL;
	int exists = 0;

	if((pf = fopen(fileName,"r"))!=NULL){
		exists = 1;
		fclose(pf);
	}

	return exists;
}

void location(char *fileName, char *fileLocation){
	strcat(fileLocation, fileName);
}

void createFile(char *fileName, char *fileLocation){
	FILE *pf = NULL;
	struct registry reg;
	int y= 0;
	char ans;
	if((pf=fopen(fileLocation,"w"))==NULL){
		perror("\nError: ");
		exit(1);
	}
	do{
		printf("Nom: ");
		fflush(stdout);
		fflush(stdin);
		gets(reg.name);
		printf("Adreça: ");
		fflush(stdout);
		gets(reg.address);
		printf("Telèfon: ");
		fflush(stdout);
		scanf("%ld", &reg.phoneNumber);
		fflush(stdin);
		fprintf(pf,"%s %s %ld \n", reg.name, reg.address, reg.phoneNumber);
		if(ferror(pf)){
			perror("Error: ");
			exit(2);
		}
		printf("Vols afegir un altre registre? (y/n): ");
		fflush(stdout);
		fflush(stdin);
		ans = getchar();
		y++;
	} while (ans == 'y');
}
