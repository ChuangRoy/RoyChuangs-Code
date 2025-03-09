#include <bits/stdc++.h>
using namespace std;
#define AC ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

signed main ()
{
    AC
    string s, t;
    cin >> s >> t;
    vector<vector<int>> dp(s.size()+1, vector<int> (t.size()+1, 0));
    vector<vector<short>> rec(s.size()+1, vector<short> (t.size()+1, 0));
    for (int i = 1; i <= s.size(); i++) {
        for (int j = 1; j <= t.size(); j++) {
            if (s[i-1] == t[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                rec[i][j] = 1;
            } else {
                // dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                if (dp[i-1][j] > dp[i][j-1]) {
                    dp[i][j] = dp[i-1][j];
                    rec[i][j] = 2;
                } else {
                    dp[i][j] = dp[i][j-1];
                    rec[i][j] = 3;
                }
            }
        }
    }
    // cout << dp[s.size()][t.size()] << '\n';
    string ans = "";
    int i = s.size(), j = t.size();
    while (i > 0 && j > 0) {
        switch (rec[i][j]) {
        case 1:
            ans = ans + s[i-1];
            i--; j--;
            break;
        case 2:
            i--;
            break;
        case 3:
            j--;
            break;
        }
    }
    for (int it = ans.size()-1; it >= 0; it--) cout << ans[it];
    cout << '\n';
    return 0;
}