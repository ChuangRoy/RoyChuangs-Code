#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    if ((n%4) && ((n+1)%4)) {
        cout << "NO";
        return 0;
    }
    cout << "YES" << '\n';
    set<int> s1, s2;
    int i;
    for (i = n; i >= 4; i-=4) {
        s1.insert(i);
        s2.insert(i-1);
        s2.insert(i-2);
        s1.insert(i-3);
    }
    if (i == 3) {
        s1.insert(1);
        s1.insert(2);
        s2.insert(3);
    }
    cout << s1.size() << '\n';
    for (auto i : s1) cout << i << ' ';
    cout << '\n';
    cout << s2.size() << '\n';
    for (auto i : s2) cout << i << ' ';
    cout << '\n';
    return 0;
}