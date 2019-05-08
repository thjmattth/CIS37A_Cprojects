/*
 * hmwk_06_22_tjm.c
 * 
 * builds sales tracker of products sold (sellers x products) from user inputs
 * sums product quantities by product and by seller
 * prints fancy table of sales with sums
 * 
 * thomas j matthew
 * 07/05/17 
 */


#include <stdio.h>
#include <ctype.h>

#define SELLERS 5  // number of rows
#define PRODUCTS 4  // number of cols


void fill_matrix(int matrix[SELLERS][PRODUCTS] ){
	int selr_code;  // salesperson id code
	int prod_code;  // product id code
	int prod_qty;  // product quantity sold
	char rw_cmd;  // overwrite command
	
	printf("Enter seller code (-1 to quit):\t");
	scanf("%d", &selr_code);
	
	while (selr_code >= 0){
		
		printf("Enter product code:\t");
		scanf("%d", &prod_code);
		
		printf("Enter product qty:\t");
		scanf("%d", &prod_qty);
		
		// overwrite protection
		if (matrix[selr_code][prod_code] > 0){
			printf("Do you wish to overwrite? (y/n):\t");
			scanf(" %c", &rw_cmd);
			if (tolower(rw_cmd) == 'y'){
				printf("Value at seller %d, product %d changed:\t", selr_code, prod_qty);
				printf("%d --> %d/n", matrix[selr_code][prod_code], prod_qty);
				matrix[selr_code-1][prod_code-1] += prod_qty;
			}
			else {
				printf("Overwrite at seller %d, product %d halted:\t", selr_code, prod_qty);
			}
		}
		else {
		matrix[selr_code-1][prod_code-1] += prod_qty;
		}
		printf("Enter seller code (-1 to quit):\t");
		scanf("%d", &selr_code);
	}
}


void row_col_sum(int row_sum_arr[SELLERS], int col_sum_arr[PRODUCTS + 1], int matrix[SELLERS][PRODUCTS]){
	int row;
	int col;
	for (row = 0; row < SELLERS; row++){
		for (col = 0; col < PRODUCTS; col++){
			row_sum_arr[row] += matrix[row][col];  // sum across a row
			col_sum_arr[col] += matrix[row][col];  // sum across a col
		}
	}
	int tot = 0;
	for (int i = 0; i < PRODUCTS + 1; i++){
		tot += col_sum_arr[i];
	}
	col_sum_arr[PRODUCTS] = tot;	
}

void print_sales_matrix (int row_sum_arr[SELLERS], int col_sum_arr[PRODUCTS + 1], int matrix[SELLERS][PRODUCTS]){
	int row;
	int col;

	printf("seller        p r o d u c t s          sum  \n");
	printf("------- -------------------------      ---");         
	for (row = 0; row < SELLERS; row++){
		printf("\n%d:", row+1);
		
				
		for (col = 0; col < PRODUCTS; col++){
			if (row < SELLERS ){
				printf("  \t%d", matrix[row][col]);	
			}
			else {
				printf("\t%d", col_sum_arr[col]);	
			}
		}
		printf("\t%d\n", row_sum_arr[row]);
	}
	
	printf("\n======= ==========================     ===");
	printf("\ntotal:");
	for (int i = 0; i < PRODUCTS + 1; i++){
		printf("\t%d",col_sum_arr[i]);
	}
	puts("");

}


void main_cntrl (void){
	// fill matrix from user input
	int sales_matrix[SELLERS][PRODUCTS] = {0};
	fill_matrix(sales_matrix);
	
	// compute sums
	int row_sums[SELLERS] = {0};
	int col_sums[PRODUCTS + 1] = {0};
	row_col_sum(row_sums, col_sums, sales_matrix);

	// print matrix and sums
	char print_cmd;
	printf("Do you wish to print (y/n):\n");
	scanf(" %c", &print_cmd);
	if (tolower(print_cmd) == 'y'){
		print_sales_matrix(row_sums, col_sums, sales_matrix);
	}

}


//int main ( void ){
//	main_cntrl();
//	return 0;
//}
