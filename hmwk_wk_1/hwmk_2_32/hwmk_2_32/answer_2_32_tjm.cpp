/*
caluclates bmi based on height(in) and weight(lb)
hmwk 2.32

created by thomas matthew 06/21/17
catagories of bmi are determined by
Department of Health and Human Services and National Institutes of Health


*/

#include <stdio.h>

int main(void)
{
	float weight, height, bmi;
	
	printf("Enter your height in inches:\n");
	scanf("%f", &height);

	printf("Enter your weight in pounds:\n");
	scanf("%f", &weight);

	bmi = ((weight * 703) / (height * height));

	printf("Your BMI is:\n"
		   "%f\n", bmi);

	if (bmi >= 30) {
		printf("OBESE\n");
	}
	else if (bmi >= 25) {
		printf("Overweight\n");
	}
	else if (bmi >= 18.5) {
		printf("Normal\n");
	}
	if (bmi < 18.5) {
		printf("Underweight\n");
	}
	return 0;
}