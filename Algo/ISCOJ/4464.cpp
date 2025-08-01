// g++ code.cpp -O2 -o a.out -g;./a.out; rm a.out
#include <bits/stdc++.h>
using namespace std;

int main () {
    long n;
    cin >> n;
    int s[n];
    for (int i = 0; i < n; i++)
        cin >> s[i];
    for (int i = n-1; i >= 0; i--) {
        if (s[i]> 0)
            cout << 0 << endl;
        else
            cout << s[i] << endl;
    }
    return 0;
}