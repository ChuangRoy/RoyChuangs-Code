#include <bits/stdc++.h>
using namespace std;

int main () {
	ios_base::sync_with_stdio(false); cin.tie(0);
	string s1, s2; cin >> s1; cin >> s2;
	string p;
	cin >> p;
	int a;
	if ((int) p.length() % 2) {
		for (int i = 0 ; i < (int) p.length(); i++) {
			a = (s1[(int) p[i] - (int) 'a'] - 'a') % 26 + 'a';
			cout << char(a);
		}
	} else {
		for (int i = 0 ; i < (int) p.length(); i++) {
			a = (s2[(int) p[i] - (int) 'a'] - 'a') % 26 + 'a';
			cout << char(a);
		}
	}
	return 0;
}
