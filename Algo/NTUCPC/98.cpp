#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int t = 1;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] - t >= 0) {
            t++;
            cnt++;
        }
    }
    cout << cnt << '\n';
    return 0;
}