#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define AC cin.tie(0)->sync_with_stdio(false);

using namespace std;

int w[100], v[100];

void solve () {
    int N, M, K;
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++) {
        cin >> w[i] >> v[i];
    }
    vector<vector<int>> dp(K + 1, vector<int> (M + 1, 0));
    for (int i = 0; i < N; i++) {
        for (int k = K; k >= 1; k--) for (int j = M; j >= 1; j--) {
            if (w[i] <= j) {
                dp[k][j] = max(dp[k-1][j-w[i]]+v[i], dp[k][j]);
            }
        }
    }
    int ans = 0;
    for (int k = 1; k <= K; k++) {
        ans = max(dp[k][M], ans);
    }
    cout << ans << '\n';
}

int main () {
    AC
    int T; cin >> T;
    while (T--)
        solve();
    return 0;
}
