#include <bits/stdc++.h>
using namespace std;

int main () {
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n;
	long long q;
	int a, b;
	cin >> n;
	while (n--) {
		cin >> q;
		if ( (q / 1e5 >= 1) && (q / (int)1e6 < 1) ) {
			a = q / 1000;
			b = q % 1000;
			if (b > a)
				cout << "No" << endl;
			else
				cout << "Yes" << endl;
		}else
			cout << "No" << endl;
	}
	return 0;
}