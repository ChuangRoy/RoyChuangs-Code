// Problem: Subarray Sums II
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1661
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define pb emplace_back

int main () {
    AC
    int n, x;
    cin >> n >> x;
    map<ll, ll> mp;
    ll ans = 0;
    ll prefix = 0;
    int a;
    mp[0] = 1;
    for (int i = 0; i < n; i++) {
        cin >> a;
        prefix += a;
        ans += mp[prefix-x];
        mp[prefix]++;
    }
    cout << ans << '\n';
    return 0;
}