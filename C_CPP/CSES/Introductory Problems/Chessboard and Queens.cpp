#include <bits/stdc++.h>
using namespace std;
const int n = 8;
bool column[n], diag1[n*n], diag2[n*n];
bool chessboard [n][n];
int cnt = 0;

void search(int y) {
	if (y == n) {
		cnt++;
		return;
	}
	for (int x = 0; x < n; x++) {
		if (column[x] || diag1[x+y] || diag2[x-y+n-1] || chessboard[y][x]) continue;
		column[x] = diag1[x+y] = diag2[x-y+n-1] = 1;
		search(y+1);
		column[x] = diag1[x+y] = diag2[x-y+n-1] = 0;
	}
}

int main () {
	// cnt = 0;
	ios_base::sync_with_stdio(false);cin.tie(0);
	string s;

	for (int i = 0; i < n; i++) {
		cin >> s;
		column [i] = 0;
		for (int j = 0; j < n; j++) {
			diag1[i+j] = 0;
            diag2[i-j+n-1] = 0;
            if (s[j] == '*')
				chessboard[i][j] = 1;
			else
				chessboard[i][j] = 0;
		}
	}
	search(0);
	cout << cnt << endl;
	return 0;
}