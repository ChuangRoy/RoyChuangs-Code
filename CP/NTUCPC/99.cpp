#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main ()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n, l; cin >> n >> l;
    vector<int> d(n);
    for (int i = 0; i < n; i++) cin >> d[i];
    sort(d.begin(), d.end());
    int t = 0;
    int cnt = 0;
    for (auto i : d) {
        if (i - t >= l) {
            t += l;
            cnt++;
        }
    }
    cout << cnt << '\n';
    return 0;
}