#include <bits/stdc++.h>
using namespace std;

void toh (int n, int a, int b, int c)
{
    if (n == 1) {
        cout << a << ' ' << c << '\n';
        return;
    }
    toh(n-1, a, c, b);
    cout << a << ' ' << c << '\n';
    toh(n-1, b, a, c);
}

int main ()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    cout << (1<<n)-1 << '\n';
    toh(n, 1, 2, 3);
    return 0;
}