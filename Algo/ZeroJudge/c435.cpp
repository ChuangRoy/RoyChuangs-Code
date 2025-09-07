#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    long long a; cin >> a;
    long long maxa = -LLONG_MAX;
    long long ans = -LLONG_MAX;
    for (int i = 1; i < n; i++) {
        maxa = max(maxa, a);
        cin >> a;
        ans = max(ans, maxa - a);
    }
    cout << ans << '\n';
    return 0;
}