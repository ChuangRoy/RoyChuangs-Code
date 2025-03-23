#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/* Template */
#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define pb emplace_back
/* End of Template */

int main () {
    AC
    int n; cin >> n;
    while (n) {
        vector<int> a(n);
        cin >> a[0];
        while (a[0]) {
            for (int i = 1; i < n; i++) cin >> a[i];
            int s = 1;
            vector<int> st;
            int st_last = -1;
            bool flag = 1;
            for (auto i : a) {
                if (i == s) {
                    s++;
                } else if (i > s) {
                    while (i > s) {
                        st.pb(s);
                        st_last++;
                        s++;
                    }
                    s++;
                } else {
                    if (!st.empty() && i == st[st_last]) {
                        st.pop_back();
                        st_last--;
                    } else {
                        cout << "No\n";
                        flag = 0;
                        break;
                    }
                }
            }
            if (flag) cout << "Yes\n";
            cin >> a[0];
        }
        cout << '\n';
        cin >> n;
    }
    return 0;
}