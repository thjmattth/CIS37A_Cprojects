/*
calculates target heart rate determined by American Heart Association

created by thomas matthew 06/21/17

prompt:
'''
formula for calculating your maximum heart rate in
beats per minute is 220 minus your age in years. Your target heart rate is a range that’s 50–85% of
your maximum heart rate. [Note: These formulas are estimates provided by the AHA...

...Create a program that reads the user’s birthday and the current day (each consisting of the month,
day and year). Your program should calculate and display the person’s age (in years), the person’s
maximum heart rate and the person’s target-heart-rate range.
'''
*/

#include <stdio.h>

int main() {
	int cday, bday;
	printf("enter your birthday (ddmmyyyy):\n");
	scanf("%d", &bday);
	printf("enter current day (ddmmyyyy):\n");
	scanf("%d", &cday);

	int b_yr = bday % 10000;  //if 12345678 then 5678
	int b_mo = bday / 10000 % 100;  //if 12345678 then 34
	int b_dy = bday / 1000000 % 100;  //if 12345678 then 12
	int c_yr = cday % 10000;
	int c_mo = cday / 10000 % 100;
	int c_dy = cday / 1000000 % 100;

	unsigned int age;
	if (c_yr > b_yr && c_mo > b_mo) {  // birthday has passed this year
		age = c_yr - b_yr; }
	else if (c_yr > b_yr && c_mo < b_mo) {  // birthday has not yet passed this year
		age = c_yr - b_yr - 1; }
	else if(c_yr > b_yr && c_mo == b_mo) {
		if (c_dy < b_dy) {// birthday has not yet passed this month
			age = c_yr - b_yr - 1; }
		if (c_dy > b_dy) { // birthday has passed this month
			age = c_yr - b_yr; }
		if (c_dy == b_dy) {
			age = c_yr - b_yr;
			printf("happy birthday!"); }
	}

	else {
		printf("sorry, you've entered an invalid date.  try again later.");
		return 0;
	}

	int max_bpm = 220 - age;
	
	printf("your age is: %d\n", age);
	printf("max heart-rate: %d\n", max_bpm);
	printf("target heart-rate: %.1f - %.1f\n", max_bpm*0.5, max_bpm*0.85);
}