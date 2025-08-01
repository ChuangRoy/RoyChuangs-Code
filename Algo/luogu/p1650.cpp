#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

/* Template */
#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define ALL(x) begin(x),end(x)
#define pb emplace_back
#ifdef LOCAL
#define debug(args...) LKJ("[ " #args " ]", args)
template<class I> void LKJ(I&&x) { cerr << x << '\n'; }
template<class I, class...T> void LKJ(I&&x, T&&...t) { cerr << x << ", ", LKJ(t...); }
template<class I> void print(I a, I b) { while(a < b) cerr << *a << " \n"[next(a) == b], ++a; }
#else
#define debug(...) 0
#define print(...) 0
#endif
/* End of Template */

int main ()
{
    AC
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    int pta_front = 0, ptb_front = 0;
    int pta_back = n - 1, ptb_back = n - 1;
    sort(a.begin(), a.end(), [](auto a, auto b) {
        return a > b;
    });
    sort(b.begin(), b.end(), [](auto a, auto b) {
        return a > b;
    });
    ll ans = 0;
    while (ptb_front <= ptb_back && pta_front <= pta_back) {
        if (a[pta_front] > b[ptb_front]) {
            pta_front++;
            ptb_front++;
            ans += 200;
        } else if (a[pta_front] < b[ptb_front]) {
            ptb_front++;
            pta_back--;
            ans -= 200;
        } else {
            if (a[pta_back] > b[ptb_back]) {
                pta_back--;
                ptb_back--;
                ans += 200;
            } else if (a[pta_back] == b[ptb_front]) {
                pta_back--;
                ptb_front++;
            } else {
                pta_back--;
                ptb_front++;
                ans -= 200;
            }
        }
        debug(ans);
    }
    cout << ans << '\n';
    return 0;
}