#include <iostream>
#include <vector>
using namespace std;
 
int main() {
    int n, x;
    cin >> n >> x;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
    	cin >> v[i];
    }
 
    int ans = 0;
    int r = 1, sum = v[0];
    for (int l = 0; l < n; l++) {
        while (sum < x && r < n) {
            sum += v[r];
            r++;
        }
 
        if (sum == x) ans++;
        
        sum -= v[l];
    }
    
    if (sum == x) ans++;

    cout << ans << '\n';
}