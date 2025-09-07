#pragma GCC optimize("Ofast")
#include <cstdlib>
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <cstdint>
#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define pb emplace_back
#define ALL(x) begin(x),end(x)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

vector<int> xs(50004);
vector<int> vs(50004);

double evaluate(int N, double pos) {
    double ret = 0;
    for (int i = 0; i < N; i++) {
        ret = max(fabs(pos - xs[i]) / vs[i], ret);
    }
    return ret;
}

void solve() {
    int N; cin >> N;
    for (int i = 0; i < N; i++) cin >> xs[i] >> vs[i];
    double l = 0, r = 1e9;
    double d = r - l;
    while (d > 1e-7) {
        double q1 = l + d / 3, q2 = r - d / 3;
        // cerr << l << ' ' << r << ' ' << evaluate(a, b, c, q1, n) << ' ' << evaluate(a, b, c, q2, n) << endl;
        if (evaluate(N, q1) > evaluate(N, q2)) {
            l = q1;
        } else {
            r = q2;
        }
        d = r - l;
    }
    cout << fixed << setprecision(6) << evaluate(N, l) << '\n';
}

int main () {
    AC
    solve();
    return 0;
}