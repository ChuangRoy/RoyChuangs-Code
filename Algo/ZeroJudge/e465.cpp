#include <bits/stdc++.h>
using namespace std;

const int ARR_SIZE = 1e6 + 10;
vector<int> a(ARR_SIZE), dp(ARR_SIZE, 0);

int main () {
    int m, s, n;
    cin >> m >> s >> n;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    int target = m - s;
    for (int i = 0; i < n; i++) {
        for (int j = target; j >= a[i]; j--) {
            dp[j] = max(dp[j], dp[j - a[i]]+a[i]);
        }
    }
    cout << sum - dp[target];
    return 0;
}