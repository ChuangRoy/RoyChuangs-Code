#pragma GCC optimize("Ofast")
#include <iostream>
#include <utility>
#include <queue>
#include <vector>
#include <algorithm>
#define AC cin.tie(0)->sync_with_stdio(false);
#define pb emplace_back
#define ALL(x) begin(x),end(x)
#define MP(x, y) make_pair((x), (y))

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

void solve () {
    int n; cin >> n;
    vector<pair<pii, int>> v; // (a, b), i
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.pb(MP(MP(a, b), i));
    }
    sort(ALL(v));
    vector<int> room(n);
    priority_queue<pii, vector<pii>, greater<pii>> pq; // (b, room)
    int rooms_cnt = 1;
    pq.push(MP(v[0].first.second, 1));
    room[v[0].second] = 1;
    for (int i = 1; i < n; i++) {
        auto cur = v[i].first;
        if (cur.first > pq.top().first) {
            room[v[i].second] = pq.top().second;
            pq.pop();
            pq.push(MP(cur.second, room[v[i].second]));
        } else {
            room[v[i].second] = ++rooms_cnt;
            pq.push(MP(cur.second, room[v[i].second]));
        }
    }
    cout << rooms_cnt << '\n';
    for (auto i : room) cout << i << ' ';
    cout << '\n';
}

int main () {
    AC
    solve();
    return 0;
}