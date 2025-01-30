#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main ()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int x, y;
        cin >> y >> x;
        int layer, depth;
        layer = max(x, y);
        if (layer % 2) swap(x, y);
        if (x >= y) {
            depth = y;
        } else {
            depth = 2 * y - x;
        }
        cout << (layer - 1) * (layer - 1) + depth << '\n';
    }
    return 0;
}