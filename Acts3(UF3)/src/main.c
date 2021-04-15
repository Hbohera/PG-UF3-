/*
 * main.c
 *
 *  Created on: 14 d’abr. 2021
 *      Author: alumne_1r
 */

#include "functions.h"
#include <stdio.h>
#include <stdlib.h>

void main() {
	int option;
	printf("___________________________________________\n|MENÚ DE OPCIONES\t\t\t  |\n|1. Crear un fichero\t\t\t  |\n|2. Mostrar el contenido del fichero      |\n|3. Modificar el contenido del fichero    |\n|4. Salir\t\t\t\t  |\n|_________________________________________|");
	fflush(stdout);
	printf("\n¿Que opción quieres?: ");
	fflush(stdout);
	scanf("%d", &option);
	option= verify(option);
	switch(option) {
	case 1:
		ask_name(name);
		create(name);
		break;
	case 2:
		ask_name(name);
		print(name);
		break;
	case 3:
		ask_name(name);
		modify(name);
		break;
	case 4:
		printf("\nHas salido del programa");
		fflush(stdout);
		exit(0);
		break;
	}
}
