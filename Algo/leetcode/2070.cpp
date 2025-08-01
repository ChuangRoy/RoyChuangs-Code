#include <bits/stdc++.h>
using namespace std;
using ll = long long;

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        sort(items.begin(), items.end(), [](auto &a, auto &b) {
            return a[0] < b[0];
        });
        int N = items.size();
        vector<pair<int, int>> proc;
        for (int i = 0; i < (int) queries.size(); i++) {
            proc.push_back(make_pair(queries[i], i));
        }
        sort(proc.begin(), proc.end());
        vector<int> ans((int) queries.size());
        int i = 0; // processed idx
        int maxBeauty = 0;
        for (auto q : proc) {
            auto [price, idx] = q;
            while (i < N && items[i][0] <= price) {
                maxBeauty = max(items[i][1], maxBeauty);
                i++;
            }
            ans[idx] = maxBeauty;
        }
        return ans;
    }
};


int main () {
    vector<vector<int>> items = {{1,2},{3,2},{2,4},{5,6},{3,5}};
    vector<int> queries = {1, 2, 3, 4, 5, 6};
    auto sol = Solution();
    auto ans = sol.maximumBeauty(items, queries);
    for (auto i : ans) cout << i << endl;
    return 0;
}