#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

/* Template */
#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define ff first
#define ss second
#define AI(x) begin(x),end(x)
#define pb emplace_back
#ifdef LOCAL
#define debug(args...) LKJ("[ " #args " ]", args)
template<class I> void LKJ(I&&x) { cerr << x << '\n'; }
template<class I, class...T> void LKJ(I&&x, T&&...t) { cerr << x << ", ", LKJ(t...); }
template<class I> void OI(I a, I b) { while(a < b) cerr << *a << " \n"[next(a) == b], ++a; }
#else
#define debug(...) 0
#define OI(...) 0
#endif
/* End of Template */

const int mod = 1e9 + 7;

int main ()
{
    AC

    return 0;
}