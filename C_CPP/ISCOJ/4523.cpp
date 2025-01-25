#include <bits/stdc++.h>
using namespace std;

int main () {
	int n;
	cin >> n;
	string name; int k;
	while (cin >> name >> k) {
		if (k < n - 10)
			cout << name << "太高lalalalala !" << endl;
		else if (k > n + 10)
			cout << name << "太低lalalalalalala !" << endl;
		else
			cout << name << "太強lalalala !" << endl;
	}
}