#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

/*

4
....
.*..
...*
*...

*/
long long a[1010][1010];
string grid[1010];

int main () {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> grid[i];
	}

	if (grid[0][0] == '*') {
		cout << 0;
		return 0;
	}
	a[0][0] = 1;
	for (int i = 1; i < n; i++) {
		if (grid[i-1][0] != '*' && grid[i][0] != '*') { 
			a[i][0] = a[i-1][0];
		}
		else {
			a[i][0] = 0;
		} 
	}
	for (int i = 1; i < n; i++)
		if (grid[0][i-1] != '*' && grid[0][i] != '*') { 
			a[0][i] = a[0][i-1];
		}
		else {
			a[0][i] = 0;
		}

	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			if (grid[i][j] == '*') {
				a[i][j] = 0;
			}
			else {
				a[i][j] = (a[i-1][j] + a[i][j-1]) % mod;
			}
		}
	}

	cout << a[n-1][n-1] << endl;
	return 0;
}
