#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    string a, b;
    cin >> n >> m;
    vector<vector <long long>> res(m + 1, vector<long long> (n + 1, 0));
    cin >> a >> b;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i-1] == b[j-1]) {
                res [j][i] = res [j-1][i-1] + 1;
            }
            else {
                res [j][i] = max(res[j-1][i], res[j][i-1]);
            }
        }
    }
    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j <= m; j++) {
    //         cout << res[j][i] << " ";
    //     }
    //     cout << endl;
    // }
    cout << res [m][n];
    return 0;
}