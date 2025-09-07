#include <bits/stdc++.h>

#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

using namespace std;
using ll = long long;

signed main ()
{
    AC
    int n; cin >> n;
    vector<string> str(n);
    for (int i = 0; i < n; i++) cin >> str[i];
    for (auto s : str) {
        // cout << s << '\n';
        // cout << s[0] - 'a' << '\n';
        if (s.size() <= s[0] - 'a') cout << ' ';
        else cout << s[s[0] - 'a'];
    }
    cout << '\n';
    return 0;
}