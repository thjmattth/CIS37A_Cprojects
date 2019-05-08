/*
print checkerboard pattern
hmwk 3.39

created by thomas matthew 06/21/17
*/

#include <stdio.h>

int main(void)
{
	unsigned int row = 1;
	while (row <= 8) { // loop until row < 1
		unsigned int col = 1; // set column to 1 as iteration begins
			while (col <= 16) { // loop 16 times
				unsigned int sum = row + col;
				if (sum % 2 == 0) {
					printf("%s", "*"); }
				else {
					printf("%s", " "); }
				
				++col; // increment col
			} // end inner while 
			puts(""); // outputs a newline
			++row; // increment row
	} // end outer while 

}