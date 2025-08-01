#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n; cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) cin >> p[i];
    sort(p.begin(), p.end());
    int mid = p[n/2];
    unsigned long long sum = 0;
    for (int i = 0; i < n; i++) {
        if (p[i] - mid < 0) {
            sum += (mid - p[i]);
        } else {
            sum += (p[i] - mid);
        }
    }
    cout << sum << '\n';
    return 0;
}