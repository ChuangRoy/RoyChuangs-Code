#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define ALL(x) begin(x),end(x)
#define pb emplace_back

const int mod = 1e9 + 7;

ll dp[1000005][2];

int main () {
    AC
    int maxN = 1;
    dp[1][0] = 1;
    dp[1][1] = 1;
    int t; cin >> t;
    int n;
    while (t--) {
        cin >> n;
        if (n <= maxN) {
            cout << (dp[n][0] + dp[n][1]) % mod << '\n';
            continue;
        }
        for (int i = maxN+1; i <= n; i++) {
            dp[i][0] = (dp[i-1][0] * 2 % mod + dp[i-1][1]) % mod;
            dp[i][1] = (dp[i-1][0] + dp[i-1][1] * 4 % mod) % mod;
        }
        cout << (dp[n][0] + dp[n][1]) % mod << '\n';
        maxN = n;
    }
    return 0;
}