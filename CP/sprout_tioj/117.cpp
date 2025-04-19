#pragma GCC optimize("Ofast")
#include "lib0117.h"

int matrix [1024][1024];

void dnc (int N) {
    if (N == 2) {
        matrix[0][0] = 1;
        matrix[0][1] = 2;
        matrix[1][0] = 3;
        matrix[1][1] = 1;
        return;
    }
    int m = N / 2;
    dnc(m);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j+m] = matrix[i][j] + N;
            matrix[i+m][j+m] = matrix[i][j];
            if (matrix[i][j] == 1) {
                matrix[i+m][j] = N;
            } else {
                matrix[i+m][j] = matrix[i][j] + N;
            }
        }
    }
}

void solve (int N) {
    dnc(N);
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            Report(matrix[i][j]);
        }
    }
}
