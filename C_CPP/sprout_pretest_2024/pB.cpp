#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    if (n < k) {
        cout << -1 << endl;
        return 0;
    }
    vector<int> a(n);
    cin >> a[0];
    int cnt = 1;
    for (int i = 1; i < n; i++) {
        cin >> a[i];
        if (a[i] <= a[i-1]) cnt++;
    }
    if (cnt > k) {
        cout << -1 << endl;
        return 0;
    } else {
        int i;
        for (i = 1; i <= k - cnt; i++) {
            cout << i << ' ';
            if (a[i] <= a[i-1]) cnt--;
        }
        cnt = i;
        i--;
        for (; i < n; i++) {
            if (a[i] <= a[i-1]) cnt++;
            cout << cnt << ' ';
        }
    }
    return 0;
}