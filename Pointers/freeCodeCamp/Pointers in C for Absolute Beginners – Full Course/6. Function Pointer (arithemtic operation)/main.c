#include <stdio.h>
#include <windows.h>
#ifndef _UNISTD_H
#define _UNISTD_H    1

/* This is intended as a drop-in replacement for unistd.h on Windows.
 * Please add functionality as needed.
 * https://stackoverflow.com/a/826027/1202830
 */

#include <stdlib.h>
#include <io.h>
#include <process.h> /* for getpid() and the exec..() family */
#include <direct.h> /* for _getcwd() and _chdir() */

#define srandom srand
#define random rand

 /* Values for the second argument to access.
	These may be OR'd together.  */
#define R_OK    4       /* Test for read permission.  */
#define W_OK    2       /* Test for write permission.  */
	//#define   X_OK    1       /* execute permission - unsupported in windows*/
#define F_OK    0       /* Test for existence.  */

#define access _access
#define dup2 _dup2
#define execve _execve
#define ftruncate _chsize
#define unlink _unlink
#define fileno _fileno
#define getcwd _getcwd
#define chdir _chdir
#define isatty _isatty
#define lseek _lseek
/* read, write, and close are NOT being #defined here, because while there are file handle specific versions for Windows, they probably don't work for sockets. You need to look at your app and consider whether to call e.g. closesocket(). */

#ifdef _WIN64
#define ssize_t __int64
#else
#define ssize_t long
#endif

#define STDIN_FILENO 0
#define STDOUT_FILENO 1
#define STDERR_FILENO 2
/* should be in some equivalent to <sys/types.h> */
typedef __int8            int8_t;
typedef __int16           int16_t;
typedef __int32           int32_t;
typedef __int64           int64_t;
typedef unsigned __int8   uint8_t;
typedef unsigned __int16  uint16_t;
typedef unsigned __int32  uint32_t;
typedef unsigned __int64  uint64_t;



#endif /* unistd.h  */


int foo()
{
	return 42;
}

// Function prototypes
int add(int a, int b);
int substract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);

// Function to perform arithemtic operation using function pointer
int performArithmetic(int a, int b, int(*operation)(int, int))
{
	return operation(a, b);
}

int main()
{
	int nb;

	nb = 13;
	printf("%p %p\n", foo, &nb);

	Sleep(100);

	int a = 10, b = 5;
	// Call the performArithmetic function using function pointers
	int sum = performArithmetic(a, b, add);
	int difference = performArithmetic(a, b, substract);
	int product = performArithmetic(a, b, multiply);
	int quotient = performArithmetic(a, b, divide);

	printf("Sum of %d and %d:			%d\t | Sum address %p\n", a, b, sum, add);
	printf("Difference of %d and %d:	%d\t | Difference address %p\n", a, b, difference, substract);
	printf("Product of %d and %d:		%d\t | Product address %p\n", a, b, product, multiply);
	printf("Quotient of %d and %d:		%d\t | Quotient address %p\n", a, b, quotient, divide);

	return 0;
}

int add(int a, int b)
{
	return a + b;
}

int substract(int a, int b)
{
	return a - b;
}

int multiply(int a, int b)
{
	return a * b;
}

int divide(int a, int b)
{
	return a / b;
}