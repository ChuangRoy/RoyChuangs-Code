#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    int n; string s;
    while (t--) {
        cin >> n;
        cin >> s;
        int p_cnt=0, s_cnt=0;
        for (int i = 0; i < n; i++) {
            if (s[i] == 'p') p_cnt++;
            if (s[i] == 's') s_cnt++;
        }
        int p_flag = (s[n-1]=='p')?1:0;
        int s_flag = (s[0]=='s')?1:0;
        if ( (s[0] == 'p' && s_cnt > 0) || (s[n-1] == 's' && p_cnt > 0) ) {
            cout << "NO" << "\n";
        } else if (p_cnt - p_flag > 0 && s_cnt - s_flag > 0) {
            cout << "NO" << "\n";
        } else {
            cout << "YES" << "\n";
        }
    }
    return 0;
}