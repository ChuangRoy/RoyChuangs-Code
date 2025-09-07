#include <bits/stdc++.h>
using namespace std;

const int blk_size = 100;

int main () {
    ios_base::sync_with_stdio(false); cin.tie(0);
    vector<int> blks(1e7/blk_size + 1);
    vector<int> a(1e7);
    int b, ma;
    int n; cin >> n;
    int i, j;
    for (i = 0; i < n; i++) cin >> a[i];
    for (i = 1; i < n / blk_size; i++) {
        ma = 0;
        for (j = i * blk_size; j < (i+1) * blk_size; j++) ma = max(ma, a[j]);
        blks[i] = ma;
    }
    for (i = 0; i < n; i++) {
        cin >> b;
        ma = 0;
        for (j = b; j < b + blk_size - b%blk_size && j < (i+1); j++)
            ma = max(ma, a[j]);
        for (j = b/blk_size + 1; j < (i+1) / blk_size; j++)
            ma = max(ma, blks[j]);
        for (j = (i+1) - (i+1) % blk_size; b < j && j < (i+1); j++)
            ma = max(ma, a[j]);
        cout << ma << " ";
    }
    return 0;
}