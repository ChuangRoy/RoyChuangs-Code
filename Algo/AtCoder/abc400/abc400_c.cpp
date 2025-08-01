#pragma GCC optimize("Ofast")
#include <iostream>
#include <utility>
#include <cmath>
#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define pb emplace_back
#define ALL(x) begin(x),end(x)
#define MP(x) make_pair((x), (x))
#define SQ(x) ((x)*(x))

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve () {
    long long N; cin >> N;
    int cnt = 0;
    for (long long b = 1; SQ(b) <= N; b+=2) {
        long long num = SQ(b) << 1;
        while (num <= N) {
            cnt++;
            num <<= 1;
        }
    }
    cout << cnt << '\n';
}

int main () {
    AC
    solve();
    return 0;
}