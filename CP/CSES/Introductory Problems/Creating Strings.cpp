#pragma GCC optimize("Ofast")
#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <cstring>
#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define pb emplace_back
#define ALL(x) begin(x),end(x)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int cnt[26];
vector<string> out;

void recur (int cd, string s) {
    if (cd == 1) {
        for (int i = 0; i < 26; i++) {
            if (cnt[i]) {
                s += char(i+'a');
            }
        }
        out.pb(s);
        return;
    }
    for (int i = 0; i < 26; i++) {
        if (cnt[i] == 0) continue;
        cnt[i]--;
        recur(cd - 1, s + char(i+'a'));
        cnt[i]++;
    }
}

int main () {
    AC
    string s;
    cin >> s;
    memset(cnt, 0, sizeof(cnt));
    for (auto c : s) cnt[c-'a']++;
    recur((int) s.size(), "");
    cout << (int) out.size() << '\n';
    for (auto it : out) {
        cout << it << '\n';
    }
    return 0;
}