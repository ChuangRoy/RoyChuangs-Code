// Problem: Grid Paths
// Contest: CSES - CSES Problem Set
// URL: https://cses.fi/problemset/task/1625
// Memory Limit: 512 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
 
#pragma GCC optimize("Ofast")
 
#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);

char rec[48];
bool visited[9][9];
int ans = 0;

void dfs (int x, int y, int k) {
    if (visited[y][x] || (x == 1 && y == 7 && k != 48)) return;
    if (x == 1 && y == 7 && k == 48) {
        ans++;
        return;
    }
    char &cur = rec[k];
    // GPT Orz
    if (visited[y][x-1] && visited[y][x+1] && !visited[y-1][x] && !visited[y+1][x])
        return;
    if (visited[y-1][x] && visited[y+1][x] && !visited[y][x-1] && !visited[y][x+1])
        return;
    visited[y][x] = 1;
    if(cur == '?'){
        // Forced left: left cell free, but both up and down are blocked.
        if(!visited[y][x-1] && visited[y-1][x] && visited[y+1][x]) {
            dfs(x-1, y, k+1);
            visited[y][x] = false;
            return;
        }
        // Forced right
        if(!visited[y][x+1] && visited[y-1][x] && visited[y+1][x]) {
            dfs(x+1, y, k+1);
            visited[y][x] = false;
            return;
        }
        // Forced up
        if(!visited[y-1][x] && visited[y][x-1] && visited[y][x+1]) {
            dfs(x, y-1, k+1);
            visited[y][x] = false;
            return;
        }
        // Forced down
        if(!visited[y+1][x] && visited[y][x-1] && visited[y][x+1]) {
            dfs(x, y+1, k+1);
            visited[y][x] = false;
            return;
        }
    }
    // Optimized by ChatGPT
    if(cur == 'U' || cur == '?') {
        if(!visited[y-1][x])
            dfs(x, y-1, k+1);
    }
    if(cur == 'D' || cur == '?') {
        if(!visited[y+1][x])
            dfs(x, y+1, k+1);
    }
    if(cur == 'L' || cur == '?') {
        if(!visited[y][x-1])
            dfs(x-1, y, k+1);
    }
    if(cur == 'R' || cur == '?') {
        if(!visited[y][x+1])
            dfs(x+1, y, k+1);
    }
    visited[y][x] = 0;
}

int main () {
    AC
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < 9; i++) {
        visited[0][i] = 1;
        visited[8][i] = 1;
        visited[i][0] = 1;
        visited[i][8] = 1;
    }
    for (int i = 0; i < 48; i++) {
        cin >> rec[i];
    }
    dfs(1, 1, 0);
    cout << ans << '\n';
    return 0;
}
