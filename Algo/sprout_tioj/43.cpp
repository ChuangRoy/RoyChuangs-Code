#pragma GCC optimize("Ofast")
#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define pb emplace_back
#define ALL(x) begin(x),end(x)
#define ff first
#define ss second

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int dy[4] = {-1, 1, 0, 0};
const int dx[4] = {0, 0, -1, 1};

int main () {
    AC
    int t; cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int caty, catx;
        vector<vector<bool>> visited(n, vector<bool> (m, 0));
        vector<vector<char>> graph(n, vector<char> (m));
        char c;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> c;
                graph[i][j] = c;
                if (c == 'K') {
                    caty = i;
                    catx = j;
                }
                if (c == '#') {
                    visited[i][j] = 1;
                }
            }
        }
        queue<pair<int, pii>> nxts;
        nxts.push(make_pair(0, make_pair(caty, catx)));
        bool flag = 1;
        while (!nxts.empty()) {
            auto cur = nxts.front();
            nxts.pop();
            auto pos = cur.second;
            // cerr << pos.ff << ' ' << pos.ss << endl;
            if (visited[pos.ff][pos.ss]) continue;
            visited[pos.ff][pos.ss] = 1;
            if (graph[pos.ff][pos.ss] == '@') {
                cout << cur.first << '\n';
                flag = 0;
                break;
            }
            for (int i = 0; i < 4; i++) {
                nxts.push(make_pair(cur.first+1, make_pair(pos.ff+dy[i], pos.ss+dx[i])));
            }
        }
        if (flag) cout << "= =\"\n";
    }
    return 0;
}