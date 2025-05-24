#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        int Q = queries.size();
        int N = rooms.size();
        for (int i = 0; i < Q; i++) queries[i].push_back(i);

        sort(rooms.begin(), rooms.end(), [](auto &a, auto &b) {
            return a[1] > b[1];
        });
        sort(queries.begin(), queries.end(), [](auto &a, auto &b) {
            return a[1] > b[1];
        });

        vector<int> ans(Q);

        set<int> ids;

        int i = 0;
        for (auto q : queries) {
            int prefered = q[0], minSize = q[1], idx = q[2];
            while (i < N && rooms[i][1] >= minSize) {
                ids.insert(rooms[i][0]);
                i++;
            }
            if (!ids.empty()) {
                auto up = ids.upper_bound(prefered);
                if (up == ids.begin()) {
                    ans[idx] = *up;
                } else if (up == ids.end()) {
                    up--;
                    ans[idx] = *up;
                } else {
                    auto low = up;
                    low--;
                    if (*up - prefered < prefered - *low)
                        ans[idx] = *up;
                    else
                        ans[idx] = *low;
                }
            } else {
                ans[idx] = -1;
            }
        }
        return ans;
    }
};

int main () {
    vector<vector<int>> rooms  = {{2, 2}, {1, 2}, {3, 2}};
    vector<vector<int>> queries = {{3, 1}, {3, 3}, {5, 2}};
    auto sol = Solution();
    auto ans = sol.closestRoom(rooms, queries);
    for (auto i : ans) cout << i << endl;
    return 0;
}