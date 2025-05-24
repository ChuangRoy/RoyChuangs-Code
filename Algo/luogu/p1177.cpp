#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define int long long
#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define pii pair<int, int>
#define ff first
#define ss second

signed main ()
{
    AC
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    for (auto it : a) {
        cout << it << ' ';
    }
    cout << '\n';
    return 0;
}