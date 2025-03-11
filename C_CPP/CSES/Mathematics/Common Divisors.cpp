#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define pb emplace_back
#define ALL(x) begin(x),end(x)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int MAX_VAL = 1e6;

int main () {
    AC
    int n; cin >> n;
    vector<int> occ_cnt(MAX_VAL+1, 0);
    int a;
    int ma = 1;
    for (int i = 0; i < n; i++) {
        cin >> a;
        occ_cnt[a]++;
        ma = max(a, ma);
    }
    for (int gcd = ma; gcd >= 1; gcd--) {
        int cnt = 0;
        for (int j = gcd; j <= ma; j+=gcd) {
            cnt += occ_cnt[j];
            if (cnt >= 2) break;
        }
        if (cnt >= 2) {
            cout << gcd << '\n';
            break;
        }
    }
    return 0;
}