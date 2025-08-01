#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    vector<int> x(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }
    sort(x.begin(), x.end());
    long long k = 0; // prefix sum
    for (int i = 0; i < n; i++) {
        if (k + 1 < x[i]) {
            cout << k + 1 << '\n';
            return 0;
        } else {
            k += x[i];
        }
    }
    cout << k + 1 << '\n';
    return 0;
}