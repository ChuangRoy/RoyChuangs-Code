#pragma GCC optimize("Ofast")
#include "lib0114.h"

void calSubGrid (int N, int X, int Y, int x1, int y1) {
    if (N <= 1) return;
    int rotation = (Y >= N/2+y1) + (X >= N/2+x1) * 2;
    if (rotation == 0) {
        Report(x1+N/2  , y1+N/2-1,
               x1+N/2  , y1+N/2  ,
               x1+N/2-1, y1+N/2);
        calSubGrid(N/2, X, Y, x1, y1);
        calSubGrid(N/2, x1+N/2-1, y1+N/2, x1, y1+N/2);
        calSubGrid(N/2, x1+N/2, y1+N/2-1, x1+N/2, y1);
        calSubGrid(N/2, x1+N/2, y1+N/2, x1+N/2, y1+N/2);
    }
    if (rotation == 1) {
        Report(x1+N/2-1, y1+N/2-1,
               x1+N/2  , y1+N/2-1,
               x1+N/2  , y1+N/2  );
        calSubGrid(N/2, x1+N/2-1, y1+N/2-1, x1, y1);
        calSubGrid(N/2, X, Y, x1, y1+N/2);
        calSubGrid(N/2, x1+N/2, y1+N/2-1, x1+N/2, y1);
        calSubGrid(N/2, x1+N/2, y1+N/2, x1+N/2, y1+N/2);
    }
    if (rotation == 2) {
        Report(x1+N/2-1, y1+N/2-1,
               x1+N/2  , y1+N/2  ,
               x1+N/2-1, y1+N/2  );
        calSubGrid(N/2, x1+N/2-1, y1+N/2-1, x1, y1);
        calSubGrid(N/2, x1+N/2-1, y1+N/2, x1, y1+N/2);
        calSubGrid(N/2, X, Y, x1+N/2, y1);
        calSubGrid(N/2, x1+N/2, y1+N/2, x1+N/2, y1+N/2);
    }
    if (rotation == 3) {
        Report(x1+N/2-1, y1+N/2-1,
               x1+N/2  , y1+N/2-1,
               x1+N/2-1, y1+N/2  );
        calSubGrid(N/2, x1+N/2-1, y1+N/2-1, x1, y1);
        calSubGrid(N/2, x1+N/2-1, y1+N/2, x1, y1+N/2);
        calSubGrid(N/2, x1+N/2, y1+N/2-1, x1+N/2, y1);
        calSubGrid(N/2, X, Y, x1+N/2, y1+N/2);
    }
}

void solve (int N, int X, int Y) {
    calSubGrid(N, X, Y, 1, 1);
}