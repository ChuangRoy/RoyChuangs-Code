#include <bits/stdc++.h>
using namespace std;

int main () {
	ios_base::sync_with_stdio(false);cin.tie(0);
	long long x, r;
	bool y;
	cin >> r;
	r -= 1;
	bool found = 0;
	bool k = r % 2;
	const long long n = sqrt(r) + 1;
	
	for (x = 1; x <= n; x++) {
		if (k && x % 2 == 0);
		else {
			if (r % x == 0) {
				if (r / x > x+1) {
					y = (r / x - x) % 2;
					if (y){
						found = 1;
						break;
					}
				}
			}
		}
	}
	if (!found) {
		cout << "NO" << endl;
	}else{
		cout << x << " " << (r/x-x-1)/2 << endl;
	}
	return 0;
}