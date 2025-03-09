#include <bits/stdc++.h>
using namespace std;
#define int long long

bool comp (pair<int, int> a, pair<int, int> b)
{
    if (a.second == b.second) return a.first > b.first;
    return a.second > b.second;
}

signed main ()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n;
    while (cin >> n) {
        vector<pair<int, int>> p(n);
        int a, b;
        for (int i = 0; i < n; i++) {
            cin >> a >> b;
            p[i] = make_pair(a, b);
        }
        sort(p.begin(), p.end(), comp);
        int t = 0, maxt = 0;
        for (int i = 0; i < n; i++) {
            t += p[i].first;
            maxt = max(maxt, t + p[i].second);
        }
        cout << maxt << '\n';
    }
    return 0;
}