#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    long long n; cin >> n;
    while (1) {
        cout << n << " ";
        if (n % 2 == 0) {
            n = n / 2;
        } else {
            if (n == 1) break;
            n = n * 3 + 1;
        }
    }
    return 0;
}