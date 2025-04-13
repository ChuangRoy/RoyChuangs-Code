/* lib0114.h */
void solve(int N, int X, int Y);
void Report(int x1, int y1, int x2, int y2, int x3, int y3);


/* written in c++ syntax */
#include <iostream>

void Report(int x1, int y1, int x2, int y2, int x3, int y3) {
    std::cerr << "Report: "
              << x1 << ' ' << y1 << ' '
              << x2 << ' ' << y2 << ' '
              << x3 << ' ' << y3 << std::endl;
}

int main () {
    solve(4, 3, 4);
    return 0;
}