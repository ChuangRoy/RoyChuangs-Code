#include <bits/stdc++.h>

#define int long long
#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define pii pair<int, int>
#define ff first
#define ss second
#define pb push_back

using namespace std;
using ll = long long;

// X * 2 + Y * 4 = 2 * A
// X * 2 + Y * 1 = B
// 3 * Y = 2 * A - B
// Y = (2 * A - B)/3

// X + Y * 2 = A
// 4 * X + 2 * Y = 2 * B
// -3 * X = A - 2 * B
// X = (2 * B - A) / 3

signed main ()
{
    AC
    int t; cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        if ((2*a-b) < 0 || (2*b-a) < 0 || (2*a-b) % 3 || (2*b-a) % 3)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;
}