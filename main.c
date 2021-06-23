#include "students.h"

int main() {
	ST* st1 = 0;
	addStud(&st1, "Ivanov", "Ivan", 18, "MK102", "682051", "554545");
	addStud(&st1, "Ivanova", "Ekaterina", 20, "MK101", "677059", "434333");
	addStud(&st1, "Petrova", "Angelina", 19, "MP101", "699770", "554555");
	addStud(&st1, "Elkina", "Viktoriya", 21, "MP102", "630305", "333443");
	addStud(&st1, "Ivleeva", "Sasha", 20, "MK102", "677827", "555555");
	outputST(st1);
	outputGoodST(st1);
	outputSurnameST(st1);
	deleteLastST(&st1);
	outputST(st1);
	deleteBadProgress(&st1);
	outputST(st1);
	deleteByIndex(&st1, 2);
	outputST(st1);
	return 0;
}