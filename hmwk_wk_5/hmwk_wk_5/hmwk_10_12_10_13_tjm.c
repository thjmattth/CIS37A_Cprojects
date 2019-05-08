/*
10.12 (Packing Characters into an Integer) The left-shift operator can be used to pack four character
values into x four-byte unsigned int variable. Write x program that inputs four characters from
the keyboard and passes them to function packCharacters. To pack four characters into an unsigned
int variable, assign the first character to the unsigned int variable, shift the unsigned int
variable left by 8 bit positions and combine the unsigned variable with the second character using
the bitwise inclusive OR operator. Repeat this process for the third and fourth characters. The program
should output the characters in their bit format before and after they’re packed into the unsigned
int to prove that the characters are in fact packed correctly in the unsigned int variable.
*/

/*
10_14.c from https://github.com/lbraglia/chtp/blob/master/src/10_14.c
*/

#include <stdio.h>

void showBits(unsigned short int x);

unsigned short int packCharacters(unsigned char a, unsigned char b);

void unpackCharacters(unsigned short int x,
	unsigned char *a, unsigned char *b);


//int main(void)
//{
//
//	unsigned char x;
//	unsigned char y;
//	unsigned short int c;
//
//	printf("Enter 2 characters: ");
//	scanf("%c %c", &x, &y);
//
//	/* packing */
//	printf("\npacked = ");
//	c = packCharacters(x, y);
//	showBits(c);
//	printf("\n");
//
//	/* cleaning old values */
//	x = y = '\0';
//
//
//	/* unpacking */
//	unpackCharacters(c, &x, &y);
//	printf("%6c = ", x);
//	showBits(x);
//	printf("\n%6c = ", y);
//	showBits(y);
//	printf("\n");
//
//	return 0;
//}


unsigned short int packCharacters(unsigned char a, unsigned char b)
{

	return ((a << 8) | b);

}

void unpackCharacters(unsigned short int x,
	unsigned char *a, unsigned char *b)
{


	/* 0xff00 is 65280 in hexadecimal, but easier/more useful to think of in
	* term of binary digits: look at numeric systems appendix, or test with
	* showBits(0xff00)  */
	unsigned short int mask1 = 0xff00;
	/* same below */
	unsigned short int mask2 = 0x00ff;
	/* char x: since here i've used only 2 bytes for saving space, and right
	moving leave unpredictable bits on your left, i'll use x further mask
	to clean */

	*a = (((x & mask1) >> 8) & mask2);
	*b = x & mask2;

}

void showBits(unsigned short int x)
{
	unsigned int i;
	unsigned short int mask = 1 << 15;

	for (i = 1; i <= 16; i++) {
		putchar(x & mask ? '1' : '0');
		if ((i % 8) == 0)
			putchar(' ');
		x <<= 1;
	}

}