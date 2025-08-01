#include <iostream>

using namespace std;

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int ans = 0;
	for (int i = 2; i <= n; i++) {
	    ans = (ans + 2) % i;
    }
    cout << ans+1 << '\n'; 
	return 0;
}
