/*
calculates daily cost of commuting
hmwk 2.33

created by thomas matthew 06/21/17
*/

#include <stdio.h>

int main(void) {
	float miles;
	float mpg;
	float cpg;
	float park;
	float ntoll;
	float cptoll;

	float total_cost;

	printf("Input miles driven:\n");
	scanf("%f", &miles);

	printf("Input miles/gal:\n");
	scanf("%f", &mpg);

	printf("Input cost/gal:\n");
	scanf("%f", &cpg);

	printf("Input cost/park:\n");
	scanf("%f", &park);

	printf("Input number of tolls:\n");
	scanf("%f", &ntoll);

	printf("Inputs cost/toll:\n");
	scanf("%f", &cptoll);

	total_cost = (((miles / mpg) * cpg) + (ntoll * cptoll) + park);

	printf("Total Cost for Today's Driving:\n"
		"$%.02f\n", total_cost);

}
