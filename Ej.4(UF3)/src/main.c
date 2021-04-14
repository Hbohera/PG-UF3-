/*
 * main.c
 *
 *  Created on: 8 d’abr. 2021
 *      Author: alumne_1r
 */


#include <stdio.h>
#include <stdlib.h>

#define PERCENTAGE 100
#define PENALTY 2

void main(){
	FILE *file;
	float price, finalprice;
	int discount;
	printf("Introduce el precio del producto: ");
	fflush(stdout);
	scanf("%f",&price);
	printf("Introduce el porcentaje del descuento: ");
	fflush(stdout);
	scanf("%d",&discount);
	if(price >= PERCENTAGE) {
		finalprice=((price)-(price*discount/PERCENTAGE));
		printf("%.2f",finalprice);
		fflush(stdout);
	}
	else {
		if(price < 30) {
			finalprice=((price)+(price*PENALTY/PERCENTAGE));
			printf("%.2f €",finalprice);
			fflush(stdout);
		}
		else {
			printf("%.2f €",price);
			fflush(stdout);
		}
	}
	file=fopen("document.txt","a");
	if (file == 0) {
			perror("Error: ");
			exit(0);
	}
	else {
		fprintf(file, "\n|  %.2f €  |  %d %  |  %.2f €  |", price, discount, finalprice);
	}
	fclose(file);
}
