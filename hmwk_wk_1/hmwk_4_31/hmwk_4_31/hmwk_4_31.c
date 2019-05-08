/*
* diamond.c
*
* thomas matthew 06/22/17
*
* prints a diamond of stars based on total_row number (default =9)
*/

#include <stdio.h>


void print_char(int n_star, int n_space, int n_col) {
	// n_star, n_space: max num of stars, spaces to print
	// n_col: max num of cols per line, same as num rows
	for (int n = 1; n <= n_space / 2; n++) {
		printf(" ");
	}
	for (int n = 1; n <= n_star; n++) {
		printf("*");
	}
	for (int n = 1; n <= n_space / 2; n++) {
		printf(" ");
	}
	puts("");
}


int main(void) {
	int total_row = 9;
	int n_col = total_row;
	int n_star, n_space;

	for (int row = 0; row < total_row; row++) {
		if (row <= total_row / 2) {  // top half
			n_star = row * 2 + 1;
			n_space = n_col - n_star;
			print_char(n_star, n_space, n_col);
		}
		//~ print_char(); } // top half
		else {  // top half
			n_star -= 2;
			n_space = n_col - n_star;
			print_char(n_star, n_space, n_col);
		}
	}
	return 0;
}