/*
hmwk 7.30

thomas matthew 07/11/2017

prompt:
(Calculating Circle Circumference, Circle Area or Sphere Volume Using Function Pointers)
Using the techniques you learned in Fig. 7.28, create a text-based, menu-driven program that allows
the user to choose whether to calculate the circumference of a circle, the area of a circle or the volume
of a sphere. The program should then input a radius from the user, perform the appropriate
calculation and display the result. Use an array of function pointers in which each pointer represents
a function that returns void and receives a double parameter. The corresponding functions should
each display messages indicating which calculation was performed, the value of the radius and the
result of the calculation.

*/

#include <stdio.h>
#define M_PI 3.14159265358979323846

void circumference(float radius) {
	float result;
	result = M_PI * radius * 2;
	printf("\nRadius of %f produces circumference of %f \n", radius, result);
}

void area(float radius) {
	float result = (M_PI * radius * radius);
	printf("\nRadius of %f produces area of %f \n", radius, result);
}

void volume(float radius) {
	float result = ((4/3) * M_PI * radius * radius);
	printf("\nRadius of %f produces volume of %f \n", radius, result);
}

float rad_args(void) {
	float radius;
	printf("Enter the radius for calculations:\t");
	scanf("%f", &radius);
	return radius;
}

int sel_args(void) {
	int selection;
	printf("\nCalculation Options:\n"
		"1) Circumference of Circle\n"
		"2) Area of Circle\n"
		"3) Volume of Sphere\n"
		"-1) quit\n"
		"Enter the choice of calculations:\t");

	scanf("%d", &selection);
	return selection;
}

void calc_cntrl(void) {
	float radius = 0;
	radius = rad_args();

	// array of functions pointer
	void(*calc_ptr_arr[])(float) = { circumference, area, volume };
	
	int select = 0;
	select = sel_args();
	
	if (select < 1 || select > 3) {
		printf("Invalid Selection.  Quitting...");
		return 0;
	}

	(*calc_ptr_arr[select-1])(radius);
	puts("");
	return 0;
}

//void main(void) {
//	calc_cntrl();
//}