#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


/* Template */
#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define pb emplace_back
/* End of Template */

int main ()
{
    AC
    int t; cin >> t;
    for (int q = 1; q <= t; q++) {
        vector<unsigned int> groups(1e6, 0);
        int n; cin >> n;
        for (int i = 1; i <= n; i++) {
            int k; cin >> k;
            for (int j = 0; j < k; j++) {
                int a;
                cin >> a;
                groups[a] = i;
            }
        }
        vector<queue<int>> rec;
        vector<int> group_pos(1001, -1);
        int m; cin >> m;
        cout << "Line #" << q << '\n';
        int i = 0;
        while (m--) {
            string op;
            cin >> op;
            if (op == "ENQUEUE") {
                int a; cin >> a;
                if (group_pos[groups[a]] == -1 || group_pos[groups[a]] < i) {
                    queue<int> temp;
                    temp.push(a);
                	rec.pb(temp);
                	if (groups[a] != 0) {
                		group_pos[groups[a]] = int(rec.size()) - 1;
                	}
                } else {
                	rec[group_pos[groups[a]]].push(a);
                }
            } else if (op == "DEQUEUE") {
                cout << rec[i].front() << '\n';
                rec[i].pop();
                if (rec[i].empty()) i++;
            }
        }
    }
    return 0;
}