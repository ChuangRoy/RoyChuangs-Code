#include <bits/stdc++.h>
using namespace std;

int main () {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t;
	cin >> t;
	int n;
	bitset<32> a;
	while (t--) {
		cin >> n;
		a = bitset<32>(n);
		cout << a.count() << endl;
	}
}