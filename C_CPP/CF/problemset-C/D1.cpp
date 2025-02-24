#include <bits/stdc++.h>
using namespace std;
 
bool comp (pair<long, long> a, pair<long, long> b) {
	return a.second < b.second;
}
 
int main () {
	int n;
	cin >> n;
	int a, b;
	pair<long, long> p[n];
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		p[i].first = a;
		p[i].second = b;
	}
	sort(p, p + n, comp);
	long long t = 0;
	long long cnt = 0;
	for (int i = 0; i < n; i++) {
		if (p[i].first >= t) {
			t = p[i].second;
			cnt++;
		}
	}
	cout << cnt << endl;
	return 0;
}