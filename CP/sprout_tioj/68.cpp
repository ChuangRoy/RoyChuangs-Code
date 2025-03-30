#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		priority_queue<long long, vector<long long>, greater<long long>> pq;
		while (n--) {
			int k; cin >> k;
			pq.push(k);
		}
		unsigned long long ans = 0;
		while (pq.size() > 1) {
			long long a = pq.top();
			pq.pop();
			long long b = pq.top();
			pq.pop();
			ans += a+b;
			pq.push(a+b);
		}
		cout << ans << '\n';
	}
	return 0;
}
