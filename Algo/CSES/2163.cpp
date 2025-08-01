#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define pb emplace_back

const int mod = 1e9 + 7;

int main ()
{
    AC
    int n, k;
    cin >> n >> k;
    // divide vector into pieces : faster for O(n) erasing
    vector<vector<int>> a;
    int vec_blk_size = sqrt(n);
    int cnt = 0;
    vector<int> vec;
    for (int i = 1; i <= n; i++) {
        if (cnt > vec_blk_size) {
            a.pb(vec);
            vec.clear();
            cnt = 0;
        }
        vec.pb(i);
        cnt++;
    }
    if (!vec.empty()) {
        a.pb(vec);
    }
    // complex !!!
    int row = 0, col = 0;
    while (n) {
        int j = k % n;
        n--;
        while (j) {
            if (col + j >= a[row].size()) {
                j -= (a[row].size() - col);
                col = 0; // bruh i forgot this line and received lots of error
                row++;
                if (row == a.size()) row = 0;
            } else {
                col += j;
                j = 0;
            }
        }
        // when j == 0
        while (a[row].size() <= col) {
            col = 0;
            row++;
            if (row == a.size()) row = 0;
        }
        cout << a[row][col] << ' ';
        if (n) {
            a[row].erase(a[row].begin() + col);
            // del 1 element and overflow 1 col
            while (col >= a[row].size()) {
                col = 0;
                row++;
                if (row == a.size()) row = 0;
            }
        }
    }
    cout << '\n';
    return 0;
}