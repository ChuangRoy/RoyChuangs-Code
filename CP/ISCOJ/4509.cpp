#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    long long sum = 0;
    vector <int> v(n), t(n);
    vector <long long> dp (m+1, 0);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        sum += v[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> t[i];
    }
    for (int i = 0; i < n; i++) {
        for (int ti = m; ti >= t[i]; ti--) {
            dp[ti] = max(dp[ti], dp[ti - t[i]] + v[i]);
        }
    }
    cout << sum - dp[m];
    return 0;
}