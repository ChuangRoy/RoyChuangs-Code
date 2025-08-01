#pragma GCC optimize("Ofast")
#include <iostream>
#include <string>
#define fastio cin.tie(0)->sync_with_stdio(false)

using namespace std;

bool is_smaller(int y) {
    string s;
    cout << "? " << y << endl;
    cin >> s;
    return s == "YES";
}

void solve() {
    int l = 0, r = 1e9;
    while (l < r) {
        int mid = (l + r) / 2;
        if (is_smaller(mid)) {
            l = mid + 1;
        } else {
            r = mid;
        }
    }
    cout << "! " << l << endl;
}

int main() {
    fastio;
    solve();
    return 0;
}