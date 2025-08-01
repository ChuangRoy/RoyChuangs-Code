#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 1;
const int INF = 1e6 + 1;

signed main () {
    int n, x = 0;
    int c[100];
    bool dp[N];
    int ans = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> c[i];
        x += c[i];
    }
    for (int i = 0; i < N; i++) dp[i] = 0;
    dp [0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = x - c[i]; j >= 0; j--) {
            if (dp[j]) {
                if (dp[j+c[i]] == 0) {
                    ans++;
                }
                dp[j+c[i]] = 1;
            }
        }
    }
    cout << ans << "\n";
    for (int i = 1; i <= x; i++) {
        if (dp[i]) {
            cout << i << " ";
        }
    }
    return 0;
}