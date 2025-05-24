#include <bits/stdc++.h>
using namespace std;

int main () {
	int n;
	cin >> n;
	string name[n];
	int k = 0, a;
	for (int i = 0; i < n; i++) {
		cin >> name[i] >> a;
		k = (k + a) % n;
	}
	cout << name[k] << "太電了OrzOrz";
}