/*
11.10 
merge records on account number

thomas matthew 7/30/17

thanks to Saloni Madaan for discussions that helped me arrive at a solution
*/

#include <stdio.h>
#include <stdlib.h>

void merge_on_account(void) {
	int account_master; // account no from old master file
	double balance_master; // balance $ from old master file
	int account_transaction; // account no from transactions file
	double balance_transaction; // balance $ from transactions file
	char accountholder_master[88];  // name from master file
	FILE *odfPtr; // pointer to old master file
	FILE *trfPtr; // ponter to transactions file
	FILE *nwfPtr; // pointer to new master file

	// quit if files cannot be opened
	if ((odfPtr == fopen("master_old.txt", "r")) == NULL) {
		printf("Cannot Open master file\n");
		exit(1);
	}
	if ((trfPtr == fopen("transactions.txt", "r")) == NULL) {
		printf("Cannot Open transaction file\n");
		exit(1);
	}
	if ((nwfPtr == fopen("newmast.dat", "w")) == NULL) {
		printf("Cannot Open newmast.dat\n");
		exit(1);
	}

	// display account
	printf("Account Display:\n");
	fscanf(trfPtr, "%d%lf", &account_transaction, &balance_transaction);

	while (!feof(trfPtr)) {  // loop thru file while line != EOF
		fscanf(odfPtr, "%d%[^0-9-]%lf", &account_master, accountholder_master, &balance_master);

		while (account_master < account_transaction && !feof(odfPtr)) {
			fprintf(nwfPtr, "%d%s%.2f\n", account_master, accountholder_master, balance_master);
			printf("%d %s %.2f\n", account_master, accountholder_master, balance_master);
			fscanf(odfPtr, "%d%[^0-9-]%lf", &account_master, accountholder_master, &balance_master);
		}
		if (account_master == account_transaction) { // loops if more transactions are to be updated
			while (account_master == account_transaction && !feof(trfPtr)) {
				balance_master += balance_transaction;
				fscanf(trfPtr, "%d%lf", &account_transaction, &balance_transaction);
			}
			fprintf(nwfPtr, "%d %s %.2f\n", account_master, accountholder_master, balance_master);
			printf("%d %s %.2f\n", account_master, accountholder_master, balance_master);
		}
		// what if transaction records do not match master file?
		else if (account_master > account_transaction) {
			printf("Transaction record mismatch at %d\n", account_transaction);
			fprintf(nwfPtr, "%d %s %.2f\n", account_master, accountholder_master, balance_master);
			printf("%d %s %.2f\n", account_master, accountholder_master, balance_master);
			fscanf(trfPtr, "%d%lf", &account_transaction, &balance_transaction);
		}
		else {
			printf("Transaction record mismatch at %d\n", account_transaction);
			fscanf(trfPtr, "%d%lf", &account_transaction, &balance_transaction);
		}
		fscanf(trfPtr, "%d%lf", &account_transaction, &balance_transaction);
	}
	while (!feof(odfPtr)) {  // print account number with name and balance
		fscanf(odfPtr, "%d%[^0-9-]%lf", &account_master, accountholder_master, &balance_master);
		fprintf(nwfPtr, "%d %s %.2f\n", account_master, accountholder_master, balance_master);
		printf("%d %s %.2f\n", account_master, accountholder_master, balance_master);
	}
	fclose(odfPtr);
	fclose(trfPtr);
	fclose(nwfPtr);
}

int main(void) {
	merge_on_account();
}