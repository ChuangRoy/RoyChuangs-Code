#include <bits/stdc++.h>

#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define pii pair<int, int>
#define ff first
#define ss second
#define pb push_back

using namespace std;
using ll = long long;

int main ()
{
    AC
    string s1, s2;
    cin >> s1 >> s2;
    int a = 4;
    if (s1 == "sick") {
        a -= 2;
    }
    if (s2 == "sick") {
        a -= 1;
    }
    cout << a << '\n';
    return 0;
}