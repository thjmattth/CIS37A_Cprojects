#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define ROWS 2
#define COLS 3

void fill_mat(int mat[ROWS][COLS]) {
	for (int r = 0; r < ROWS; r++) {
		for (int c = 0; c < COLS; c++){
			printf("fill row %d, col %d", r, c);
			scanf("%d", &mat[r][c]);
		}
	}
}

void print_mat(int mat[ROWS][COLS]) {
	printf("here is is:\n");
	for (int r = 0; r < ROWS; r++) {
		for (int c = 0; c < COLS; c++) {
			printf("%d\t", mat[r][c]);
		}
		puts("");
	}
}

void main(void) {
	int mat[ROWS][COLS] = { 0 };
	fill_mat(mat);
	print_mat(mat);

}