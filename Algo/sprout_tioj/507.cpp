#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <cmath>
#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define pb emplace_back
#define ALL(x) x.begin(),x.end()
#define SQ(x) ((x)*(x))
#define SZ(x) ((int) x.size())

using namespace std;

const long long INF = LLONG_MAX;

struct dot {
    long long x, y;
};

vector<dot> dots(2e5+5);

long long get2dis (dot a, dot b) {
    return SQ(b.x - a.x) + SQ(b.y - a.y);
}

long long getDisSq (int start, int end) {
    if (end == start) return INF;
    if (end - start == 1) {
        return get2dis(dots[start], dots[end]);
    }
    int mid = (start + end) >> 1;
    long long centerX = dots[mid].x;
    long long d = min(getDisSq(start, mid), getDisSq(mid+1, end));
    long long dsqrt = ceil(sqrt(d));
    vector<dot> candidate;
    for (int i = start; i <= end; i++) {
        if (abs(dots[i].x - centerX) >= dsqrt) continue;
        candidate.pb(dots[i]);
    }
    sort(ALL(candidate), [](dot a, dot b) {
        return a.y < b.y;
    });
    for (int i = 0; i < SZ(candidate); i++) {
        for (int j = i+1; j < SZ(candidate); j++) {
            if (candidate[j].y < candidate[i].y) continue;
            if (candidate[j].y > candidate[i].y + dsqrt) break;
            d = min(d, get2dis(candidate[i], candidate[j]));
        }
    }
    return d;
}

void solve () {
    int N; cin >> N;
    for (int i = 0; i < N; i++)
        cin >> dots[i].x >> dots[i].y;
    sort(dots.begin(), dots.begin()+N, [](dot a, dot b) {
        return a.x < b.x;
    });
    long long d = getDisSq(0, N - 1);
    cout << d << '\n';
}

int main () {
    AC
    solve();
    return 0;
}