#pragma GCC optimize("Ofast")
#include <iostream>
#include <utility>
#include <algorithm>
#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

using namespace std;

int main () {
    AC
    int T; cin >> T;
    while (T--) {
        long long a[7];
        for (int i = 1; i <= 6; i++) cin >> a[i];
        int cnt = 0;
        // 6
        cnt += a[6];
        // 5
        cnt += a[5];
        a[1] = max(0LL, a[1] - a[5] * 11);
        // 4
        cnt += a[4];
        long long spaces = a[4] * 20;
        long long use2 = min(a[2], spaces / 4);
        a[2] -= use2;
        spaces -= use2 * 4;
        a[1] = max(0LL, a[1]-spaces);
        // 3
        cnt += a[3] / 4;
        int rem3 = a[3] % 4;
        if (rem3 > 0) {
            cnt++;
            if (rem3 == 3) {
                spaces = 9;
                use2 = min(a[2], 1LL);
                a[2] -= use2;
            } else if (rem3 == 2) {
                spaces = 18;
                use2 = min(a[2], 3LL);
                a[2] -= use2;
            } else {
                spaces = 27;
                use2 = min(a[2], 5LL);
                a[2] -= use2;
            }
            spaces -= use2 * 4;
            a[1] = max(0LL, a[1]-spaces);
        }
        // 2
        cnt += a[2] / 9;
        int rem2 = a[2] % 9;
        if (rem2 > 0) {
            cnt++;
            spaces = 36 - rem2 * 4;
            a[1] = max(0LL, a[1]-spaces);
        }
        // 1
        cnt += a[1] / 36;
        if (a[1] % 36)
            cnt++;
        cout << cnt << '\n';
    }
    return 0;
}