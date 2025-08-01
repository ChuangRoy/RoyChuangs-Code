#include <iostream>
#include <vector>
using namespace std;
 
vector<vector<bool>> rec(1002, vector<bool> (1002, 1));
 
void dfs (int x, int y) {
    if (rec[x][y]) return;
    rec[x][y] = 1;
    dfs(x-1, y);
    dfs(x, y-1);
    dfs(x+1, y);
    dfs(x, y+1);
}
 
int main () {
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int cnt = 0;
        char c;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                cin >> c;
                if (c == '.') {
                    rec[i][j] = 0;
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (rec[i][j] == 0) cnt++;
                dfs(i, j);
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}