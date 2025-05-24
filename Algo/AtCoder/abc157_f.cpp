#pragma GCC optimize("Ofast")
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

const double down = 0.9999;
const double scale = 0.4;
const double TL = 1.9;
double ansx, ansy, anst;
int n, k;
double x[60], y[60], c[60];

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

double calT (double nx, double ny) {
    vector<double> t(n);
    for (int i = 0; i < n; i++) {
        t[i] = c[i] * sqrt(SQ(x[i]-nx) + SQ(y[i]-ny));
    }
    // nth_element rearranges so that t[k-1] is the kth smallest element
    nth_element(t.begin(), t.begin() + k - 1, t.end());
    return t[k-1];
}


void simulated_annealing () {
    double T = 1200;
    while (T > 1e-16) {
        double nx = ansx + (randprob()*2 - 1) * T;
        double ny = ansy + (randprob()*2 - 1) * T;
        double nt = calT(nx, ny);
        double d = nt - anst;
        if (d < 0) {
            ansx = nx;
            ansy = ny;
            anst = nt;
        } else if (exp(-d/T) > randprob()) {
            ansx = nx;
            ansy = ny;
        }
        T *= down;
    }
}

int main () {
    AC
    cin >> n >> k;
    int sx = 0, sy = 0;
    auto clk = clock();
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> c[i];
        sx += x[i];
        sy += y[i];
    }
    ansx = sx / (double)n;
    ansy = sy / (double)n;
    anst = calT(ansx, ansy);
    while (double (clock() - clk) / CLOCKS_PER_SEC < TL)
        simulated_annealing();
    cout << fixed << setprecision(6) << anst << '\n';
    return 0;
}