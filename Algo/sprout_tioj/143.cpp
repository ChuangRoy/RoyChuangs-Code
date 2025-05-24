#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define AC cin.tie(0)->sync_with_stdio(false);

using namespace std;

int w[100], v[100];
int dp[10004];

void solve () {
    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> w[i] >> v[i];
    }
    memset(dp, 0x3f3f3f3f, sizeof(dp));
    dp[0] = 0;
    for (int i = 0; i < N; i++) for (int j = 10000; j >= 1; j--) {
        if (v[i] <= j) {
            dp[j] = min(dp[j-v[i]]+w[i], dp[j]);
        }
    }
    int ans = 0x3f3f3f3f;
    for (int i = 1; i <= 10000; i++) {
        if (dp[i] <= M)
            ans = i;
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
