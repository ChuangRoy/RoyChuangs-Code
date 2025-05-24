#include <bits/stdc++.h>
using namespace std;

bool comp (pair <int, int> a, pair <int, int> b) {
    return (float) a.first / a.second > (float) b.first / b.second;
}

int main () {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m;
    cin >> n >> m;
    pair<int, int> p[n];
    int i;
    long long sum_size = 0, ans = 0;
    for (i = 0; i < n; i++) cin >> p[i].first >> p[i].second;
    sort (p, p+n, comp);
    i = 0;
    while (sum_size + p[i].second <= m) {
        ans += p[i].first;
        sum_size += p[i].second;
        i += 1;
    }
    cout << ans + (int)((double) p[i].first/p[i].second*(m-sum_size));
    return 0;
}