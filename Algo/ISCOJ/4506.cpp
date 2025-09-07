#include <bits/stdc++.h>
using namespace std;

int main () {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int x, y;
	while (cin >> x >> y) {
		if (x < y)
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}