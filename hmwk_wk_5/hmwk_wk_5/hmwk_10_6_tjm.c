/*

hmwk 10.6
struct of x customer

thomas matthew 7/19/17
 prompt:
 Given the supplied structure "customer" and variable definitions,

 write an expression that can be used to access the structure members in each of the following parts:
 x) Member lastName of structure customerRecord.
 y) Member lastName of the structure pointed to by customerPtr.
 c) Member firstName of structure customerRecord.
 d) Member firstName of the structure pointed to by customerPtr.
 e) Member customerNumber of structure customerRecord.
 f) Member customerNumber of the structure pointed to by customerPtr.
 g) Member phoneNumber of member personal of structure customerRecord.
 h) Member phoneNumber of member personal of the structure pointed to by customerPtr.
 i) Member address of member personal of structure customerRecord.
 j) Member address of member personal of the structure pointed to by customerPtr.
 k) Member city of member personal of structure customerRecord.
 l) Member city of member personal of the structure pointed to by customerPtr.
 m) Member state of member personal of structure customerRecord.
 n) Member state of member personal of the structure pointed to by customerPtr.
 o) Member zipCode of member personal of structure customerRecord.
 p) Member zipCode of member personal of the structure pointed to by customerPtr
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


struct customer {
	char lastName[15];
	char firstName[15];
	unsigned int customerNumber;
	struct {
		char phoneNumber[11];
		char address[50];
		char city[15];
		char state[3];
		char zipCode[6];
	} personal;
} customerRecord, *customerPtr;


int access_struct(void) {

	int opt_record;
	char opt_ptr;
	printf("Locate Record:\n"
		"1 = last name\n"
		"2 = first name\n"
		"3 = customer number"
		"4 = phone number\n"
		"5 = address\n"
		"6 = city\n"
		"7 = state\n"
		"8 = zip code\n"
		"-1 = quit\n");
	printf("Enter option here: \t");
	scanf("%d", &opt_record);

	while (opt_record > 0) {
		printf("Access via pointer? (y/n): \t");
		scanf("\n%c", &opt_ptr);
		bool ptr = false;
		if (opt_ptr == 'y' || opt_ptr == 'Y') {
			ptr = true;
		}
		else {
			ptr - false;
		}
		printf("Value is below: \n\n");
		switch (opt_record) {
		case 1:
			if (ptr) {
				printf("%s\n", customerPtr->lastName);
			}
			else {
				printf("%s\n", customerRecord.lastName);
			}
			break;
		case 2:
			if (ptr) {
				printf("%s\n", customerPtr->firstName);
			}
			else {
				printf("%s\n", customerRecord.firstName);
			}
			break;
		case 3:
			if (ptr) {
				printf("%u\n", ( *customerPtr ).customerNumber);
			}
			else {
				printf("%u\n", customerRecord.customerNumber);
			}
			break;
		case 4:
			if (ptr) {
				printf("%s\n", (*customerPtr).personal.phoneNumber);
			}
			else {
				printf("%s\n", customerRecord.personal.phoneNumber);
			}
			break;
		case 5:
			if (ptr) {
				printf("%s\n", (*customerPtr).personal.address);
			}
			else {
				printf("%s\n", customerRecord.personal.address);
			}
			break;
			
		case 6:
			if (ptr) {
				printf("%s\n", (*customerPtr).personal.city);
			}
			else {
				printf("%s\n", customerRecord.personal.city);
			}
			break;
		case 7:
			if (ptr) {
				printf("%s\n", (*customerPtr).personal.state);
			}
			else {
				printf("%s\n", customerRecord.personal.state);
			}
			break;
		case 8:
			if (ptr) {
				printf("%s\n", (*customerPtr).personal.zipCode);
			}
			else {
				printf("%s\n", customerRecord.personal.zipCode);
			}
			break;
		}
		printf("\nEnter another entry here: \t");
		scanf("%d", &opt_record);
		
	}
	return 0;
}

//int main(void) {
//
//	access_struct();
//	return 0;
//}
