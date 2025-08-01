#pragma GCC optimize("Ofast")
#include <iostream>
#include <utility>
#include <cmath>
#include <algorithm>
#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define pb emplace_back
#define ALL(x) begin(x),end(x)
#define MP(x) make_pair((x), (x))
#define SQ(x) ((x)*(x))
#define SZ(x) ((long long) x.size())

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve () {
    unsigned long long A;
    cin >> A;
    ll root = sqrt(A);
    vector<bool> isPrime(root+1, 1);
    vector<ll> primes;
    isPrime[0] = 0;
    isPrime[1] = 0;
    for (int i = 2; i <= root; i++) {
        if (isPrime[i]) primes.pb(i);
        for (auto p : primes) {
            if (i * p > root) break;
            isPrime[i*p] = 0;
            if (i % p == 0) break;
        }
    }
    vector<int> nums;
    for (auto p : primes) {
        if (SQ(p) < A) {
            nums.pb(p);
        }
    }
}

int main () {
    AC
    int T; cin >> T;
    while (T--)
        solve();
    return 0;
}