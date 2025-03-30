#include <iostream>
using namespace std;

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T; cin >> T;
	while (T--) {
		long long n; cin >> n;
		if (n == 1) {
			cout << 1 << '\n';
			continue;
		}
		int a[11] = {0};
		for (int x = 9; x >= 2; x--) {
			while (n > 0 && n % x == 0) {
				n /= x;
				a[x]++;
			}
		}
		if (n > 1) {
			cout << -1 << '\n';
			continue;
		}
		for (int i = 1; i <= 9; i++) {
			for (int j = 0; j < a[i]; j++) cout << i;
		}
		cout << '\n';
	}
	return 0;
}
