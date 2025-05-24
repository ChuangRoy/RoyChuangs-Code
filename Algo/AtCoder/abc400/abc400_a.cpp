#pragma GCC optimize("Ofast")
#include <iostream>
#include <utility>
#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define pb emplace_back
#define ALL(x) begin(x),end(x)
#define MP(x) make_pair((x), (x))
#define SQ(x) ((x)*(x))

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve () {
    int A; cin >> A;
    if (400 % A)
        cout << -1;
    else
        cout << 400 / A;
}

int main () {
    AC
    solve();
    return 0;
}