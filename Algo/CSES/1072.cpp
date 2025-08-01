#include <iostream>
#define SQ(x) ((x)*(x))
using namespace std;

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n; cin >> n;
	for (long long x = 1; x <= n; x++) {
		cout << SQ(x)*(SQ(x)-1)/2 - 4*(x-1)*(x-2) << '\n';
	}
	return 0;
}
