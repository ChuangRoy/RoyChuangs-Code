#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
const int INF = 1e6 + 1;
const int mod = 1e9 + 7;

int main () {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, x;
    int c[100];
    int dp[N];
    dp[0] = 1;
    cin >> n >> x;
    for (int i = 0; i < n; i++) cin >> c[i];
    for (int k = 1; k <= x; k++) {
        dp[k] = 0;
        for (int j = 0; j < n; j++) {
            int coin = c[j];
            if (k - coin >= 0)
                dp[k] = (dp[k] + dp[k-coin]) % mod;
        }
    }
    cout << dp[x];
    return 0;
}