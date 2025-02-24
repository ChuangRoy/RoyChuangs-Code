#include <bits/stdc++.h>
using namespace std;

int main () {
	int n;
	cin >> n;
	long p[n];
	long long sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	sort(p, p+n);
	int mid = p[n/2];
	for (int i = 0; i < n; i++) {
		sum += abs(p[i] - mid);
	}
	cout << sum << endl;
	return 0;
}