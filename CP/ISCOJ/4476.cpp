#include <bits/stdc++.h>
using namespace std;

int main () {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n;
	cin >> n;
	int k;
	map <int, int> mp;
	while (n--) {
		cin >> k;
		if (mp [k] == 0) {
			cout << "N" << endl;
			mp[k] = 1;
		} else {
			cout << "Y " << mp[k] << endl;
			mp [k] ++;
		}
	}
}