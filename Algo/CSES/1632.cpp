// Problem: Movie Festival II
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1632
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
    int n, k;
    cin >> n >> k;
    vector<pii> movies;
    multiset<int> ends;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        movies.pb(make_pair(a, b));
    }
    sort(movies.begin(), movies.end());
    int i = 0;
    int cnt = k;
    while (i < k) {
        ends.insert(movies[i].second);
        i++;
    }
    while (i < n) {
        if (movies[i].first < *ends.begin()) {
            if (movies[i].second < *ends.rbegin()) {
                ends.erase(ends.find(*ends.rbegin()));
                ends.insert(movies[i].second);
            }
        } else {
            auto it = ends.upper_bound(movies[i].first);
            it--;
            ends.erase(it);
            ends.insert(movies[i].second);
            cnt++;
        }
        i++;
    }
    cout << cnt << '\n';
    return 0;
}