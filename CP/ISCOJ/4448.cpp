#include <bits/stdc++.h>
using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int k, n;
    long sum = 0;
    cin >> k >> n;
    bool running= 1;
    for (int i = 1; i <= n && running; i++) {
        if (i == k) {
            running = 0;
        }else
            sum += i;
    }
    cout << sum << endl;
    return 0;
}