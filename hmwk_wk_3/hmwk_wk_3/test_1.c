#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 2
#define COLS 3

void fill_mat(int mat[ROWS][COLS]) {
	for (int r = 0; r < ROWS; r++) {
		for (int c = 0; c < COLS; c++){
			printf("fill row %d, col %d  \t:", r, c);
			scanf("%d", &mat[r][c]);
		}
	}
}

void print_mat(int mat[ROWS][COLS], char labels[5][11]) {
	printf("here is is yo:\n");
	for (int r = 0; r < ROWS; r++) {
		for (int c = 0; c < 11; c++) {
			printf("%c", labels[r][c]);
		}
		print("\t");
		for (int c = 0; c < COLS; c++) {
			printf("%d\t", mat[r][c]);
		}
		puts("");
	}
}

void main(void) {
	int mat[ROWS][COLS] = { 0 };
	char row_labels[5][11] = { "gun control", "immigration", "drug wars  ", "healthcare ", "education  " };
	fill_mat(mat)sdfbvfd 
	print_mat(mat, row_labels);
	printf("what");
}