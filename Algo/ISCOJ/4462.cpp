#include <bits/stdc++.h>
using namespace std;

int main () {
	ios_base::sync_with_stdio(false);cin.tie(0);
	string s;
	getline(cin, s);
	// cout << ">" << s.length();
	for (int i = 0; i < (int)s.length() - 3; i++) {
		// cout << ">" << s[i] << s[i+1] << s[i+2] << s[i+3] << endl;
		if (s[i] == 'D' && s[i+1] == 'i' && s[i+2] == 'a' && s[i+3] == 'n') {
			s[i] = 'W';
			s[i+1] = 'e';
			s[i+2] = 'a';
			s[i+3] = 'k';		
		}
		if (s[i] == 'd' && s[i+1] == 'i' && s[i+2] == 'a' && s[i+3] == 'n') {
			s[i] = 'w';
			s[i+1] = 'e';
			s[i+2] = 'a';
			s[i+3] = 'k';
		}
	}
	cout << s << endl;
	return 0;
}