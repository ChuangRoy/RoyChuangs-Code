#include <bits/stdc++.h>
using namespace std;

const int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int main () {
	int x, y;
	int graph [100][100];
	int m, n, k;
	int count = 0, direction = 0, score = 0;	
	cin >> m >> n >> k >> y >> x;
	for (int i = 0; i < m; i++)	{
		for (int j = 0; j < n; j++) {
			cin >> graph [i][j];
		}
	}
	bool flag = 1, modflag = 1;
	while (graph [y][x] != 0) {
		if (flag) {
			score += graph [y][x];
			flag = 0;
			modflag = 1;
		} else {
			int dx = d[direction % 4][1], dy = d[direction % 4][0];
			if (score % k == 0 && modflag) {
				direction += 1;
				modflag = 0;
			} else if (x + dx > n - 1 || y + dy > m - 1 || x + dx < 0 || y + dy < 0) {
				direction += 1;
			} else if (graph [y + dy][x + dx] == -1) {
				direction += 1;
			} else {
//				cout << ">" << x << " " << y << " " << dx << " " << dy << " " << score << endl;
				graph [y][x] -= 1;
				x += dx;
				y += dy;
				flag = 1;
				count += 1;
			}
		}
	}
	cout << count << endl;
	
	return 0;
}
