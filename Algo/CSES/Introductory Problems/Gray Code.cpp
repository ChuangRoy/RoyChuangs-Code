#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define ALL(x) begin(x),end(x)
#define pb emplace_back

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

vector<string> gcode (int n)
{
    if (n == 1) {
        return {"0", "1"};
    }
    vector<string> prev = gcode(n-1);
    vector<string> reversed = prev;
    reverse(reversed.begin(), reversed.end());
    int prevSize = 1 << (n-1);
    for (int i = 0; i < prevSize; i++) {
        prev[i] = "0" + prev[i];
        prev.pb("1" + reversed[i]);
    }
    return prev;
}

int main ()
{
    AC
    int n; cin >> n;
    vector<string> ans = gcode(n);
    for (auto i : ans) {
        cout << i << '\n';
    }
    return 0;
}