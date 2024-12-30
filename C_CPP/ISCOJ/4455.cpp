// https://iscoj.fg.tp.edu.tw/problems/4455
#include <bits/stdc++.h>
using namespace std;

int main () {
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n;
	cin >> n;
	int a[n];
	int i = n;
	while (i--)
		cin >> a[n-i-1];
	vector<int> base;
	base.push_back(a[0]);
	bool err;
	for (i = 1; i < n; i++) {
		err = 1;
		for (int j = 0; j < base.size() && err; j++) {
			if (base[j] > a[i]) {
				// cout << ">" << base [j] << ' ' << a[i] << endl;
				base[j] = a[i];
				err = 0;
			}
		}
		if (err) {
			base.push_back(a[i]);
			// cout << ">" << a[i] << endl;
		}
	}
	cout << base.size() << endl;
	return 0;
}