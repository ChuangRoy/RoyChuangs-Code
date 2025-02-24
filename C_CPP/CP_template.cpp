#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define ALL(x) begin(x),end(x)
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
    
    return 0;
}