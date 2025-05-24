#pragma gcc optmize("Ofast")
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T; cin >> T;
	while (T--) {
		int n; cin >> n;
		vector<pair<int, int>> a(n);
		int cooktime = 0, eattime = 0;
		for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
		sort(a.begin(), a.end(), [](auto x, auto y) {
			return x.second > y.second;
		});
		cooktime += a[0].first;
		for (int i = 1; i <= n; i++) {
			eattime = max(eattime, cooktime+a[i-1].second);
			if (i < n)
				cooktime += a[i].first;
		}
		cout << eattime << '\n';
	}
	return 0;
}
