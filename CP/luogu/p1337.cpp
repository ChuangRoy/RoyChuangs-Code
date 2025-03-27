#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <cmath>
#include <iomanip>
#include <queue>
#include <ctime>
#define AC ios_base::sync_with_stdio(false); std::cin.tie(nullptr); std::cout.tie(nullptr);
#define pb emplace_back
#define ALL(x) begin(x),end(x)
#define SQ(x) ((x)*(x))

using namespace std;

const double down = 0.999;
const double scale = 0.4;
const double TL = 0.89;
double ansx, ansy, answ;
double xx, yy;
int n;
double x[1000], y[1000], w[1000];

auto seed = chrono::steady_clock::now().time_since_epoch().count();
mt19937 rng(seed);

int randint (int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

double randprob () {
    float prob = randint(0, 1e6);
    prob /= 1e6;
    return prob;
}

double calW (double nx, double ny) {
    double ret = 0;
    for (int i = 0; i < n; i++) {
        ret += w[i] * sqrt(SQ(x[i]-nx) + SQ(y[i]-ny));
    }
    return ret;
}


void simulated_annealing () {
    double T = 110000;
    while (T > 1e-17) {
        double nx = xx + (randprob()*2 - 1) * T;
        double ny = yy + (randprob()*2 - 1) * T;
        double nw = calW(nx, ny);
        double d = nw - answ;
        if (d < 0) {
            xx = nx;
            ansx = nx;
            yy = ny;
            ansy = ny;
            answ = nw;
        } else if (exp(-d/T) > randprob()) {
            xx = nx;
            yy = ny;
        }
        T *= down;
    }
}

int main () {
    AC
    cin >> n;
    int sx = 0, sy = 0;
    auto clk = clock();
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> w[i];
        sx += x[i];
        sy += y[i];
    }
    ansx = sx / (double)n;
    ansy = sy / (double)n;
    answ = calW(ansx, ansy);
    while (double (clock() - clk) / CLOCKS_PER_SEC < TL)
        simulated_annealing();
    cout << fixed << setprecision(3) << ansx << ' ' << ansy << '\n';
    return 0;
}