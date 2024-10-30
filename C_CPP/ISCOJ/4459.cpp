// https://iscoj.fg.tp.edu.tw/problems/4459
#include <bits/stdc++.h>
using namespace std;

// C(m+n-2, n-1)
const int mod = 1e9 + 7;

int main () {
	int n, m;
	cin >> n >> m;
	long long a[n][m];
	for (int i = 0; i < n; i++)
		a[i][0] = 1;
	for (int i = 0; i < m; i++)
		a[0][i] = 1;
	for (int i = 1; i < n; i++)
		for (int j = 1; j < m; j++)
			a[i][j] = (a[i-1][j] + a[i][j-1]) % mod;
	cout << a[n-1][m-1] << endl;
	return  0;
}