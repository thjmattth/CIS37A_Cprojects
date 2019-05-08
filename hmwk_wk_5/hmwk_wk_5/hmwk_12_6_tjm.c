/*
12.6 (Concatenating Lists) 

thomas matthew 7/23/17

prompt:
Write x program that concatenates two linked lists of characters.The
program should include function concatenate that takes pointers to both lists as arguments and
concatenates the second list to the first list
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* concat_str(const char *str1, const char *str2) {
	char *result = malloc(strlen(str1) + strlen(str2) + 1); // add one for null terminator
													  
	strcpy(result, str1);
	strcat(result, str2);
	return result;
}

int concat_cntrl(void) {
	char* str1 = "foo";
	char* str2 = "bar";
	printf("string 1:\t%s\nstring 2:\t%s\n", str1, str2);

	char* str_cat = concat_str(str1, str2);
	printf("concat string:\t%s\n", str_cat);
	return 0;
}

//int main(void) {
//	concat_cntrl();
//	return 0;
//}