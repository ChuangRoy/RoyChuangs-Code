#include <bits/stdc++.h>
using namespace std;

int main () {
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	int a[n], b[m];
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < m; i++) cin >> b[i];
	int ia = 0, ib = 0;
	sort(a, a + n);
	sort(b, b + m);
	int ans = 0;
	while (ia < n && ib < m) {
		if (b[ib] - k > a[ia]) {
			ia++;
		} else if (a[ia] > b[ib] + k) {
			ib++;
		} else {
			ia++;
			ib++;
			ans++;
		}
	}
	cout << ans << "\n";
	return 0;
}