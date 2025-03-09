#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
const int INF = 1e6 + 1;

int main () {
    int n, x;
    int c[100];
    int dp[N];
    dp[0] = 0;
    cin >> n >> x;
    for (int i = 0; i < n; i++) cin >> c[i];
    for (int k = 1; k <= x; k++) {
        dp [k] = INF;
        for (int j = 0; j < n; j++) {
            int coin = c[j];
            if (k - coin >= 0)
                dp[k] = min(dp[k], dp[k - coin] + 1);
        }
    }
    if (dp [x] == INF)
        cout << -1;
    else
        cout << dp[x];
    return 0;
}