#include <bits/stdc++.h>
using namespace std;

int main () {
	ios_base::sync_with_stdio(false);cin.tie(0);
	int n, q;
	cin >> n >> q;
	int *a = new int[n];
	int *da = new int[n+1];
	memset(da, 0, sizeof(da[0]) * n);
	for (int i = 0; i < n; i++)
	    cin >> a[i];
	int l, r, k;
	while (q--) {
	    cin >> l >> r >> k;
	    da[l-1] += k;
	    da[r] -= k;
	}
	int sum = 0;
	for (int j = 0; j < n; j++) {
		sum += da[j];
	    cout << a[j] + sum << " ";
	}
	delete [] a;
	delete [] da;
	return 0;
}
