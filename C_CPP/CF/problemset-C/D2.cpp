// unfinished

#include <bits/stdc++.h>
using namespace std;

bool comp (pair<long, long> a, pair<long, long> b) {
	return a.second < b.second;
}

int main () {
	int n, k;
	cin >> n >> k;
	int a, b;
	pair<long, long> p[n];
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		p[i].first = a;
		p[i].second = b;
	}
	sort(p, p + n, comp);
	long long t[k];
	memset(t, 0, sizeof(t[0]) * k);
	long long cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			if (p[i].first >= t[j]) {
				t[j] = p[i].second;
				cnt++;continue;
			}
		}
	}
	cout << cnt << endl;
	return 0;
}