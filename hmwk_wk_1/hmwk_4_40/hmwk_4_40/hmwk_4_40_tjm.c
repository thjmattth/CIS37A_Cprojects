/*
* fairtax.c
* hmwk 4.40
*
* thomas matthew 06/22/17
*
* prints tax burden of a fair-tax scheme
*
* housing, food, clothing, transportation, edu-
cation, health care, vacations)
*/


#include <stdio.h>

int calc_tax(void) {
	float hous;
	float food;
	float cloth;
	float trnst;
	float edctn;
	float helth;
	float vacay;

	float sum = 0;

	printf("Enter yearly housing costs:\n");
	scanf("%f", &hous);
	sum += hous;

	printf("Enter yearly food costs:\n");
	scanf("%f", &food);
	sum += food;

	printf("Enter yearly cloth costs:\n");
	scanf("%f", &cloth);
	sum += cloth;

	printf("Enter yearly transit costs:\n");
	scanf("%f", &trnst);
	sum += trnst;

	printf("Enter yearly education costs:\n");
	scanf("%f", &edctn);
	sum += edctn;

	printf("Enter yearly healthcare costs:\n");
	scanf("%f", &helth);
	sum += helth;

	printf("Enter yearly vacation costs:\n");
	scanf("%f", &vacay);
	sum += vacay;

	float tax_rate = 23;
	float tax_burden = 0;

	printf("Enter tax rate percentage:\n");
	while (tax_rate >= 0) {

		scanf("%f", &tax_rate);
		tax_burden = ((tax_rate / 100) * sum);
		printf("With taxible yearly costs of $%.2f,"
			" a tax rate of %.2f%% will cost:\n$%.2f\n", sum, tax_rate, tax_burden);
		printf("\nEnter another tax rate percentage (or -1 to quit):\n");
	}
	return 0;
}

int main(int argc, char **argv)
{
	calc_tax();
	return 0;
}