#pragma GCC optimize("Ofast")
#include <iostream>
#include <utility>
#include <algorithm>
#include <vector>
#include <deque>
#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define pb push_back
#define ALL(x) begin(x),end(x)
#define MP(x, y) make_pair((x), (y))
#define SQ(x) ((x)*(x))
#define SZ(x) ((int) x.size())

using namespace std;
typedef pair<int, int> pii;

vector<vector<bool>> grid(505, vector<bool> (505, 0));

int dx [4] = {0, 0, -1, 1};
int dy [4] = {-1, 1, 0, 0};

void solve () {
    int n, m;
    cin >> n >> m;
    deque<pair<int, pii>> cats;
    deque<pair<int, pii>> nxts;
    int mx, my;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            char c;
            cin >> c;
            if (c == '.') {
                grid[i][j] = 1;
            }
            if (c == 'K') {
                grid[i][j] = 1;
                nxts.pb(MP(0, MP(i, j)));
            }
            if (c == '@') {
                grid[i][j] = 1;
                mx = j;
                my = i;
            }
        }
    }
    int q;
    cin >> q;
    while (q--) {
        int tt, xx, yy;
        cin >> tt >> yy >> xx;
        cats.pb(MP(tt, MP(yy, xx)));
    }
    sort(ALL(cats));
    int t = 0;
    while (SZ(nxts) >= 1 or SZ(cats) >= 1) {
        while (SZ(cats) >= 1 and cats[0].first == t) {
            auto cur = cats[0].second;
            cats.pop_front();
            nxts.push_front(MP(t, MP(cur.first, cur.second)));
        }
        while (SZ(nxts) >= 1 and nxts[0].first == t) {
            auto cur = nxts[0].second;
            nxts.pop_front();
            if (!grid[cur.first][cur.second])
                continue;
            // cerr << t << ' ' << cur.first << ' ' << cur.second << endl;
            if (cur.first == my and cur.second == mx) {
                cout << t << '\n';
                return;
            }
            grid[cur.first][cur.second] = 0;
            for (int k = 0; k < 4; k++) {
                if (grid[cur.first+dy[k]][cur.second+dx[k]])
                    nxts.pb(MP(t+1, MP(cur.first+dy[k], cur.second+dx[k])));
            }
        }
        t++;
    }
    cout << "= =\"\n";
}

int main () {
    AC
    solve();
    return 0;
}