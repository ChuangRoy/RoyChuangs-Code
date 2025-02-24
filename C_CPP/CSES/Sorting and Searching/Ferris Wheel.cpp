#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, x; cin >> n >> x;
    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    sort(p.begin(), p.end());
    int l = 0, r = n - 1;
    int cnt = 0;
    while (r > l) {
        if (p[r] + p[l] > x) {
            r--;
        } else {
            l++;
            r--;
        }
        cnt++;
    }
    if (l == r) cnt++;
    cout << cnt << '\n';
    return 0;
}