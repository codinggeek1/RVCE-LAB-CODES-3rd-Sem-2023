//add.c
int add(int a, int b)
{
	return(a+b);
}


//sub.c
int sub(int a, int b)
{
   return(a-b);
}

//main.c
#include <stdio.h>
#include "calc.h"

int main()
{
	printf("add is %d\n",add(5,6));
	printf("sub is %d\n",sub(4,1));
	return 0;
}

//calc.h
int add(int a, int b);
int sub(int a, int b);


//static
//gcc -c add.c
//gcc -c sub.c
//gcc -c main.c

//ar rcs libbasic.a sub.o add.o
//gcc -o pgm main.o -L. libbasic.a
//./pgm


//dynamic
//gcc -fPIC -c add.c
//gcc -fPIC -c sub.c
//gcc -c main.c
//gcc -shared -o libos.so add.o sub.o
//gcc -o dpgm main.o libos.so
//sudo cp libos.so/usr/lib
//./dpgm
