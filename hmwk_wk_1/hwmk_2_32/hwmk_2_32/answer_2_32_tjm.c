#include <stdio.h>

int main(void)
{
	int weight;
	int height;
	int bmi;
	
	printf("Enter your height in inches:\n");
	scanf("%d", &height);

	printf("Enter your weight in pounds:\n");
	scanf("%d", &weight);

	bmi = (weight * 703) / (height * height);

	printf("Your BMI is:\n"
		   "%f", bmi);

	if (bmi < 18.5) {
		printf("Underweight");
	}
	else if (bmi >= 18.5 && bmi < 25) {
		printf("Normal");
	}
	else if (bmi >= 25  && bmi < 30) {
		printf("Overweihght");
	}
	else if (bmi >= 30) {
		printf("OBESE");
	}
}