#include <bits/stdc++.h>
using namespace std;

int main () {
	int k;
	bool prime;
	while (cin >> k) {
		prime = 1;
		for (int i = 2; i <= sqrt(k) && prime; i++) {
			if (!(k % i)) {
				prime = 0;
			}
		}
		if (k == 1 || k == 0)
			cout << "No" << endl;
		else {
			if (prime)
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
	}
	return 0;
}