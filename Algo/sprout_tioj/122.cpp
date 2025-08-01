#pragma GCC optimize("Ofast")
#include "lib0122.h"
#include <utility>
#include <vector>
#include <algorithm>
#define ALL(x) begin(x),end(x)
#define MP(x, y) make_pair(x, y)
#define SZ(x) ((int) x.size())
#define pb emplace_back
 
using namespace std;
typedef long long ll;

void solve(int N, long long K, long long A[]) {
    vector<pair<ll, vector<int>>> s1(1, MP(0, vector<int> {})), s2(1, MP(0, vector<int> {}));
    int half = (N+1) / 2;
    for (int i = 0; i < half; i++) {
        int sz1 = SZ(s1);
        for (int j = 0; j < sz1; j++) {
            auto s = s1[j];
            if (s.first + A[i] == K) {
                for (auto it : s.second) Report(it);
                Report(i+1);
                Report(-1);
                return;
            } else if (s.first + A[i] < K) {
                s.second.pb(i+1);
                s1.pb(MP(s.first + A[i], s.second));
            }
        }
    }
    for (int i = half; i < N; i++) {
        int sz2 = SZ(s2);
        for (int j = 0; j < sz2; j++) {
            auto s = s2[j];
            if (s.first + A[i] == K) {
                for (auto it : s.second) Report(it);
                Report(i+1);
                Report(-1);
                return;
            } else if (s.first + A[i] < K) {
                s.second.pb(i+1);
                s2.pb(MP(s.first + A[i], s.second));
            }
        }
    }
    sort(ALL(s1));
    sort(ALL(s2));
    // for (auto s : s2) cerr << s.first << endl;
    int l = 0, r = SZ(s2) - 1;
    while (l < SZ(s1) && r >= 0) {
        if (s1[l].first + s2[r].first == K) {
            for (auto it : s1[l].second) Report(it);
            for (auto it : s2[r].second) Report(it);
            Report(-1);
            return;
        } else if (s1[l].first + s2[r].first > K) {
            r--;
        } else {
            l++;
        }
    }
    Report(-1);
}