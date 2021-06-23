#include "students.h"

void full(ST** st, char* surname, char* name,
	unsigned int age, char* group, int* num, int* rating) {
	*st = (ST*)malloc(sizeof(ST*));
	(*st)->surname = (char*)malloc(sizeof(char));
	(*st)->name = (char*)malloc(sizeof(char));
	(*st)->group = (char*)malloc(sizeof(char));
	(*st)->surname = surname;
	(*st)->name = name;
	(*st)->age = age;
	(*st)->group = group;
	(*st)->lenTel = strlen(num);
	(*st)->tel = (int*)malloc(sizeof(int) * (*st)->lenTel);
	int number = atoi(num);
	for (int i = (*st)->lenTel - 1; i >= 0; --i) {
		(*st)->tel[i] = number % 10;
		number = number / 10;
	}
	(*st)->lenRat = strlen(rating);
	(*st)->ratings = (int*)malloc(sizeof(int) * (*st)->lenRat);
	int rat = atoi(rating);
	for (int i = (*st)->lenRat - 1; i >= 0; --i) {
		(*st)->ratings[i] = rat % 10;
		rat = rat / 10;
	}
}

void addStud(ST** st, char* surname, char* name,
	unsigned int age, char* group, int* num, int* rating) {
	if (*st == 0) {
		full(st, surname, name, age, group, num, rating);
		(*st)->count = 1;
		(*st)->next = 0;
	}
	else {
		ST* current = *st;
		while (current->next != 0) {
			current = current->next;
		}
		full(&(current->next), surname, name, age, group, num, rating);
		++(*st)->count;
		current->next->next = 0;
	}
	
}

void deleteLastST(ST** st) {
	ST* current = *st;
	if (current == 0)
		return;
	if (current->next == 0) {
		free(current);
		*st = 0;
		return;
	}
	while (current->next->next != 0)
		current = current->next;
	current->next = 0;
}

int deleteByIndex(ST** st, unsigned int index) {
	int position = 1;
	ST* current = *st;
	if (current == 0)
		return -1;
	if (index == 0) {
		current = current->next;
		free(*st);
		*st = current;
		return 0;
	}
	while ((current != 0) && (current->next != 0)  && (position != index - 1)) {
		current = current->next;
		++position;
	}
	if (position == (index - 1)) {
		if (current->next != 0) {
			printf("Deleting at %d student : %s\n", index, current->next->name);
			current->next = current->next->next;
		}
	}
	else {
		printf("Try to delete by wrong index %d\n", index);
		return -1;
	}
	return 0;
}

void deleteBadProgress(ST** st) {
	ST* current = *st;
	if (current == 0)
		return;
	int badRat;
	while (current->next != 0) {
		badRat = 0;
		for (int i = 0; i < current->next->lenRat; ++i) {
			badRat += current->next->ratings[i];
		}
		badRat /= current->next->lenRat;
		if (badRat > 3) current = current->next;
		else current->next = current->next->next;
	}
}

void outputST(ST* st) {
	printf("\nStudents:\n");
	while (st != 0) {
		printf("\nSurname: %s\n", st->surname);
		printf("Name: %s\n", st->name);
		printf("Age: %d\n", st->age);
		printf("Group: %s\n", st->group);
		printf("Number: ");
		for (int i = 0; i < st->lenRat; ++i) {
			printf("%d ", st->tel[i]);
		}
		printf("\nRatings: ");
		for (int i = 0; i < st->lenRat; ++i) {
			printf("%d ", st->ratings[i]);
		}
		printf("\n");
		st = st->next;
	}
}

void outputGoodST(ST* st) {
	printf("\nGood Students:\n");
	int ball;
	while (st != 0) {
		ball = 0;
		for (int i = 0; i < st->lenRat; ++i) {
			ball += st->ratings[i];
		}
		ball /= st->lenRat;
		if (ball > 3) {
			printf("\nSurname: %s\n", st->surname);
			printf("Name: %s\n", st->name);
			printf("Age: %d\n", st->age);
			printf("Group: %s\n", st->group);
			printf("Number: ");
			for (int i = 0; i < st->lenRat; ++i) {
				printf("%d ", st->tel[i]);
			}
			printf("\nRatings: ");
			for (int i = 0; i < st->lenRat; ++i) {
				printf("%d ", st->ratings[i]);
			}
			printf("\n");
			st = st->next;
		}
		else st = st->next;
	}
}

void outputSurnameST(ST* st) {
	printf("\nStudents with a last name beginning with Iv:\n");
	while (st != 0) {
		if ((st->surname[0] == 'I') && (st->surname[1] == 'v')) {
			printf("\nSurname: %s\n", st->surname);
			printf("Name: %s\n", st->name);
			printf("Age: %d\n", st->age);
			printf("Group: %s\n", st->group);
			printf("Number: ");
			for (int i = 0; i < st->lenRat; ++i) {
				printf("%d ", st->tel[i]);
			}
			printf("\nRatings: ");
			for (int i = 0; i < st->lenRat; ++i) {
				printf("%d ", st->ratings[i]);
			}
			printf("\n");
			st = st->next;
		}
		else st = st->next;
	}
}

void outputOneGroupST(ST* st) {
	printf("\nStudents from the same group:\n");
	ST* current = st;
	char** mass = (char**)malloc(sizeof(char*) * current->count);
	for (int i = 0; i < st->count; ++i) {
		mass[i] = (char*)malloc(sizeof(char));
		mass[i] = current->group;
		current = current->next;
	}
	current = st;
	int tmp = 0;
	for (int i = 0; i < st->count - 1; ++i) {
		for (int j = i + 1; j < st->count; ++j) {
			if (mass[i] == mass[j]) ++tmp;
		}
	}
	while (current != 0) {
		if (st->group == st->next->group) {
			printf("\nSurname: %s\n", st->surname);
			printf("Name: %s\n", st->name);
			printf("Age: %d\n", st->age);
			printf("Group: %s\n", st->group);
			printf("Number: ");
			for (int i = 0; i < st->lenRat; ++i) {
				printf("%d ", st->tel[i]);
			}
			printf("\nRatings: ");
			for (int i = 0; i < st->lenRat; ++i) {
				printf("%d ", st->ratings[i]);
			}
			printf("\n");
			st = st->next;
		}
		else st = st->next;
	}
}

void freeST(ST* st) {
	for (int i = 0; i < st->count; ++i) {
		free(st->name);
		free(st->surname);
		free(st->group);
		free(st->tel);
		free(st->ratings);

	}
	free(st);
}