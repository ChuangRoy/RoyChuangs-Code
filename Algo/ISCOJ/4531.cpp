#include <bits/stdc++.h>

#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define pii pair<int, int>
#define ff first
#define ss second
#define pb push_back

using namespace std;
using ll = long long;

signed main ()
{
    AC
    string A5Cow[3] = {"A", "5", "cow"};
    string s;
    int r = 0;
    ll cnt = 0;
    while (cin >> s) {
        // cout << s << ' ';
        if (s == A5Cow[r]) r++;
        else if (s == A5Cow[0]) r = 1;
        else r = 0;

        if (r == 3) {
            cnt++;
            r = 0;
        }
    }
    cout << cnt << '\n';
    return 0;
}