#pragma GCC optimize("Ofast")
#include <iostream>
#include <utility>
#include <deque>
#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define pb push_back
#define ALL(x) begin(x),end(x)
#define MP(x) make_pair((x), (x))
#define SQ(x) ((x)*(x))
#define SZ(x) ((int) x.size())

using namespace std;
typedef long long ll;

struct line {
    long long a, b;
};

int s[200001], f[200001];
line l[200000];

bool check(int L1,int L2,int Ln){
    return (l[L2].b-l[L1].b)*(l[L1].a-l[Ln].a) >= (l[Ln].b-l[L1].b)*(l[L1].a-l[L2].a);
}

ll eval (int id, int x) {
    return l[id].a * x + l[id].b;
}

void solve () {
    int n, x;
    cin >> n >> x;
    for (int i = 1; i <= n; i++) cin >> s[i];
    for (int i = 1; i <= n; i++) cin >> f[i];
    l[0].a = x;
    l[0].b = 0;
    deque<int> dq; // store index
    dq.pb(0);
    for (int i = 1; i < n; i++) {
        while (SZ(dq) >= 2 && eval(dq[0], s[i]) > eval(dq[1], s[i])) dq.pop_front();
        l[i].a = f[i];
        l[i].b = eval(dq[0], s[i]);
        while (SZ(dq) >= 2 && check(*(dq.end()-2), *(dq.end()-1), i)) dq.pop_back();
        dq.pb(i);
    }
    while (SZ(dq) >= 2 && eval(dq[0], s[n]) > eval(dq[1], s[n])) dq.pop_front();
    cout << eval(dq[0], s[n]) << '\n';
}

int main () {
    AC
    solve();
    return 0;
}
