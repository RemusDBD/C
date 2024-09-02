#include <stdio.h>

// Function to print different data types using void pointers
void printData(void* data, char dataType)
{
	if (dataType == 'i')
		printf("(3)\nInteger: %d\n", *((int*)data));
	else if (dataType == 'f')
		printf("Float: %E\n", * ((float*)data));
	else if (dataType == 'c')
		printf("Character: %c\n", *((char*)data));
	else
		printf("Unknown data type. \n");
}

int main()
{
	/*				(1)					*/

	int nb;
	int* ptr;

	// Initialize an integer variable nb with a binary value
	nb = 0b100000000;	// Binary literal for 256
	ptr = &nb;			// Pointer to the integer nb

	// Print the value of nb and the first two bytes of nb interpreted as short
	printf("(1)\n%d %d\n",
		*ptr,			// Dereferencing ptr to get the value of nb
		*(short*)ptr); // Casting ptr to short* and dereferencing

	/*				(2)				*/

	short	c;
	short* pc;  

	// Initialize a short variable c with a decimal value
	c = 16896;	// Assigning a short integer
	pc = &c;	// Pointer to the short c


	// Print the addresses of pc and the addresses after adding multiples of sizeof(type)
	printf("(2)\n%p\n%p\n%p\n%p\n",
		pc,			// Address of c
		// Pointer arithmetic : pc + ( n * sizeof (type))
		pc + 1,		// datasize = short -> 1 :¡@add 2 byte 
		pc + 2,		// datasize = short -> 2 :¡@add 4 byte 
		pc + 3);	// datasize = short -> 3 :¡@add 6 byte 

	/*				(3)				*/

	int intValue = 42;

	// Print different data types using void pointers
	printData(&intValue, 'i');
	printData(&intValue, 'f');
	printData(&intValue, 'c');
}