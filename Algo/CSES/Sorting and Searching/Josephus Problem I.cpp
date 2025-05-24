#include <bits/stdc++.h>

#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define pii pair<int, int>
#define pb push_back

using namespace std;
using ll = long long;

int main ()
{
    AC
    int n; cin >> n;
    queue<int> q;
    bool flag = 0;
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }
    while (!q.empty()) {
        int eliminate = q.front();
        q.pop();
        if (flag) {
            flag = 0;
            cout << eliminate << ' ';
        } else {
            flag = 1;
            q.push(eliminate);
        }
    }
    return 0;
}