#include <bits/stdc++.h>

#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define pii pair<int, int>
#define ff first
#define ss second
#define pb push_back

using namespace std;
using ll = long long;

signed main ()
{
    AC
    int a, b;
    cin >> a >> b;
    vector<bool> isPrime(b + 1, 1);
    vector<int> primes;
    isPrime[0] = 0;
    isPrime[1] = 0;
    for (int i = 2; i <= b; i++) {
        if (isPrime[i]) primes.pb(i);
        for (auto p : primes) {
            if (i * p > b) break;
            isPrime[i*p] = 0;
            if (i % p == 0) break;
        }
    }
    for (auto p : primes) {
        if (p >= a) cout << p << '\n';
    }
    return 0;
}