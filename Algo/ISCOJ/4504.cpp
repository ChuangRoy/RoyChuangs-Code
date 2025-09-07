#include <bits/stdc++.h>
using namespace std;

int main () {
	ios_base::sync_with_stdio(false);cin.tie(0); 
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		map <int, bool> mp;
		int c = 0;
		while (n != 1 && mp[n] == 0) {
			if (n % 2) {
				mp [n] = 1;
				n = (n * 3 + 1) % 2657;
			} else {
				mp [n] = 1;
				n = (n / 2) % 2657;
			}
			c++;
		}
		if (mp[n] == 1)
			cout << "forever" << endl;
		else
			cout << c << endl;
	}
	return 0;
}