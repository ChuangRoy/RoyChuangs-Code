#include <stdio.h>
#include <stdlib.h>

int main () {
    int *p;
    int a = 1;
    p = &a;
    printf("a is %d \n", a);
	printf("pointer of a is %d \n", *p);
}