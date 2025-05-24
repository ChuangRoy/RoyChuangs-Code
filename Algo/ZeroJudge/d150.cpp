#include <iostream>
#include <algorithm>
using namespace std;

bool cmp (int a, int b) {return (a>b);}

int main () {
    int m, n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> m;
        int ans = 0;
        int shopping_list[m] = {0};
        for (int j = 0; j < m; j++) {
            cin >> shopping_list[j];
        }
        sort(shopping_list, shopping_list+m, cmp);
        for (int j = 0; (j + 2) < m; j += 3) {
            ans += shopping_list [j + 2];
        }
        cout << ans << endl;
    }
    return 0;
}
