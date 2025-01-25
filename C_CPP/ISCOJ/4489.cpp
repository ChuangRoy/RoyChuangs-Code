#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;

int main () {
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n, m;
	cin >> n >> m;
	if (n - m < m)
		m = n - m;
	unsigned long long a = 1;
	// unsigned long long b = 1;
	for (int i = n; i > n - m; i--) {
		a = (a * i) % mod;
	}
	for (int i = 1; i <= m; i++) {
		while (a % i) a += mod;
		a = a / i;
	}
	// while (a % b) a += mod;
	cout << a % mod << endl;
}