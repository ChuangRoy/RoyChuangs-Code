#pragma GCC optimize("Ofast")
#include <iostream>
#include <utility>
#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define pb emplace_back
#define ALL(x) begin(x),end(x)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

int main () {
    AC
    int n; cin >> n;
    if (n % 2) {
        for (int i = 0; i < n / 2; i++) cout << '-';
        cout << '=';
        for (int i = 0; i < n / 2; i++) cout << '-';
    } else {
        for (int i = 1; i < n / 2; i++) cout << '-';
        cout << "==";
        for (int i = 1; i < n / 2; i++) cout << '-';
    }
    return 0;
}