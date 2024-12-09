#include <bits/stdc++.h>
using namespace std;

int main () {
	int T;
	cin >> T;
	while (T--) {
		string s;
		cin >> s;
		long long c = 0;
		for (int i = 4; i <= (int)s.length(); i++) {
			for (int j = 0; j <= (int)s.length() - i; j++) {
				string a = s.substr(j, i);
				if (!(stoi(a.substr(i-3, 3)) % 8)) {
					if (!(stoll(a)%253)) {
						c++;
					}
				}
			}
		}
		cout << c << endl;
	}
}