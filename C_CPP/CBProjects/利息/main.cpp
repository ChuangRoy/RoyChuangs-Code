#include <iostream>
#include <cmath>
using namespace std;

float f(int x, int n, float r) {
    if (n <= 1)
        return x * (1 + r);
    else
        return f(x, n-1, r) * (1 + r);
}

int main () {
    int x = 10000;
    int n = 10;
    float r = 0.1;
    cout << round(f(x, n, r)) << endl;
    return 0;
}