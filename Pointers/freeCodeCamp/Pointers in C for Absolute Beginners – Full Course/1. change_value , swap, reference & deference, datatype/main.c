#include <stdio.h>
#include <time.h>
#include <stdlib.h>

/* area for define */

#define SIZE_ARRAY 50
typedef struct s_fat_boy // for passing by reference
{
	char v[SIZE_ARRAY];
}			 t_fat_boy;

typedef struct s_big // for datatype showcase
{
	int v[1000];
}		  t_big;

void change_value(int *nb);
void swap(int* n, int* n1)
{
	int tmp;

	tmp = *n;
	*n = *n1;
	*n1 = tmp;
}

void find_42(t_fat_boy fat_boy)
{
	int i;

	i = 0;
	while (1)
	{
		if (fat_boy.v[i] == 42)
		{
			printf("42 is in position %d\n", i);
			break;
		}
		++i;
	}
}


int main()
{
	//nb for change_value
	int nb;
	//a, b for swap
	int a;
	int b;
	//n, pn, ppn, pppn for declaration = instruction manual
	int n;
	int* pn; // single pointer -> declares a pointer called pn that points to an integer.
	int** ppn; // double pointer -> pointer to a pointer and holds the address pn
	int*** pppn; // triple pointer -> pointer to a double pointer and holds the address ppn

	/* area for variable */
	nb = 42;		// variable for change_value
	a = 42;			// variable for swap
	b = 1337;		// variable for swap
	n = 42;			// variable for dereference
	pn = &n;		// variable for dereference
	ppn = &pn;		// variable for dereference
	pppn = &ppn;	// variable for dereference

	/* area for function */

	change_value(&nb); // call change_value function

	printf("nb : %d\n", nb); // print out change_value of nb
	printf("before swap : a->%d\tb->%d\n", a, b); // print out original a, b value
	swap(&a, &b);
	printf("after swap : a->%d\tb->%d\n", a, b); // print out swapped a, b value

	printf("dereferenced address of n : %p == %p\n", **pppn, pn); // print out the (twice) dereferenced address 

	// function to show passing by reference 
	t_fat_boy fat_boy;
	srand(time(NULL));
	for (int i = 0; i < SIZE_ARRAY; ++i) fat_boy.v[i] = i;
	fat_boy.v[rand() % SIZE_ARRAY] = 42;;
	find_42(fat_boy); 


	// function to show pointer to have different data types on the same size
	//		datatype | variable 
			char		c;
			short		sh;
			int			in;
			double		d;
			t_big		big;

	printf("%zu ptr char\n"
		"%zu ptr short\n"
		"%zu ptr int\n"
		"%zu ptr double\n"
		"%zu ptr big struct\n",
		sizeof(&c),
		sizeof(&sh),
		sizeof(&in),
		sizeof(&d),
		sizeof(&big));
}

void change_value(int *foobar)
{
	*foobar = 1337;
}

