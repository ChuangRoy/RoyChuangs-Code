#pragma GCC optimize("Ofast")
#include <algorithm>
#include <iostream>
#include <map>
#define fastio cin.tie(0)->sync_with_stdio(false)

using namespace std;
typedef long long ll;

void query (ll s, map<ll, ll> &mp) {
    if (mp.empty()) return;
    // mp[start] = end
    auto up = mp.lower_bound(s);
    auto low = up;

    if (up == mp.begin()) {
        ll start = up->first + 1, end = up->second;
        cout << up->first << '\n';
        mp.erase(up);
        if (start <= end) {
            mp[start] = end;
        }
        return;
    }

    low--;
    if (low->first <= s and s <= low->second) {
        ll start = low->first, end = low->second;
        cout << s << '\n';
        mp.erase(low);
        if (start <= s - 1) {
            mp[start] = s - 1;
        }
        if (s + 1 <= end) {
            mp[s + 1] = end;
        }
        return;
    }

    if (up == mp.end() or (up->first - s) > (s - low->second)) {
        cout << low->second << '\n';
        ll start = low->first, end = low->second - 1;
        mp.erase(low);
        if (start <= end) {
            mp[start] = end;
        }
    } else {
        ll start = up->first + 1, end = up->second;
        cout << up->first << '\n';
        mp.erase(up);
        if (start <= end) {
            mp[start] = end;
        }
    }
}

void solve () {
    map<ll, ll> mp;
    int N; cin >> N;
    for (int i = 0; i < N; i++) {
        ll l, r;
        cin >> l >> r;
        mp[l] = r;
    }
    int Q; cin >> Q;
    while (Q--) {
        ll s; cin >> s;
        query(s, mp);
    }
}

int main () {
    fastio;
    solve();
    return 0;
}