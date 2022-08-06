#include <stdio.h>

int main () {
    int i1, i2, i3;
    long j1, j2, j3;
    i1 = 2147483647;
    i2 = i1 + 1;
    i3 = i2 - 1;
    printf("i1 = %d\n", i1);
    printf("i2 = %d\n", i2);
    printf("i3 = %d\n", i3);
    
    j1 = 2147483647;
    j2 = j1 + 1;
    j3 = j2 -1;
    printf("j1 = %d\n", j1);
    printf("j2 = %d\n", j2);
    printf("j3 = %d\n", j3);
    
    return 0;
}