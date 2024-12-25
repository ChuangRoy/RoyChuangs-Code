#include <bits/stdc++.h>
using namespace std;

const int arr_size = 2e5;
pair<int, int> arr[arr_size];

bool comp(pair<int, int> a, pair<int, int> b) {
	return;
}

int main () {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i].first >> arr[i].second;
	}
	sort(arr, arr + n, comp);
	vector<pair<int, int>> rec(1, arr[0]); int r = 0;
	for (int i = 1; i < n; i++) {
		if (rec[r] <= arr[i]) {
			rec.push_back(arr[i]);
			r++;
		} else {
			auto replace = lower_bound(rec.begin(), rec.end(), arr[i]);
			*replace = arr[i];
		}
	}
	cout << r + 1 << "\n";
	return 0;
}
