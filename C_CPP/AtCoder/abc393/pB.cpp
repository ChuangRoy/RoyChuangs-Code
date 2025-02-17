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
    string s;
    cin >> s;
    int d = 1; // j = i + d
    int i = 0;
    ll cnt = 0;
    while (2*d < s.size()) {
        while (i + 2*d < s.size()) {
            if (s[i] == 'A' && s[i+d] == 'B' && s[i+2*d] == 'C') {
                cnt++;
                // cout << i << ' ' << i+d << ' ' << i + 2 * d << '\n';
            }
            i++;
        }
        i = 0;
        d++;
    }
    cout << cnt << '\n';
    return 0;
}