#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#include <algorithm>
#define fastio cin.tie(0)->sync_with_stdio(false)
#define eb emplace_back
#define test(x) cerr << "Line(" << __LINE__ << ") " #x << ' ' << x << endl
#define printv(x) { \
	for (auto i : x) cout << i << ' '; \
	cout << endl; \
}
#define ALL(x) x.begin(), x.end()

using namespace std;
typedef long long ll;

const int dx[] = {1, 0, 1};
const int dy[] = {1, 1, 0};

void solve () {
    int n, m;
    cin >> n >> m;
    vector dp(n + 1, vector<ll> (m + 1, 0));
    vector rec(n + 1, vector<int> (m + 1, -1));
    vector<int> arr1(n+1), arr2(m+1);
    for (int i = 1; i <= n; i++) cin >> arr1[i];
    for (int i = 1; i <= m; i++) cin >> arr2[i];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (arr1[i] == arr2[j]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                rec[i][j] = 0;
            } else if (dp[i-1][j] > dp[i][j-1]) {
                dp[i][j] = dp[i-1][j];
                rec[i][j] = 1;
            } else {
                dp[i][j] = dp[i][j-1];
                rec[i][j] = 2;
            }
        }
    }
    cout << dp[n][m] << '\n';
    vector<int> lcs;
    int yy = n, xx = m;
    while (yy > 0 && xx > 0) {
        auto cur = rec[yy][xx];
        if (cur == 0) {
            lcs.eb(arr1[yy]);
        }
        xx -= dx[cur];
        yy -= dy[cur];
    }
    reverse(ALL(lcs));
    printv(lcs);
}

int main () {
    fastio;
    solve();
    return 0;
}