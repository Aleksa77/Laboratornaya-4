#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student {

	char* surname;
	char* name;
	unsigned int age;
	char* group;
	int* tel;
	int lenTel;
	int* ratings;
	int lenRat;	
	int count;
	struct Student* next;
} ST;

void addStud(ST** st, char* surname, char* name,
	unsigned int age, char* group, int* num, int* rating);
void full(ST** st, char* surname, char* name,
	unsigned int age, char* group, int* num, int* rating);

void outputST(ST* st);
void outputGoodST(ST* st);
void outputSurnameST(ST* st);
void outputOneGroupST(ST* st);
void deleteLastST(ST** st);
int deleteByIndex(ST** st, unsigned int index);
void deleteBadProgress(ST** st);
void freeST(ST* st);