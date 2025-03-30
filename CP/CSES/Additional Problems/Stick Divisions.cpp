#include <iostream>
#include <vector>
#include <queue>
using namespace std;
 
int main () {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int x, n;
	cin >> x >> n;
	priority_queue<int, vector<int>, greater<int>> pq;
	while (n--) {
		int k; cin >> k;
		pq.push(k);
	}
	long long ans = 0;
	while (pq.size() > 1) {
		int a = pq.top();
		pq.pop();
		int b = pq.top();
		pq.pop();
		ans += a+b;
		pq.push(a+b);
	}
	cout << ans << '\n';
	return 0;
}
