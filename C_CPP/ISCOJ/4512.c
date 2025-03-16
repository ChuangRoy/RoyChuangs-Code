#pragma GCC target("sse,sse2,sse3,ssse3,abm,avx")
#pragma GCC optimize("Ofast")
#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

int main () {
    int n;
    scanf("%d", &n);
    if (n == 0) return 0;
    ll a, money = 100;
    scanf("%lld", &a);
    a /= 86400;
    printf("100\n");
    ll b;
    for (int i = 1; i < n; i++) {
        scanf("%lld", &b);
        b /= 86400;
        if (b == a) continue;
        if (b - a > 1) {
            money -= 20 * (b - a - 1);
        } else {
            money += 10;
        }
        if (money < 100) money = 100;
        if (money > 500) money = 500;
        printf("%lld\n", money);
        a = b;
    }
    return 0;
}