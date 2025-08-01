#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define pb emplace_back
/* Debug */
#ifdef LOCAL
#define debug(args...) LKJ("[ " #args " ]", args)
template<class I> void LKJ(I&&x) { cerr << x << '\n'; }
template<class I, class...T> void LKJ(I&&x, T&&...t) { cerr << x << ", ", LKJ(t...); }
template<class I> void print(I a, I b) { while(a < b) cerr << *a << " \n"[next(a) == b], ++a; }
#else
#define debug(...) 0
#define print(...) 0
#endif
/* End of Debug */

int main ()
{
    AC
    int n; cin >> n;
    vector<pii> x(n+2);
    for (int i = 0; i <= n+1; i++) {
        x[i] = make_pair(i-1, i+1);
    }
    int q; cin >> q;
    int op, cur;
    while (q--) {
        cin >> op >> cur;
        int prev = x[cur].first;
        int next = x[cur].second;
        switch(op) {
        case 0:
            x[prev].second = next;
            x[next].first = prev;
            break;
        case 1:
            if (prev == 0) break;
            x[x[prev].first].second = cur;
            x[next].first = prev;
            x[cur].first = x[prev].first;
            x[cur].second = prev;
            x[prev].first = cur;
            x[prev].second = next;
            break;
        }
    }
    int top = x[0].second;
    while (top <= n) {
        cout << top << ' ';
        top = x[top].second;
    }
    cout << '\n';
    return 0;
}