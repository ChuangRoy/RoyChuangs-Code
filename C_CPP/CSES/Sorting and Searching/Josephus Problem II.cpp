#include <bits/stdc++.h>

#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define pii pair<int, int>
#define ff first
#define ss second
#define pb push_back

using namespace std;
using ll = long long;

int main ()
{
    AC
    int n; cin >> n;
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        q.push(i);
    }
    int cnt = 0;
    int k; cin >> k;
    while (!q.empty()) {
        int k_converted = k % n;
        int eliminate = q.front();
        q.pop();
        if (cnt == k_converted) {
            cnt = 0;
            n--;
            cout << eliminate << ' ';
        } else {
            cnt++;
            q.push(eliminate);
        }
    }
    return 0;
}