/*
world population counter
hmwk 4.39

by thomas matthew 06/28/17


*/


#include <stdio.h>
#include <stdlib.h>
#include <math.h>


void world_pop( float pop_i, float rate, int year, int year_current) {
	
	float pop_n; // current year's pop, (pop_i = initial pop)
	float pop_l; // last year's pop
	float pop_change; // population change between years
	float r = (rate/100)+1.0;
	pop_n = pop_i * pow(r, year);
	
	if (year == 0) {
		pop_change = 0;  // population change is 0 for first year
		}
	else {
		float pop_l; // last year's pop
		pop_l = pop_i * pow(r, year - 1);
		pop_change = pop_n - pop_l;
	}
		printf("%d \t | \t %.1f \t | \t %.1f \n", year_current, pop_n, pop_change);
	}


void input_loop_print(void) {
	float p;
	float r;
	int y_f;
	int y_c = 2017;
	printf("enter initial population (millions):\n");
	scanf("%f", &p);
	printf("enter population growth rate (%%):\n");
	scanf("%f", &r);
	printf("enter years of population growth:\n");
	scanf("%d", &y_f);
	printf("year\t|\tpop \t|\tytd_increase\n");
	printf("_____________________________________\n");
	for (int y = 0; y <= y_f; ++y) {
		y_c += 1;
		world_pop(p, r, y, y_c);
	}
}


//void main(void) {
//	input_loop_print();
//}