#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int ll
#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define ALL(x) begin(x),end(x)
#define pb emplace_back

signed main () {
    AC
    char c;
    bool state = 0;
    ll a = 0, b = 0;
    bool asign = 0, bsign = 0;
    vector<ll> x, y;
    while (cin >> c) {
        if (c != ')' && c != ',' && c != '-' && ('0' > c || c > '9')) {
            continue;
        }
        if (c == ')') {
            if (asign) a *= -1;
            if (bsign) b *= -1;
            x.pb(a);
            y.pb(b);
            a = 0; b = 0;
            asign = 0; bsign = 0;
            state = 0;
            continue;
        }
        if (c == ',') {
            state = 1;
            continue;
        }
        if (c == '-') {
            if (state) bsign = !bsign;
            else asign = !asign;
            continue;
        }
        if (state) {
            b *= 10;
            b += (c - '0');
        } else {
            a *= 10;
            a += (c - '0');
        }
    }
    double sum_x = 0, sum_y = 0;
    int n = x.size();
    for (int i = 0; i < n; i++) {
        sum_x += x[i];
        sum_y += y[i];
    }
    cout << fixed << setprecision(3);
    cout << '(' << sum_x / n << "," << sum_y / n << ")\n";
    return 0;
}