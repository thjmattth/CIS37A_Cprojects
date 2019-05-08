#include<string.h>
#include<stdlib.h>
#include<stdio.h>

//#define A_LEN 5
//#define B_LEN 3
//#define max 10
//
//void main(void) {
//	int a[A_LEN] = { 6, 5, 4, 3, 2 };
//	int b[B_LEN] = { 1, 5, 10 };
//
//	int* merged = calloc((A_LEN + B_LEN), sizeof(int)); // array merged holds result
//
//	for (int i = 0; i < (A_LEN + B_LEN); i++) { // fill from a 
//		if (i < A_LEN) {
//			merged[i] = a[i];
//		}
//		else {
//			merged[i] = b[i - A_LEN];
//		}
//	}
//
//	//memcpy(merged, a, A_LEN * sizeof(int)); // copy 5 ints to merged
//	//memcpy(merged + B_LEN, b, B_LEN * sizeof(int)); // copy 3 ints to merged
//
//	for (int i = 0; i < 8; i++) {
//		printf("%d", merged[i]);
//	}
//	puts("");
//	printf("%d", merged[0]);
//}
