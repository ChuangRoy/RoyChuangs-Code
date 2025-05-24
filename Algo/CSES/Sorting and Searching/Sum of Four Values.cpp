#pragma GCC optimize("Ofast")
#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

void solve () {
 	int N;
 	long long x;
 	cin >> N >> x;
 	vector<pair<long long, int>> nums(N);
 	for (int i = 0; i < N; i++) {
 	    long long k; cin >> k;
 	    nums[i].first = k;
 	    nums[i].second = i + 1;
 	}
 	sort(nums.begin(), nums.end());
 	for (int l = 0; l < N - 3 ; l++) {
 		for (int r = l + 3; r < N; r++) {
 			int ll = l +  1;
 			int rr = r - 1;
 			long long target = x - nums[l].first - nums[r].first;
 			if (x - target < 0) continue;
 			if (x - target < nums[l].first*2 || x - target > nums[r].first*2) continue;
 			while (ll < rr) {
 			    long long sum = nums[ll].first + nums[rr].first;
 			    if (sum == target) {
 			        cout << nums[l].second << ' ' << nums[ll].second << ' '
 			                << nums[rr].second << ' ' << nums[r].second;
 			        return;
 			    }
 			    if (sum < target) ll++;
 			    else rr--;
 			}
		}
	}
	cout << "IMPOSSIBLE\n";
}

int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
	return 0;
} 
