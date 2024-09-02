#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

#define SIZE 100

void foo(int *arrr[])
{
	printf("All foo here!\n");
}

// size necessary
void print_elements(int*y, int size)
{
	printf("%zu\n", sizeof y);
	for (int i = 0; i < size; ++i)
		printf("%d\n", y[i]);
}


int main()
{	
	puts("Array & Pointer\n");

	puts("Array");

	// array
	int arr[10]; // allocating 10*4 = 40 bytes to arr
	arr[0] = 42;
	arr[1] = 1337;
	arr[2] = -21;

	/*for (int i = 0; i < 10; ++i)
		printf("%d\n", *arr++); // cannot change base address directly into an array*/


	//In the stack : YES
	printf("The address of the array %p\n", arr);
	//cannot increase arr : YES

	//sizeof !
	printf("%zu\n", sizeof(arr));

	//&
	printf("%p\n", &arr);
	printf("%p\n", arr);

	//Pointer arithmetic
	printf("%p\n", &arr + 1);
	printf("%p\n", &arr + 1);


	puts("\n");

	puts("Pointer");

	// Fake array
	int* ptr = alloca(sizeof(int) * 10);

	*(ptr + 0) = 42;
	*(ptr + 1) = 1337;
	*(ptr + 2) = -21;

	/*for (int i = 0; i < 10; ++i)
		printf("%d\n", *ptr++);*/

	//In the stack : YES
	printf("The address of the fake %p\n", ptr);
	//cannot increase ptr : YES

	//sizeof !
	printf("%zu\n", sizeof(ptr));

	//&
	printf("%p\n", &ptr);
	printf("%p\n", ptr);

	//Pointer arithmetic
	printf("%p\n", &ptr + 1);
	printf("%p\n", ptr + 1);

	puts("\n");

	//
	// 
	// Array Decay into a pointer
	//
	//
	puts("Array Decay into a pointer");

	int v[10];
	
	v[1] = 42;
	printf("%d\n", *(v + 1));
	printf("%d\n", *(1 + v));
	printf("%d\n", 1[v]);
	printf("%d\n", v[1]);
	printf("%c\n", "hello"[0]); // array indexing
	printf("%c\n", *"hello"); 
	printf("%c\n", 2["hello"]);

	puts("\n");

	int arrr[1000];
	foo(arrr);

	puts("\nanchor size \n");

	// anchor size

	int y[SIZE];

	for (int i = 0; i < SIZE; ++i)
		y[i] = rand() % 101;

	print_elements(y, SIZE);

}