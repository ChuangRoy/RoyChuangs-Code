#include <stdio.h>
#include <stdlib.h>

int layers = 3;
int counter = 0;
unsigned short int toh[64][4];
int main () {
    for (int i = 0; i < layers; i++) {
        toh[i][0] = 1;
        toh[i][1] = 'a';
        toh[i][2] = 'b';
        toh[i][3] = 'c';
    }
    int i = 0;
    if (layers <= 0) {
        i = -1;
    }
    while (i >= 0) {
        if (i == layers - 1) {
            counter += 1;
            printf("%d Disk %d %c -> %c\n", counter, layers - i, toh[i][1], toh[i][3]);
            i -= 1;
        } else {
            if (toh[i][0] == 1) {
                toh[i+1][0] = 1;
                toh[i+1][1] = toh[i][1];
                toh[i+1][2] = toh[i][3];
                toh[i+1][3] = toh[i][2];
                toh[i][0] = 2;
                i += 1;
            }
            else if (toh[i][0] == 2) {
                counter += 1;
                printf("%d Disk %d %c -> %c\n", counter, layers - i, toh[i][1], toh[i][3]);
                toh[i][0] = 0;
                toh[i+1][0] = 1;
                toh[i+1][1] = toh[i][2];
                toh[i+1][2] = toh[i][1];
                toh[i+1][3] = toh[i][3];
                i += 1;
            }
            else
                i -= 1;
        }
    }
}
