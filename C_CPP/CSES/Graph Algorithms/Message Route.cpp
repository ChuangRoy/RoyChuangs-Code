#include <bits/stdc++.h>
using namespace std;

int main () {
    int n, m;
    cin >> n >> m;
    vector <vector<int>> graph(n);
    while (m--) {
        int a, b;
        cin >> a >> b;
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
    }
    int cnt = 1;
    vector<bool> visited(n, 0);
    vector<bool> pushed(n, 0);
    vector<int> rec(n);
    queue<pair<int, int>> nxts;
    nxts.push(make_pair(0, 1));
    while (!nxts.empty() && !visited[n-1]) {
        pair<int, int> cur = nxts.front();
        nxts.pop();
        if (!visited[cur.first]) {
            visited[cur.first] = 1;
            if (cur.first == n - 1) {
                cnt = cur.second;
            } else {
                for (int i = 0; i < graph[cur.first].size(); i++) {
                    if (!visited[graph[cur.first][i]] && !pushed[graph[cur.first][i]]) {
                        nxts.push(make_pair(graph[cur.first][i], cur.second + 1));
                        rec[graph[cur.first][i]] = cur.first;
                        pushed[graph[cur.first][i]] = 1;
                    }
                }
            }
        }
    }
    if (visited[n-1]) {
        cout << cnt << "\n";
        vector<int> reverse;
        int i = n-1;
        reverse.push_back(n);
        while (rec[i] != 0) {
            reverse.push_back(rec[i] + 1);
            i = rec[i];
        }
        cout << 1 << " ";
        for (i = reverse.size()-1; i > -1; i--) {
            cout << reverse[i] << " ";
        }
        cout << "\n";
    } else {
        cout << "IMPOSSIBLE" << "\n";
    }

    return 0;
}
