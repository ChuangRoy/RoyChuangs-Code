#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main () {
    const int n = 8;
    int pascal[n][n] = {0};
    int biggest = 0;
    if (n == 0) {
        cout << 0;
        return 0;
    }
    if (n == 1) {
        cout << 1;
        return 0;
    }
    pascal[0][0] = 1;
    for (int row = 1; row < n; row++)
        pascal [row] [0] = 1;
    for (int row = 1; row < n; row++) {
        for (int col = 1; col < n; col++) {
            pascal [row] [col] = pascal[row-1][col]+pascal[row-1][col-1];
            if (pascal [row] [col] > biggest)
                biggest = pascal [row] [col];
        }

    }
    const int LEN = 2 + log10(biggest);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << setw(LEN) << pascal [i] [j];
        }
        cout << endl;
    }


    return 0;
}
