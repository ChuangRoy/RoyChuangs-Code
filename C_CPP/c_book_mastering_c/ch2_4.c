#include <stdio.h>
#include <stdlib.h>

int main () {
    int i, j, k;
    i = 013;
    j = 026;
    printf("i = %d \n", i);
    printf("j = %d \n", j);
    
    i = 0x28;
    j = 0x3A;
    k = 0x3a;
    printf("i = %d \n", i);
    printf("j = %d \n", j);
    printf("k = %d \n", k);
    
    return 0;
}