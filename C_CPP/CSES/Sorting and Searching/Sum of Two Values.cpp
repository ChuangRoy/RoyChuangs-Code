#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first;
}
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i].first;
        p[i].second = i + 1;
    }
    sort(p.begin(), p.end(), comp);
    int l = 0, r = n - 1, sum;
    bool flag = 1;
    while (l < r && flag) {
        sum = p[l].first + p[r].first;
        if (sum == x) {
            flag = 0;
        } else if (sum > x) {
            r--;
        } else {
            l++;
        }
    }
    if (flag) {
        cout << "IMPOSSIBLE";
    } else {
        cout << p[l].second << " " << p[r].second;
    }
    return 0;
}