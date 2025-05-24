#pragma GCC optimize("Ofast")
#include <iostream>
#include <utility>
#include <vector>
#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define pb emplace_back
#define ALL(x) begin(x),end(x)

using namespace std;
typedef long long ll;

int main () {
    AC
    int n; cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    bool arthseq = 1;
    for (int i = 2; i < n; i++) {
        if (a[i]+a[i-2] != a[i-1]+a[i-1]) {
            arthseq = 0;
            cout << "No\n";
            break;
        }
    }
    if (arthseq) cout << "Yes\n";
    bool geoseq = 1;
    for (int i = 2; i < n; i++) {
        if (a[i]*a[i-2] != a[i-1]*a[i-1]) {
            geoseq = 0;
            cout << "No\n";
            break;
        }
    }
    if (geoseq) cout << "Yes\n";
    return 0;
}