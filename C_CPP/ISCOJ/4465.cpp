#include <bits/stdc++.h>
using namespace std;


int main () {
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n, m;
	cin >> n >> m;

	int a[n+2][m+2];
	memset(a, 0, sizeof(a[0][0]) * (n+2) * (m+2));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
		}
	}
	int ans[n][m];
	memset(ans, 0, sizeof(ans[0][0]) * n * m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int l = i; l <= i + 2; l++) {
				for (int m = j; m <= j+2; m++) {
					ans[i][j] += a[l][m];
				}
			}
			ans [i][j] -= a[i+1][j+1];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cout << ans[i][j] << " ";
	cout << endl;}
	return 0;
}