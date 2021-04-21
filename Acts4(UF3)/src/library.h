/*
 * library.h
 *
 *  Created on: 22 abr. 2021
 *      Author: Helios
 */

#ifndef LIBRARY_H_
#define LIBRARY_H_

struct registry{
	char name[100];
	char address[100];
	long phoneNumber;
};

void ask_name(char *);
int existsFile(char *);
void createFile(char *, char *);
void verify(char *);
void location(char *, char *);

#endif /* LIBRARY_H_ */
