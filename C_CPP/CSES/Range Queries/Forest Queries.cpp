#include <bits/stdc++.h>
using namespace std;

const int arr_size = 1001;
int rec[arr_size][arr_size];
bool forest[arr_size][arr_size];

int main ()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, q;
    cin >> n >> q;
    char c;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> c;
            if (c == '*') forest[i][j] = 1;
            else forest[i][j] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        rec[0][i] = 0;
        rec[i][0] = 0;
    }
    int cnt;
    for (int i = 1; i <= n; i++) {
        cnt = 0;
        for (int j = 1; j <= n; j++) {
            cnt += forest[i-1][j-1];
            rec[i][j] = rec[i-1][j] + cnt;
        }
    }
    int y1, x1, y2, x2;
    for (int i = 0; i < q; i++) {
        cin >> y1 >> x1 >> y2 >> x2;
        cout << rec[y2][x2] - rec[y2][x1-1] - rec[y1-1][x2] + rec[y1-1][x1-1] << "\n";
    }
    return 0;
}
