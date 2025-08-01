#include <bits/stdc++.h>
using namespace std;
 
const int blk_size = 100;
const int INF = 1e9 + 1;
 
int main () {
    ios_base::sync_with_stdio(false); cin.tie(0);
    vector<int> blks(1e7/blk_size + 1);
    vector<int> a(1e7);
    int mi;
    int n; cin >> n;
    int q; cin >> q;
    int i, j;
    for (i = 0; i < n; i++) cin >> a[i];
    for (i = 1; i < n / blk_size; i++) {
        mi = INF;
        for (j = i * blk_size; j < (i+1) * blk_size; j++) mi = min(mi, a[j]);
        blks[i] = mi;
    }
    int x, y;
    for (i = 0; i < q; i++) {
        cin >> x >> y;
        x-=1; y-=1; // convert to 0 base
        mi = INF;
        for (j = x; j < x + blk_size - x%blk_size && j < (y+1); j++)
            mi = min(mi, a[j]);
        for (j = x/blk_size + 1; j < (y+1) / blk_size; j++)
            mi = min(mi, blks[j]);
        for (j = (y+1) - (y+1) % blk_size; x < j && j < (y+1); j++)
            mi = min(mi, a[j]);
        cout << mi << '\n';
    }
    return 0;
}