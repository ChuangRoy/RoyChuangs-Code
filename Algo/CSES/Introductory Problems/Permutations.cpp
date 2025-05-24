#include <bits/stdc++.h>

#define int long long
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
    int n; cin >> n;
    if (n == 2 || n == 3) {
        cout << "NO SOLUTION\n";
        return 0;
    }
    for (int i = 2; i <= n; i += 2) {
        cout << i << ' ';
    }
    for (int i = 1; i <= n; i += 2) {
        cout << i << ' ';
    }
    cout << '\n';
    return 0;
}