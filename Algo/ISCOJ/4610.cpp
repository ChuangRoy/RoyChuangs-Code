#pragma GCC optimize("Ofast")
#include <iostream>
#include <cstring>
#define fastio cin.tie(0)->sync_with_stdio(false)

using namespace std;
typedef long long ll;

ll mat[1003][1003];
ll prefix[1003][1003];

void solve () {
    int n, m, q;
    cin >> n >> m >> q;
    memset(prefix, 0, sizeof(prefix));
    for (int i = 1; i <= n; i++) {
        ll rowsum = 0;
        for (int j = 1; j <= m; j++) {
            cin >> mat[i][j];
            prefix[i][j] = prefix[i-1][j] + rowsum + mat[i][j];
            rowsum += mat[i][j];
        }
    }
    // for (int i = 1; i <= n; i++) {
        // for (int j = 1; j <= m; j++) {
            // fout << prefix[i][j] << ' ';
        // }
        // fout << '\n';
    // }
    while (q-->0) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        cout << (prefix[x2][y2] - prefix[x2][y1-1] - prefix[x1-1][y2] + prefix[x1-1][y1-1]) << '\n';
    }
}

int main () {
    fastio;
    solve();
    return 0;
}