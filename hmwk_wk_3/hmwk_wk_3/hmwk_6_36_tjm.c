/*
hmwk 6.36

thomas matthew 07/08/2017

prompt:
6.36 (Print a String Backward) Write a recursive function stringReverse that takes a character
array as an argument, prints it back to front and returns nothing. The function should stop processing
and return when the terminating null character of the string is encountered.

*/

#include <stdio.h>
#define LEN 5

void print_backwards(int i, char arr[]) {
	i -= 1;
	if (i < 0) {
		return 0;
	}
	else {
		printf("%c", arr[i]);
		print_backwards(i, arr);
	}
}

void test(void) {
	char arr[] = { "abcd" };
	printf("forward: ");
	for (int i = 0; i < LEN ; i++) {
		printf("%c", arr[i]);
	}
	puts("");
	printf("backward: ");
	print_backwards(LEN, arr);
	puts("");
}

//void main(void) {
//	test();
//}