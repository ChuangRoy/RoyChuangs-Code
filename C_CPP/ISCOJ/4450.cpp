// ISCOJ 4450 https://iscoj.fg.tp.edu.tw/problems/4450

#include <bits/stdc++.h>
using namespace std;

int main () {
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n;
	cin >> n;
	int i = n, si;
	int a[n+1];
	while(i--) {
		cin >> si;
		a [si] = n - i;
	}
	long c = a[1];
	for (i = 2; i <= n; i++) {
		c += abs(a[i] - a[i-1]);
	}
	cout << c << endl;
}