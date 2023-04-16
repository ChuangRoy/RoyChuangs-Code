#include <iostream>
using namespace std;

int gcd (int m, int n) {
    if (m%n == 0)
        return n;
    else
        return gcd(n, m % n);
}

int main () {
    int m, n;
    cin >> m >> n;
    cout << gcd(m, n) << endl;
    return 0;
}