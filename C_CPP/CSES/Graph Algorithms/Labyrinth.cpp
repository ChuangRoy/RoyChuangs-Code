#pragma GCC optimize("Ofast")
#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <algorithm>
#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define pb emplace_back
#define ALL(x) begin(x),end(x)
#define ff first
#define ss second
// #define ASTAR

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
 
const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, -1, 1};
const string directions = "UDLR";

const int inf = 1e9;

int evaluate (int x, int y, int bx, int by) {
    return abs(bx - x) + abs(by - y);
}
 
int main () {
    AC
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> visited(n+2, vector<bool> (m+2, 1));
    vector<vector<pii>> rec(n+2, vector<pii> (m+2, make_pair(inf, 0)));
    int ax, ay, bx, by;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            char c;
            cin >> c;
            if (c == '.') {
                visited[i][j] = 0;
            }
            if (c == 'A') {
                ay = i;
                ax = j;
                visited[i][j] = 0;
            }
            if (c == 'B') {
                by = i;
                bx = j;
                visited[i][j] = 0;
            }
        }
    }
    rec[ay][ax].ff = 0;
#ifdef ASTAR
    priority_queue<pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;
    pq.push(make_pair(evaluate(ax, ay, bx, by), make_pair(ay, ax)));
    while (!pq.empty()) {
        auto cur = pq.top();
        auto pos = cur.ss;
        pq.pop();
        if (visited[pos.ff][pos.ss]) continue;
        visited[pos.ff][pos.ss] = 1;
        if (pos.ff == by && pos.ss == bx) {
            cout << "YES\n";
            cout << rec[by][bx].ff << '\n';
            vector<char> rev;
            int cury = by;
            int curx = bx;
            while (cury != ay || curx != ax) {
                int d = rec[cury][curx].ss;
                rev.pb(directions[d]);
                cury -= dy[d];
                curx -= dx[d];
            }
            reverse(rev.begin(), rev.end());
            for (auto it : rev) cout << it;
            cout << '\n';
            return 0;
        }
        for (int i = 0; i < 4; i++) {
            int ny = pos.ff + dy[i];
            int nx = pos.ss + dx[i];
            if (!visited[ny][nx] &&
                rec[ny][nx].ff > rec[pos.ff][pos.ss].ff + 1) {

                rec[ny][nx] = make_pair(rec[pos.ff][pos.ss].ff+1, i);
                pq.push(make_pair(
                    rec[ny][nx].ff+evaluate(nx, ny, bx, by),
                    make_pair(ny, nx))
                );
            }
        }
    }
    cout << "NO\n";
#else
    queue<pii> nxts;
    nxts.push(make_pair(ay, ax));
    while (!nxts.empty()) {
        auto pos = nxts.front();
        nxts.pop();
        if (visited[pos.ff][pos.ss]) continue;
        visited[pos.ff][pos.ss] = 1;
        if (pos.ff == by && pos.ss == bx) {
            cout << "YES\n";
            cout << rec[by][bx].ff << '\n';
            vector<char> rev;
            int cury = by;
            int curx = bx;
            while (cury != ay || curx != ax) {
                int d = rec[cury][curx].ss;
                rev.pb(directions[d]);
                cury -= dy[d];
                curx -= dx[d];
            }
            reverse(rev.begin(), rev.end());
            for (auto it : rev) cout << it;
            cout << '\n';
            return 0;
        }
        for (int i = 0; i < 4; i++) {
            int ny = pos.ff + dy[i];
            int nx = pos.ss + dx[i];
            if (!visited[ny][nx]) {
                rec[ny][nx] = make_pair(rec[pos.ff][pos.ss].ff+1, i);
                nxts.push(make_pair(ny, nx));
            }
        }
    }
    cout << "NO\n";
#endif
    return 0;
}