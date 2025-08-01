#pragma GCC optimize("Ofast")
#include <iostream>
#include <utility>
#include <algorithm>
#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define pb emplace_back
#define ALL(x) begin(x),end(x)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main () {
    AC
    int cnt[14] = {0};
    for (int i = 0; i < 7; i++) {
        int a; cin >> a;
        cnt[a]++;
    }
    sort(cnt, cnt + 14, [](auto a, auto b){
        return a > b;
    });
    if (cnt[0] >= 3 && cnt[1] >= 2) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}