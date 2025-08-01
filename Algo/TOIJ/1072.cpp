#include <bits/stdc++.h>
using namespace std;
#define int long long

bool comp (pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}

signed main ()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    while (n) {
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; i++) cin >> a[i].first >> a[i].second;
        sort(a.begin(), a.end(), comp);
        // for (auto i : a) cout << i.first << ' ' << i.second << '\n';
        int t = 0;
        int maxt = 0;
        for (int i = 0; i < n; i++) {
            t += a[i].first;
            maxt = max(maxt, t + a[i].second);
        }
        cout << maxt << '\n';
        cin >> n;
    }
    return 0;
}