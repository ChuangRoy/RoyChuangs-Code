#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m; cin >> n >> m;
    vector <int> v(n), t(n);
    vector <long long> dp (m+1, 0);
    for (int i = 0; i < n; i++) {
        cin >> t[i];
        cin >> v[i];
    }
    for (int i = 0; i < n; i++) {
        for (int ti = m; ti >= t[i]; ti--) {
            dp[ti] = max(dp[ti], dp[ti - t[i]] + v[i]);
        }
    }
    cout << dp[m];
    return 0;
}