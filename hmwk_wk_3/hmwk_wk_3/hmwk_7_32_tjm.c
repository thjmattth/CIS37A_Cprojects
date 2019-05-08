//  thomas matthew 07/13/17

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 5
#define COLS 4
#define CHAR_LEN 11
char row_labels[ROWS][CHAR_LEN] = { "gun control", "immigration", "drug wars  ", "healthcare ", "education  " };

int fill_matrix(float array[ROWS][COLS]){
	int x;
	int y;
	int l;
	int inpu;
	// one col at a time
	for ( y = 0; y < COLS; y++ ) {
		printf("How important (1-10) is:\n");
		float col_tot = 0;
		// one row at a time
		for ( x = 0; x < ROWS; x++ ){
			if (x == (ROWS-1)){
				array[x][y] = col_tot;
			}
			else if (y == (COLS-1)) {
				array[x][y] = 0;
			}
			else {
				for ( l = 0; l < CHAR_LEN; l++){
					printf("%c", row_labels[x][l]);
				}
				printf(":  ");
				scanf("%d", &inpu);
				array[x][y] = inpu;
				col_tot += array[x][y];			
			}
		}
	}
	for (x =0; x<ROWS; x++){
		float row_tot = 0;
		for (y = 0; y < COLS; y++){
			if (x < ROWS-1 && y < COLS-1){
				row_tot += array[x][y];  // array[x][COLS-1] += array[x][y];
			}
			else{
			array[x][COLS-1] = (row_tot / (COLS-1)); // array[x][COLS-1] = array[x][COLS-1] / (COLS-1);
			}	
		}
		printf("row_tot: %f", row_tot);
	}	
	return 0;
}

int print_mat(float mat[ROWS][COLS], char labels[ROWS][CHAR_LEN]) {
	int x;	
	int l;
	int y;
	printf( "Summary:\n\t\t" );
	for (y = 0; y < COLS -1; y++){
		printf("RESPONDANT #%d\t", y+1);

	}
	printf("MEAN RATING\n");
	for ( x = 0; x < ROWS;x++ ) {
		if (x < (ROWS-1)){
			for ( l = 0; l < CHAR_LEN; l++){
				printf("%c", row_labels[x][l]);
			}
		}
		else{
			printf("total: \t");
		}
		
		printf("\t");
		for ( y = 0; y < COLS; y++ ) {
			printf( "  [%f]\t", mat[x][y] );
		}
	printf( "\n" );
	}
	getchar();
	return 0;
}

int main (void) {

	float array[ROWS][COLS]; /* Declares an array like a chessboard */
	fill_matrix(array);
	print_mat(array, row_labels);

}
