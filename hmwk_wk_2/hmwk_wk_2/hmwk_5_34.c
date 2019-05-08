//recursive exponentiation
//hmwk 5.34
//
//by thomas matthew 06/29/17

#include <stdio.h>;


unsigned long long int calc_expo(unsigned long long int base, unsigned long long int expo ) {
	if (expo == 0) {  // base case 
		return 1;  // base^0 = 1
	}
	else if ( expo % 2 == 0 ) {
		return calc_expo(base*base, expo / 2);  // base^2*exp = (base^2)^exp
	}
	else {
		return base * calc_expo (base, expo - 1 ); // base^exp = base*base^(exp-1)
	}		
}


void input_expo (void) {
	unsigned long long int b, e;

	printf("input base:\n");
	scanf("%llu", &b);

	printf("input exp:\n");
	scanf("%llu", &e);

	printf("Answer:\n%llu\n", calc_expo(b, e));
}

//int main(void) {
//	input_expo();
//}