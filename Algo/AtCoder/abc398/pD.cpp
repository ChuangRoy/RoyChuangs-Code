#pragma GCC optimize("Ofast")
#include <iostream>
#include <utility>
#include <string>
#include <cstring>
#include <map>
#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define pb push_back
#define ALL(x) begin(x),end(x)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
bool grid[400005];

int main () {
    AC
    memset(grid, 0, sizeof(grid));
    int n, r, c;
    cin >> n >> r >> c;
    string s;
    cin >> s;
    map<pii, int> mp;
    int segment = 2;
    int origin_x = 0, origin_y = 0;
    mp[{0, 0}] = 1;
    grid[1] = 1;
    for (char op : s) {
        if (op == 'N') {
            origin_y++;
            r++;
        } else if (op == 'S') {
            origin_y--;
            r--;
        } else if (op == 'E') {
            origin_x--;
            c--;
        } else {
            origin_x++;
            c++;
        }
        if (mp[{origin_y, origin_x}] == 0) {
            mp[{origin_y, origin_x}] = segment++;
        }
        if (mp[{r, c}] == 0) {
            mp[{r, c}] = segment++;
        }
        if (grid[mp[{r, c}]]) cout << 1;
        else cout << 0;
        grid[mp[{origin_y, origin_x}]] = 1;
    }
    return 0;
}