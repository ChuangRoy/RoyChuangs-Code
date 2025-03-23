#include <bits/stdc++.h>
using namespace std;

const int arr_size = 1e5;
int dp[arr_size];
int h[arr_size];

int main ()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    cin >> h[0] >> h[1];
    dp[0] = 0;
    dp[1] = abs(h[0] - h[1]);
    for (int i = 2; i < n; i++) {
        cin >> h[i];
        dp[i] = min(dp[i-2]+abs(h[i-2]-h[i]), dp[i-1]+abs(h[i-1]-h[i]));
    }
    cout << dp[n-1] << '\n';
    return 0;
}