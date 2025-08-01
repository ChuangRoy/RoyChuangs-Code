#include <bits/stdc++.h>
using namespace std;

const int N = 5010;
int record [N][N];
const int INF = 6e5;

/*
TWXFUABGBNLTBFNSUVQW
GPNJILFXJUIZPLTVUIB
*/

int main () {
	string a, b;
	cin >> a >> b;
	int m = a.length(), n = b.length();

	for (int i = 0; i < N; i++) record[i][0] = i;
	for (int i = 0; i < N; i++) record[0][i] = i;
	
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			int dis = INF;
			int cost = 0;
			if (a[i-1] != b[j-1]) cost = 1;
			dis = min(dis, record[i-1][j]+1);
			dis = min(dis, record[i][j-1]+1);
			dis = min(dis, record[i-1][j-1]+cost);
			record [i][j] = dis;
		}
	}
	cout << record[m][n];
	return 0;
}
