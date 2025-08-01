#pragma GCC optimize("Ofast")
#include <iostream>
#include <utility>
#include <algorithm>
#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define ALL(x) begin(x),end(x)
#define pb emplace_back

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main () {
    AC
    ll m, n;
    cin >> m >> n;
    while (m | n) {
        if (m < n) swap(m, n);
        // mn - mk - nk + k^2
        cout << m*n*n - n*(n-1)*(m+n)/2 + (n-1)*n*(2*n-1)/6 << '\n';
        cin >> m >> n;
    }
    return 0;
}