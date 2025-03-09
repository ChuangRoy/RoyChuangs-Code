#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

int main () {
    AC
    int x, n;
    cin >> x >> n;
    set<int> s;
    multiset<int> l;
    l.insert(x);
    s.insert(0);
    s.insert(x);
    while (n--) {
        int p;
        cin >> p;
        auto end = s.upper_bound(p);
        auto begin = end;
        begin--;
        l.erase(l.find(*end - *begin));
        l.insert(p - *begin);
        l.insert(*end - p);
        s.insert(p);
        cout << *l.rbegin() << ' ';
    }
    return 0;
}