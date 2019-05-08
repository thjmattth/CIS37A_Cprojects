/*
 hmwk 6.33
 
 thomas matthew 07/06/2017

 prompt:
 6.33 (Binary Search) Modify the program of Fig. 6.19 to use a recursive binarySearch function
 to perform the binary search of the array. The function should receive an integer array, the starting
 subscript, the ending subscript and the search key as arguments. If the search key is found, return
 the array subscript; otherwise, return –1.

 */

#include <stdio.h>
#define LEN 10


int recurse_search(int query, int i_lo, int i_hi, int array[]) {
	int i;
	i = (i_lo + i_hi) / 2;  // i is median of range(i_lo, i_hi)
	if (i_lo > i_hi) {  // invalid value search range if i_lo > i_hi
		return -1;  
	}
	else {
		if (query == array[i]) {  // // query matched index i
			return i;
		}
		else if (query > array[i]) {
			recurse_search(query, i+1, i_hi, array);  // query below index i
		}
		else if (query < array[i]) {
			recurse_search(query, i_lo, i-1, array);  // query above index i
		}
	}
}


void input_array( void ) {
	
	// initialize ordered array
	int arr[LEN] = { 0 };
	for (int i = 0; i < LEN; i++) {
		arr[i] = i;
	}
	printf("here is your list:\t");
	for (int i = 0; i < LEN; i++) {
		printf("%d ", arr[i]);
	}
	// get query
	int query;
	int query_index;
	printf("\ninput integer to query:\t");
	scanf("%d", &query);
	query_index = recurse_search(query, 0, LEN - 1, arr);
	if (query_index > 0){
		printf("query %d found at index position %d", query, query_index);
	}
	else {
		printf("query %d  not found in array", query, query_index);
	}
	puts("");
}


//void main(void) {
//	input_array();
//}
