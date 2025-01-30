#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;

int power2 (int n) {
    if (n == 1) return 2;
    if (n == 0) return 1;
    long long half = power2(n / 2);
    long long half_squared = (half * half) % mod;
    if (n % 2) return (half_squared * 2) % mod;
    else return half_squared;
}

int main ()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    cout << power2(n) << '\n';
    return 0;
}