/*
hmwk 8.24
prints words from string that end in "ed"

thomas matthew 7/18/17
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>



char *inputString(FILE* fp, size_t size) {
	// This function was adapted from SO user: BLUEPIXY
	// https://stackoverflow.com/questions/16870485/how-can-i-read-an-input-string-of-unknown-length?rq=1
	//The size is extended by the input with the value of the provisional
	char *str;
	int ch;
	size_t len = 0;
	str = realloc(NULL, sizeof(char)*size);//size is start size
	if (!str)return str;
	while (EOF != (ch = fgetc(fp)) && ch != '\n') {
		str[len++] = ch;
		if (len == size) {
			str = realloc(str, sizeof(char)*(size += 16));
			if (!str)return str;
		}
	}
	str[len++] = '\0';

	return realloc(str, sizeof(char)*len);
}

int input_ed(void) {
	char *str_arr;
	char *word;
	printf("input string : ");
	str_arr = inputString(stdin, 10);
	int len = strlen(str_arr);
	printf("words that end with 'ed':\n");
	int offset = 0;
	for (int c = 0; c < strlen(str_arr); c++) {
		if (offset >= len){
			return 0;
		}
		else if ((str_arr[c] < 65 // not ascii value 65-90, or 97-122 inclusive
			|| (str_arr[c] >=96 && str_arr[c < 97])
			|| str_arr[c] > 122)
			&& tolower(str_arr[c - 2]) == 'e'
			&& tolower(str_arr[c - 1]) == 'd'){
			for (int p = 0 + offset + 1; p < c; p++) {
				if ((str_arr[p]>=65  && str_arr[p] <=90)
					|| (str_arr[p] >= 97 && str_arr[p] <= 122)) {
					printf("%c", str_arr[p]);
				}
			}
			puts("");
		}
		else if (str_arr[c] == ' ') {
			offset = c;
		}
	}

	return 0;
}


//int main(void) {
//	input_ed();
//	return 0;
//}