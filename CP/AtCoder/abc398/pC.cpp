#pragma GCC optimize("Ofast")
#include <iostream>
#include <utility>
#include <vector>
#include <map>
#include <algorithm>
#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define pb push_back
#define ALL(x) begin(x),end(x)


using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define int ll
signed main () {
    AC
    int n; cin >> n;
    int mpsz = 1;
    map<int, int> mp;
    map<int, int> idx;
    vector<pii> rec;
    rec.pb({-1, 0});
    for (int i = 1; i <= n; i++) {
        int a; cin >> a;
        if (mp[a] == 0) {
            mp[a] = mpsz++;
            rec.pb({a, 1});
            idx[a] = i;
        } else {
            rec[mp[a]].second++;
        }
    }
    sort(ALL(rec), [](auto a, auto b){
        if (a.second == b.second) return a.first > b.first;
        return a.second > b.second;
    });
    int i = 0;
    while (i < mpsz) {
        if (rec[i].second == 1) break;
        i++;
    }
    if (i == mpsz) {
        cout << -1;
    } else {
        cerr << rec[i].first;
        cout << idx[rec[i].first];
    }
    return 0;
}