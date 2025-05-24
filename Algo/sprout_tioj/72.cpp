#include <iostream>
using namespace std;

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		int cnt = 1;
		int last;
		cin >> last;
		n--;
		while (n--) {
			int h; cin >> h;
			if (n == 0) {
				if (cnt % 2) break;
				if (h > last) {
					cnt++;
				} else {
					cnt--;
				}
				break;
			}
			if (cnt % 2) {
				if (h < last) {
					cnt++;
				}
				last = h;
			} else {
				if (h > last) {
					cnt++;
				}
				last = h;
			}
		}
		cout << cnt << '\n';
	}
	return 0;
}
