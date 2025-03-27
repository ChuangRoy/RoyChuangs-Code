#pragma GCC optimize("Ofast")
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <cstdint>
#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define pb emplace_back
#define ALL(x) begin(x),end(x)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

double evaluate(vector<double> &a, vector<double> &b, vector<double> &c, double t, int n) {
    double ret = -1e9;
    for (int i = 0; i < n; i++) {
        ret = max(a[i] * (t - b[i]) * (t - b[i]) + c[i],
                    ret);
    }
    return ret;
}

int main () {
    AC
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<double> a(n), b(n), c(n);
        for (int i = 0; i < n; i++) cin >> a[i] >> b[i] >> c[i];
        double l = 0, r = 300;
        double d = r - l;
        while (d > 1e-9) {
            double q1 = l + d / 3, q2 = r - d / 3;
            double e1 = evaluate(a, b, c, q1, n), e2 = evaluate(a, b, c, q2, n);
            if (e1 > e2) {
                l = q1;
            } else if (e1 == e2) {
                l = q1;
                r = q2;
            } else {
                r = q2;
            }
            d = r - l;
        }
        cout << fixed << setprecision(12) << evaluate(a, b, c, l, n) << '\n';
    }
    return 0;
}