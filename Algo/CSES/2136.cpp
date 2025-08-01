#pragma GCC optimize("Ofast")
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

using namespace std;

int main () {
    AC
    int n, k;
    cin >> n >> k;
    int a[20001];
    memset(a, 0, sizeof(a));
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < k; j++) {
            a[i] += ((s[j] == '1') << j);
        }
    }
    int ans = 31;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            ans = min(__builtin_popcount(a[i]^a[j]), ans);
        }
    }
    cout << ans << '\n';
    return 0;
}