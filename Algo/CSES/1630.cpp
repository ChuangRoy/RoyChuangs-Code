#include <bits/stdc++.h>
using namespace std;

bool comp (pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first;
}

int main ()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<pair<int, int>> p(n);
    int a, d;
    for (int i = 0; i < n; i++) {
        cin >> a >> d;
        p[i] = make_pair(a, d);
    }
    sort(p.begin(), p.end(), comp);
    long long t = 0;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        t += p[i].first;
        sum += (p[i].second - t);
    }
    cout << sum << '\n';
    return 0;
}