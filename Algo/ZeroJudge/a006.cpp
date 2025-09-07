#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    double a, b, c;
    cin >> a >> b >> c;
    double d = (b*b)-4*a*c;
    if (d < 0) {
        cout << "No real root" << '\n';
        return 0;
    }
    if (d == 0) {
        if (b == 0) cout << "Two same roots x=0" << '\n';
        else cout << "Two same roots x=" << ((-1*b)/(2*a)) << '\n';
        return 0;
    }
    cout << "Two different roots x1=" << ((-1*b+sqrt(d))/(2*a))
         << " , x2=" << ((-1*b+-sqrt(d))/(2*a)) << '\n';
    return 0;
}