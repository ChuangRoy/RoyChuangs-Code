#pragma GCC optimize("Ofast")
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef long long ll;

int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int permutations[6][3] = {{0, 1, 2}, {0, 2, 1}, {1, 0, 2}, {1, 2, 0}, {2, 0, 1}, {2, 1, 0}};

int getNum () {
    char c1, c2;
    c1 = getchar();
    while (c1 <'0' || c1 > '9') c1 = getchar();
    c2 = getchar();
    return (c1 - '0') * 10 + (c2 - '0');
}

bool checkDays (int d, int m, int y) {
    if (y < 1) return 0;
    if (m > 12 || m < 1) return 0;
    if (y % 4 == 0) days[2]++;
    if (d > days[m] || d < 1) {
        days[2] = 28;
        return 0;
    }
    return 1;
}

int getDays (int d, int m, int y) {
    if (!checkDays(d, m, y)) return -1;
    if (y % 4 == 0) days[2]++;
    int ret = 0;
    for (int i = 1; i < m; i++) ret += days[i];
    ret += d;
    days[2] = 28;
    return ret;
}

int main () {
    int dd, mm, yy;
    int kd, km, ky;
    int k[3];
    int yyd, kyd;
    dd = getNum(); mm = getNum(); yy = getNum();
    k[0] = getNum(); k[1] = getNum(); k[2] = getNum();
    // printf("%d %d %d\n", dd, mm, yy);
    // printf("%d %d %d\n", k[0], k[1], k[2]);
    yyd = getDays(dd, mm, yy);
    for (int i = 0; i < 6; i++) {
        kd = k[permutations[i][0]];
        km = k[permutations[i][1]];
        ky = k[permutations[i][2]];
        if (!checkDays(kd, km, ky)) continue;
        kyd = getDays(kd, km, yy);
        if (yy - ky > 18 || ((yy - ky == 18) && (yyd >= kyd)) ) {
            printf("YES\n");
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}