#include <bits/stdc++.h>
using namespace std;

int main () {
	ios_base::sync_with_stdio(false);cin.tie(0); 
	int t;
	cin >> t;
	while (t--) {
		int q;
		cin >> q;
		unsigned long long a[q];
		if (q < 3) {
			if (q == 1)
				cout << 1 << endl;
			else
				cout << 2 << endl;
		} else {
			a[0] = 1; a[1] = 2;
			for (int i = 2; i < q; i++) {
				a[i] = (a[i-1] + a[i-2]) % 1000000007;
			}
			cout << a[q-1] << endl;
		}
	}
	return 0;
}