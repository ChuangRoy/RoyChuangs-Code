#include <iostream>
#include <cmath>
using namespace std;

int main () {
    int m, n, an;
    unsigned long long int sum = 0;
    cin >> n;
    cin >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) {
            an = i * pow(10, int(log10(j)+1));
            sum += an;
            sum += j;
        }
        
    cout << sum << endl;
    return 0;
}