#include <bits/stdc++.h>

#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define pii pair<int, int>
#define ff first
#define ss second
#define pb push_back

using namespace std;
using ll = long long;

int main ()
{
    AC
    int n, m;
    cin >> n >> m;
    vector<pii> v;
    int a, b;
    int cnt = 0;
    while (m--) {
        cin >> a >> b;
        if (a == b) {
            cnt++;
        } else {
            v.pb(make_pair(min(a, b), max(a, b)));
        }
    }
    sort(v.begin(), v.end());
    for (int i = 1; i < v.size(); i++) {
        if (v[i] == v[i-1]) cnt++;
    }
    cout << cnt << '\n';
    return 0;
}