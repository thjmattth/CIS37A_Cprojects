/*
hmwk 8.2 
initialize string two ways

thomas matthew 7/18/2017
*/

#include <string.h>

int arr_compare(void) {
	char vowel1[] = "AEIOU";
	char vowel2[] = { 'A', 'E', 'I', 'O', 'U', '\0' };

	if (memcmp(vowel1, vowel2, sizeof(vowel1)) == 0) {
		printf("The arrays are EQUAL: \t");
		puts("You can initialize an array either way");
	}
	else {
		printf("The arrays are not equal.");
	}
	return 0;
}

//int main(void) {
//	arr_compare();
//}