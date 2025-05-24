#pragma GCC optimize("Ofast")
#include <iostream>
#include <utility>
#include <string>
#include <map>
#include <vector>
#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define pb emplace_back
#define ALL(x) begin(x),end(x)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main () {
    AC
    int n; cin >> n;
    map<string, int> mp;
    map<int, string> name;
    vector<pii> rec(4*n+10, {0, 0});
    int idx = 1;
    while (n--) {
        string p, m, d;
        cin >> p >> m >> d;
        if (mp[p] == 0) mp[p] = idx++;
        int cur = mp[p];
        name[cur] = p;
        if (m != "-1") {
            if (mp[m] == 0) mp[m] = idx++;
            rec[cur].first = mp[m];
            name[mp[m]] = m;
        }
        if (d != "-1") {
            if (mp[d] == 0) mp[d] = idx++;
            rec[cur].second = mp[d];
            name[mp[d]] = d;
        }
    }
    int q; cin >> q;
    while (q--) {
        string p, x;
        cin >> p >> x;
        int cur = mp[p];
        if (x == "MOM") {
            if (rec[cur].first == 0) cout << "EMPTY\n";
            else cout << name[rec[cur].first] << '\n';
        }
        if (x == "DAD") {
            if (rec[cur].second == 0) cout << "EMPTY\n";
            else cout << name[rec[cur].second] << '\n';
        }
        if (x == "GRANDMA") {
            int m = rec[cur].first;
            if (m == 0) {
                cout << "EMPTY\n";
            } else {
                cur = m;
                if (rec[cur].first == 0) cout << "EMPTY\n";
                else cout << name[rec[cur].first] << '\n';
            }
        }
        if (x == "GRANDPA") {
            int d = rec[cur].second;
            if (d == 0) {
                cout << "EMPTY\n";
            } else {
                cur = d;
                if (rec[cur].second == 0) cout << "EMPTY\n";
                else cout << name[rec[cur].second] << '\n';
            }
        }
    }
    return 0;
}