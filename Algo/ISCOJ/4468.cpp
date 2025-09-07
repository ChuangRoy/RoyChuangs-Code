#include <bits/stdc++.h>
using namespace std;

int main ()
{
    ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
    int n; cin >> n;
    vector<int> pos(n+1, 0);
    int x;
    for (int i = 0; i < n; i++) {
        cin >> x;
        pos[x] = i;
    }
    int r = 0;
    cin >> x;
    int target = pos[x];
    vector<int> rec(1, target);
    for (int i = 1; i < n; i++) {
        cin >> x;
        target = pos[x];
        if (rec[r] < target) {
            rec.push_back(target);
            r++;
        } else {
            auto replace = lower_bound(rec.begin(), rec.end(), target);
            *replace = target;
        }
    }
    cout << r + 1 << "\n";
    return 0;
}