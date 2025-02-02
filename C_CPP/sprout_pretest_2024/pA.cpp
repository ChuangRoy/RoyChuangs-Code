#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, q;
    cin >> n >> q;
    vector<int> a(n+2, 0);
    vector<int> b(n+2, 0);
    for (int i = 0; i < n; i++) cin >> a[i+1];
    for (int i = 0; i < n; i++) cin >> b[i+1];
    int x;
    while (q--) {
        cin >> x;
        int cnt = 0;
        if (x > 1) {
            cnt += (a[x-1] << (b[x-2]+b[x]));
        }
        cnt += (a[x] << (b[x-1]+b[x+1]));
        if (x < n) {
            cnt += (a[x+1] << (b[x]+b[x+2]));
        }
        cout << cnt << '\n';
    }
    return 0;
}