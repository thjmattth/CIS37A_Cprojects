/*
10.12 (Packing Characters into an Integer) 

thomas matthew 7/23/17
*/

#include <stdio.h>
#define CHAR_BIT 8

int pack_chars(unsigned char a, unsigned char b, unsigned char c, unsigned char d) {
	
	unsigned short int result = 0;
	result &= ~(0xff << 24);
	result |= (a << CHAR_BIT * 3);
	result |= (b << CHAR_BIT * 2);
	result |= (c << CHAR_BIT * 1);
	result |= (d);

	unsigned int i;
	unsigned short int mask = 1 << CHAR_BIT - 1;

	for (i = 1; i <= CHAR_BIT * 3; i++) {
		putchar(result & mask ? '1' : '0');
		if ((i % CHAR_BIT) == 0)
			putchar(' ');
		result <<= 1;
	}
	return 0;
}


int pack_cntrl(void)
{
	unsigned char a;
	unsigned char b;
	unsigned char c;
	unsigned char d;

	printf("enter 4 chars:\t ");
	scanf("%c \t %c\t %c\t %c", &a, &b, &c, &d);

	printf("\npacked : ");
	pack_chars(a, b, c, d);
	
	return 0;
}

//int main(void) {
//	pack_cntrl();
//	return 0;
//}
