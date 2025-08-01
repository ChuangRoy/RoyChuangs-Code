#pragma GCC optimize("Ofast")
#include <iostream>
#include <climits>
#define AC cin.tie(0)->sync_with_stdio(false);
#define err(x) cerr << #x << ": " << x << endl;

using namespace std;
typedef long long ll;

const ll inf = LLONG_MAX;
ll grid[1002][1002];
bool visited[1002][1002];
ll ans[1002][1002];

ll Cal(int y, int x) {
    if (visited[y][x]) return ans[y][x];
    visited[y][x] = 1;
    ans[y][x] = grid[y][x];
    int dx[] = {0, 0, -1, 1, -1, 1, -1, 1};
    int dy[] = {-1, 1, 0, 0, -1, -1, 1, 1};
    ll minVal = grid[y][x];
    int nx = x, ny = y;
    for (int i = 0; i < 8; i++) {
        int curx = x + dx[i], cury = y + dy[i];
        if (grid[cury][curx] < minVal) {
            minVal = grid[cury][curx];
            nx = curx, ny = cury;
        }
    }
    if (nx == x && ny == y) return ans[y][x];
    ans[y][x] = Cal(ny, nx);
    return ans[y][x];
}

void solve () {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <=m; j++) {
            cin >> grid[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << Cal(i, j) << ' ';
        }
        cout << '\n';
    }
}

int main () {
    AC
    for (int i = 0; i < 1002; i++) {
        for (int j = 0; j < 1002; j++) {
            visited[i][j] = 0;
            grid[i][j] = inf;
        }
    }
    solve();
    return 0;
}