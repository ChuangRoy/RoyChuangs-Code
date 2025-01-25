#include <bits/stdc++.h>
using namespace std;

bool comp (pair<long, long> a, pair<long, long> b) {
	return a.first < b.first;
}

int main () {
	int n;
	cin >> n;
	int a, d;
	pair<long, long> p[n];
	for (int i = 0; i < n; i++) {
		cin >> a >> d;
		p[i].first = a;
		p[i].second = d;
	}
	long long sum = 0;
	long long t = 0;
	sort(p, p + n, comp);
	for (int i = 0; i < n; i++) {
		t += p[i].first;
		sum += (p[i].second - t);
	}
	cout << sum << endl;
	return 0;
}