#include <bits/stdc++.h>
using namespace std;

int main () {
	ios_base::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while (T--) {
	    int m, n;
	    cin >> m >> n;
	    if (m + 1 == n)
            cout << "Malantaŭen" << "\n";
        else
            cout << "Unua movo" << "\n";
    }
	return 0;
}
