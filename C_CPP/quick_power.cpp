#include <bits/stdc++.h>
using namespace std;

int qpow (unsigned long long a, int b, int p)
{
    unsigned long long res = 1;
    while (b) {
        if (b & 1) res = (res * a) % p;
        b >>= 1;
        a = a * a % p;
    }
    return res;
}

int main ()
{
    cout << qpow(10, 100, 1e9+7) << endl;
    return 0;
}