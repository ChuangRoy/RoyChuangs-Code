#include <bits/stdc++.h>
using namespace std;

const int arr_size = 1e6 + 10;
const int inf = 1e9;

int dp[arr_size];
int main () {
	int n; cin >> n;
	dp[0] = 0;
	for (int i = 1; i <= n; i++) {
		dp[i] = inf;
		for (int j = i; j > 0; j /= 10) {
			dp[i] = min(dp[i - j % 10] + 1, dp[i]);
		}
	}
	cout << dp[n];
	return 0;
}