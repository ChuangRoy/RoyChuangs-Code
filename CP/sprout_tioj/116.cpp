#pragma GCC optimize("Ofast")
#include "lib0116.h"
#include <climits>

int ans[1000000];

void dnc (int startX, int endX, int startY, int endY) {
    if (endY < startY) return;
    int midCol = (endY - startY) >> 1;
    int maxIdx = -1;
    int maxVal = INT_MIN;
    for (int i = startX + midCol; i <= endX - midCol; i++) {
        int curVal = GetVal(startY + midCol + 1, i + 1);
        if (curVal > maxVal) {
            maxIdx = i;
            maxVal = curVal;
        }
    }
    ans[startY + midCol] = maxIdx;
    dnc(startX, maxIdx - 1, startY, startY + midCol - 1);
    dnc(maxIdx + 1, endX, startY + midCol + 1, endY);
}

void solve (int N, int M) {
    dnc(0, M-1, 0, N-1);
    for (int i = 0; i < N; i++)
        Report(ans[i]+1);
}