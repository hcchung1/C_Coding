#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>
#include <time.h>

typedef struct Date {
	int month;
	int date;
}date;

bool abc = false;

void addTwoDate(int* based, int* basem, int* addd) {
	// abc = false;
	switch (*basem) {		
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		if (*addd + *based > 31) {
			if (*addd == 31) {
				*based = 31;
				abc = false;
				*addd = 0;
				break;
			}
			if (abc) *addd -= 31;
			else *addd = *addd + *based - 31;
			*based = 1;
			abc = true;
			*basem = *basem + 1;
			break;

		}
		else {
			*based += (abc) ? (*addd - 1) : (*addd);
			abc = false;
			*addd = 0;
			break;
		}
	case 2:
		if (*addd + *based > 28) {
			if (*addd == 28) {
				*based = 28;
				abc = false;
				*addd = 0;
				break;
			}
			if (abc) *addd -= 28;
			else *addd = *addd + *based - 28;
			*based = 1;
			abc = true;
			*basem = *basem + 1;
			break;
		}
		else {
			*based += (abc) ? (*addd - 1) : (*addd);
			abc = false;
			*addd = 0;
			break;
		}
	case 4: case 6: case 9: case 11:
		if (*addd + *based > 30) {
			if (*addd == 30) {
				*based = 30;
				abc = false;
				*addd = 0;
				break;
			}
			if (abc) *addd -= 30;
			else *addd = *addd + *based - 30;
			*based = 1;
			abc = true;
			*basem = *basem + 1;
			break;
		}
		else {
			*based += (abc) ? (*addd - 1) : (*addd);
			abc = false;
			*addd = 0;
			break;
		}
	
	}

}

int main() {

	date base;
	scanf("%d%d", &base.month, &base.date);
	int addm, addd;
	scanf("%d%d", &addm, &addd);
	base.month += addm;
	while (addd) {
		addTwoDate(&base.date, &base.month, &addd);
	}
	printf("%d %d \n", base.month, base.date);


}