#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 1;
const int INF = 1e6 + 1;
const int mod = 1e9 + 7;

int main () {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int x;
    int c[6] = {1, 2, 3, 4, 5, 6};
    int dp[N];
    dp[0] = 1;
    cin >> x;
    for (int k = 1; k <= x; k++) {
        dp[k] = 0;
        for (int j = 0; j < 6; j++) {
            int coin = c[j];
            if (k - coin >= 0)
                dp[k] = (dp[k] + dp[k-coin]) % mod;
        }
    }
    cout << dp[x];
    return 0;
}