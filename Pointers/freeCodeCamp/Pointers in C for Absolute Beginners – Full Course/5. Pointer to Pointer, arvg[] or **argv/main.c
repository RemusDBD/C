#include<stdio.h>


//
//pointer to pointer: **argv
//

/*
// ./a.out hello there
int main(int argc, char** argv)
{
	int j, k;

	j = 0;
	while (*(argv + j))
	{
		k = 0;
		while (*(*(argv +j) + k))
		{
			printf("%c", argv[j][k]);
			++k;
		}
		puts("");
		++j;
	}
}
*/


// pro version 

/*
int main(int ac, char** av)
{
	while (*av != NULL)
	{
		while (**av != '\0')
			printf("%c", *(*av)++);
		puts("");
		++av;
	}
}
*/

//
// arvg[] or **argv
//


void fake_main(char *av[])
//void fake_main(char** av) // work either the same

{
	while (*av)
		printf("%s\n", *av++);
}

int main()
{
	char* av[] = { "./prog", "1", "2", "3", NULL };
	// char **av1 = { "prog", "1", "2", "3"}; // can't directly point a pointer to a pointer to an array of string

	fake_main(av);
}