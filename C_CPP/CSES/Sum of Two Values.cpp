#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main() {
    int n, x;
    cin >> n >> x;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
    	cin >> v[i].first;
    	v[i].second = i + 1;
    }
    sort(v.begin(), v.end());
	int l = 0;
    int r = n - 1;
    long long sum = v[0].first + v[r].first;
    while (l < r) {
    	if (sum > x) {
    		sum -= v[r--].first;
    		if (r >-1)
    			sum += v[r].first;
    	}else if (sum < x) {
    		sum -= v[l++].first;
    		if (l < n)
    			sum += v[l].first;
    	}else
    		break;
    }
	if (sum == x && l < r)
		cout << v[l].second << " " << v[r].second << endl;
	else
		cout << "IMPOSSIBLE" << endl;
}