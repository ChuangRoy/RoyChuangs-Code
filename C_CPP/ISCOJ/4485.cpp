#include <bits/stdc++.h>
using namespace std;

int main () {
	ios_base::sync_with_stdio(false);cin.tie(0);
	int a, b, c, d, e, f;
	cin >> a >> b >> c;
	int t; cin >> t;
	int max = -2147483648, maxI = 1;
	int temp;
	for (int i = 1; i <= t; i++) {
		cin >> d >> e >> f;
		temp = a * d + b * e + c * f;
		if (temp > max) {
			max = temp;
			maxI = i;
		}
	}
	cout << maxI << "\n";
	return 0;
}