#include<stdio.h>
#include<stdlib.h>

//Program to show HEAP vs STACK memory
void bar()
{
	int nb;

	nb = 1337;
}


int* foo()
{
	int *n;

	n = malloc(sizeof(int));
	*n = 42;
	return n;
}

int main()
{
	int* pn;

	pn = foo();
	printf("%d\n", *pn);
	bar();
	printf("%d\n", *pn);
}

/*	GNU extension
int main(int argc, char** argv)
{
	int		n;
	void*	ptr;

	n = 256;
	ptr = &n;

	for (int i = 0; i < sizeof n; ++i)
	{
		printf("%d\n", *(unsigned char*)ptr);
		ptr++;
	}

}
*/