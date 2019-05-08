/*
hmwk 9.10
convert farhenheit to celsius

thomas matthew 7/18/17
*/

#include <stdio.h>

float fahr_to_cels(float fahr) {
	return 5.0 / 9.0 * (fahr - 32);
}

int format_print(void) {
	float fahr_input;
	float cels_output;
	char sign;
	printf("enter degrees of fahrenheit:\t");
	scanf("%f", &fahr_input);
	cels_output = fahr_to_cels(fahr_input);
	puts("");

	printf("Fahrenheit\tCelsius\n" );
	if (fahr_input < 0) {
		sign = '+';
	}
	else {
		sign = "";
	}
	printf("%.3f\t\t", fahr_input);
	if (cels_output < 0) {
		sign = '+';
	}
	else {
		sign = "";
	}
	printf("%.3f\n", cels_output);
	return 0;
	
}

int main(void) {
	format_print();
	return 0;
}