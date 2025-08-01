#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main () {
    AC
    string a;
    cin >> a;
    int dotpos;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == '.') {
            dotpos = i;
            break;
        }
    }
    ll num = 0;
    for (int i = 0; i < dotpos; i++) {
        num *= 10;
        num += (a[i]-'0');
    }
    int p = 0, q = 0;
    for (int i = dotpos+1; i < a.size(); i++) {
        p*=10; q*=10;
        p += (a[i]-'0');
        q += 9;
    }
    int cd = gcd(q, p);
    p /= cd; q /= cd;
    cout << (num * q + p) << '/' << q << '\n';
    return 0;
}