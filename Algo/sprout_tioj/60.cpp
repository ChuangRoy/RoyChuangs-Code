#pragma GCC optimize("Ofast")
#include <iostream>
#include <utility>
#include <climits>
#include <vector>
#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define ALL(x) begin(x),end(x)
#define pb push_back

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

bool check (vector<vector<int>> &puzzle, int y, int x) {
    for (int i = 0; i < 9; i++) {
        if (i != x && puzzle[y][i] == puzzle[y][x])
            return 0;
        if (i != y && puzzle[i][x] == puzzle[y][x])
            return 0;
    }
    int top_x = x - x % 3,
        top_y = y - y % 3;
    for (int i = top_y; i < top_y + 3; i++) {
        for (int j = top_x; j < top_x + 3; j++) {
            if (i == y && j == x) continue;
            if (puzzle[i][j] == puzzle[y][x])
                return 0;
        }
    }
    return 1;
}

int main () {
    AC
    int t; cin >> t;
    while (t--) {
        string s;
        cin >> s;
        vector<vector<int>> puzzle(9, vector<int> (9, 0));
        vector<pii> Blanks;
        int unknowns = 0;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                int cur = i * 9 + j;
                if (s[cur] == '.') {
                    Blanks.pb({i, j});
                    unknowns++;
                } else {
                    puzzle[i][j] = s[cur] - '0';
                }
            }
        }
        int steps = 0;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (puzzle[i][j] != 0 && !check(puzzle, i, j)) {
                    steps = -1;
                    break;
                }
            }
            if (steps < 0) break;
        }
        while (steps < unknowns && steps >= 0) {
            auto [cur_y, cur_x] = Blanks[steps];
            if (puzzle[cur_y][cur_x] == 9) {
                steps--;
                puzzle[cur_y][cur_x] = 0;
            } else {
                puzzle[cur_y][cur_x]++;
                if (check(puzzle, cur_y, cur_x)) {
                    steps++;
                }
            }
        }
        if (steps < 0) {
            cout << "No solution.\n";
        } else {
            for (int i = 0; i < 9; i++) {
                for (auto j : puzzle[i]) cout << j;
            }
            cout << '\n';
        }
    }
    return 0;
}