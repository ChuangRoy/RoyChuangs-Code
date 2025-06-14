#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

using namespace std;

const int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
const int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};

void solve() {
    int N; cin >> N;
    vector<vector<int>> distance(N, vector<int> (N, -1));
    queue<pair<pair<int, int>, int>> nxts;
    nxts.push({{0, 0}, 0});
    while (!nxts.empty()) {
        auto top = nxts.front();
        nxts.pop();
        auto pos = top.first;
        if (pos.first < 0 || pos.first >= N || pos.second < 0 || pos.second >= N) continue;
        if (distance[pos.first][pos.second] != -1) continue;
        distance[pos.first][pos.second] = top.second;
        for (int i = 0; i < 8; i++) {
            nxts.push({{pos.first + dx[i], pos.second+dy[i]}, top.second + 1});
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << distance[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    solve();
    return 0;
}