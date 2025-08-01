#pragma gcc optimize("Ofast")
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n; cin >> n;
	vector<pair<ll, ll>> a(n);
	for (int i = 0; i < n; i++) cin >> a[i].first;
	for (int i = 0; i < n; i++) cin >> a[i].second;
	sort(a.begin(), a.end(), [](auto x, auto y) {
		return x.second * y.first > x.first * y.second;
	});
	long long prevw = 0;
	long long ans = 0;
	for (auto i : a) {
		ans += prevw * i.second;
		prevw += i.first;
	}
	cout << ans << '\n';
	return 0;
}
