#include <bits/stdc++.h>
using namespace std;

int main () {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	int k;
	set <int> ks;
	map <int, int> mp;
	while (n--) {
		cin >> k;
		mp [k] = mp [k] + 1;
		ks.insert(k);
	}
	for (auto i:ks) {
		cout << i << " " << mp[i] << endl;
	}
}