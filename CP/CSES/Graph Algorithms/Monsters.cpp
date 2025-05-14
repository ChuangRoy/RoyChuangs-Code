#pragma GCC optimize("Ofast")
#include <iostream>
#include <utility>
#include <cstring>
#include <deque>
#include <queue>
#include <algorithm>
#define AC cin.tie(0)->sync_with_stdio(false);
#define ALL(x) begin(x),end(x)
#define MP(x, y) make_pair((x), (y))
#define SQ(x) ((x)*(x))
#define SZ(x) ((int) x.size())
#define err(x) cerr << #x << ": " << x << endl;

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
 
bool visited[1002][1002];
int rec[1002][1002];
 
char directions[] = "UDLR";
const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};
 
void solve () {
    int n, m;
    int ay, ax;
    cin >> n >> m;
    deque<pair<int, pii>> nxts;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c;
            cin >> c;
            if (c == 'M') {
                nxts.push_front(MP(0, MP(i, j)));
            }
            if (c == 'A') {
                ay = i;
                ax = j;
                nxts.push_back(MP(1, MP(i, j)));
            }
            if (c == '.') {
                visited[i][j] = 0;
            }
        }
    }
    while (SZ(nxts) >= 1) {
        auto pos = nxts[0].second;
        int id = nxts[0].first;
        nxts.pop_front();
        if (pos.first == 1 || pos.first == n || pos.second == 1 || pos.second == m) {
            if (id == 1) {
                cout << "YES\n";
                string path;
                while (pos.first != ay || pos.second != ax) {
                    int k = rec[pos.first][pos.second];
                    path += directions[k];
                    pos.first -= dy[k];
                    pos.second -= dx[k];
                }
                cout << SZ(path) << '\n';
                reverse(path.begin(), path.end());
                cout << path << '\n';
                return;
            }
        }
        for (int k = 0; k < 4; k++) {
            int ny = pos.first + dy[k];
            int nx = pos.second + dx[k];
            if (!visited[ny][nx]) {
                nxts.push_back(MP(id, MP(ny, nx)));
                visited[ny][nx] = 1;
                if (id == 1) {
                    rec[ny][nx] = k;
                }
            }
        }
    }
    cout << "NO\n";
}
 
int main () {
    AC
    memset(visited, 1, sizeof(visited));
    solve();
    return 0;
}
