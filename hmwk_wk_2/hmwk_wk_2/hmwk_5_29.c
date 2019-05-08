/*
find greatest common factor (GCD)

thomas matthew
06/29/17
*/

#include <stdio.h>


int gcd(int int1, int int2) {
	int mod = int1%int2;
	
	if (int1%mod == 0 | int2%mod == 0) { // check if mod is divisible into either integer
		return mod;
	}
	else {
		return 1;
	}
}

void gcd_input() {
	// get user inputs
	int int1;
	int int2;
	printf("Enter integer 1:  ");
	scanf("%d", &int1);

	printf("Enter integer 2:  ");
	scanf("%d", &int2);

	// call gcd with params ordered from max to min
	if (int1 > int2) {
		printf("GCD is: %d\n", gcd(int1, int2));
		}
	else if (int2 > int1) {
		printf("GCD is: %d\n", gcd(int2, int1));
		}
	else {
		printf("GCD is: %d\n", int1);
	}
}

//void main(void) {
//	gcd_input();
//}