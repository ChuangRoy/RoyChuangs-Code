#include <bits/stdc++.h>
using namespace std;

const int arr_size = 1e5;
const int inf = 1e9;
int dp[arr_size];
int h[arr_size];

int main ()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> h[i];
    }
    dp[0] = 0;
    for (int i = 1; i < n; i++) {
        int min_cost = inf;
        for (int j = 1; j <= k; j++) {
            if (i - j >= 0) {
                min_cost = min(min_cost, dp[i-j] + abs(h[i] - h[i-j]));
            }
        }
        dp[i] = min_cost;
    }
    cout << dp[n-1] << '\n';
    return 0;
}