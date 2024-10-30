#include <bits/stdc++.h>
using namespace std;

int main () {
	int T;
	cin >> T;
	while (T--) {
		int n;
		cin >> n;
		long a[n];int i=0;
		while (n--)
			cin >> a[i++];
		int a_size = i;
		i = 0;int j = 0;
		long sum = a[0];
		set<pair<int, int>> s;
		pair<int, int> p;
		while (i < a_size && j < a_size) {
			if (sum > 2024)
				sum -= a[i++];
			else {
				if (j < a_size) {
					if (sum == 2024) {
						p = make_pair(i, j);
						s.insert(p);
					}
					sum += a[++j];
				}
				else
					j++;
			}
		}
		i = a_size - 1;j = a_size - 1;
		sum = a[a_size - 1];
		while (i > -1 && j > -1) {
			if (sum > 2024)
				sum -= a[i--];
			else {
				if (j > 0) {
					if (sum == 2024) {
						p = make_pair(j, i);
						s.insert(p);
					}
					sum += a[--j];
				}
				else
					j--;
			}
		}
		cout << s.size() << endl;
		// for (auto i:s)
			// cout << '>' <<  i.first << i.second << endl;
	}
}