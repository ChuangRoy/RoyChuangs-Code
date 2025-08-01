#include <bits/stdc++.h>
using namespace std;

bool comp (pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
} 

int main ()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<pair<int, int>> p(n);
    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        p[i] = make_pair(a, b);
    }
    sort(p.begin(), p.end(), comp);
    int cnt = 1;
    int last_end = p[0].second;
    for (int i = 1; i < n; i++) {
        if (p[i].first >= last_end) {
            cnt++;
            last_end = p[i].second;
        }
    }
    cout << cnt << '\n';
    return 0;
}