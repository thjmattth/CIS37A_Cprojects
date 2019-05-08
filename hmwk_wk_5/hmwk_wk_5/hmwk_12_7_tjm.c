/*

12.7 (Merging Ordered Lists) 

thomas matthew 7/29/17

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define A_LEN 5
#define B_LEN 3
#define max A_LEN+B_LEN

int comparison(const void * a, const void * b)
{
	int int_a = *((int*)a);
	int int_b = *((int*)b);

	if (int_a == int_b) {
		return 0;
	}
	else if (int_a < int_b) {
		return -1;
	}
	else {
		return 1;
	}
} 

void merge_sort_cntrl(void) {

	int a[A_LEN] = { 2, 3, 4, 5, 6 };
	int b[B_LEN] = { 1, 5, 10 };

	// print a, list 1
	printf("list 1:\t\t\t");
	for (int i = 0; i < A_LEN; i++) {
		printf("%d ", a[i]);
	}
	puts("");

	// print b (list 2)
	printf("list 2:\t\t\t");
	for (int i = 0; i < B_LEN; i++) {
		printf("%d ", b[i]);
	}
	puts("");

	int* merged = calloc(max, sizeof(int)); // array merged holds result

	for (int i = 0; i < max; i++) {
		if (i < A_LEN) {
			merged[i] = a[i];
		}
		else {
			merged[i] = b[i - A_LEN];
		}
	}
	// prints merged list
	printf("list merge:\t\t\t");
	for (int i = 0; i < max; i++) {
		printf("%d ", merged[i]);
	}
	puts("");

	qsort(merged, max, sizeof(int), comparison);

	// prints merged list
	printf("list merged & sorted:\t");
	for (int i = 0; i < max; i++) {
		printf("%d ", merged[i]);
	}
	puts("");

}

//void main(void) {
//	merge_sort_cntrl;
//	return 0;
//}
