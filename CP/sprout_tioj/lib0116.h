void solve(int N, int M);
void Report(int val);
int GetVal(int x, int y);

#include <iostream>
using namespace std;

int matrix [4][5]
    = {{74, 59, 36, 28, 51},
       {36, 63, 15, 25, 17},
       {71, 64, 95, 43, 56},
       {72, 62, 30, 24, 74}};
       
int main () {
    solve(4, 5);
}

int GetVal (int y, int x) {
    x--; y--;
    cerr << "GetVal: " << x << ' ' << y << ' ' << matrix[y][x] << endl;
    return matrix[y][x];
}

void Report (int val) {
    cerr << "Report: " << val << endl;
}