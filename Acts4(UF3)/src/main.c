/*
 * main.c
 *
 *  Created on: 22 abr. 2021
 *      Author: Helios
 */

#include <stdio.h>
#include "library.h"

void main(){
	char fileName[500];
	char ans = 'y';
	char fileLocation[500]= "F:/Helios/PG/PG-UF3/Acts4(UF3)/files/";
	ask_name(fileName);
	verify(fileName);
	location(fileName, fileLocation);
	if(existsFile(fileLocation)){
		printf("El fitxer ja existeix, vols sobreescriure'l? (y/n): ");
		fflush(stdout);
		fflush(stdin);
		ans = getchar();
	}
	if(ans=='y'){
		createFile(fileName, fileLocation);
	}
}
