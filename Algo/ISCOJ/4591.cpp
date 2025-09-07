#include <bits/stdc++.h>
using namespace std;

int main () {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	string s[501];
	for (int i = 0; i < n; i++)
		cin >> s[i];
	bool ans = 0;
	string x[7] = {"I", "LOVE", "U", "1", "3", "1", "4"};
	int i = 0, j = 0;
	while (i <= n && !ans) {
		if (j == 7) {
			ans = 1;
		} else if (i < n){
			if (s[i] == x[j]) {
				i++;
				j++;
			} else if (j > 0){
				j = 0;
			} else {
				i++;
			}
		} else {
			break;
		}
	}
	if (ans) {
		cout << "I LOVE U TOO";
	} else {
		cout << "I AM SO SAD";
	}
	return 0;
}