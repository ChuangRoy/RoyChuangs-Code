#pragma GCC optimize("Ofast")
#include <iostream>
#include <utility>
#include <cmath>
#define AC cin.tie(0)->sync_with_stdio(false);
#define pb emplace_back
#define ALL(x) begin(x),end(x)
#define MP(x, y) make_pair((x), (y))
#define SQ(x) ((x)*(x))
#define SZ(x) ((int) x.size())
#define err(x) cerr << #x << ": " << x << endl;
#define eps 1e-12

using namespace std;
typedef long long ll;
typedef long long pt_type;

struct pt{
    pt_type x, y;

    pt(pt_type a, pt_type b) : x(a), y(b) { ;}

    pt operator+ (pt pt1){
        return pt(x + pt1.x, y + pt1.y);
    }

    pt operator- (pt pt1){
        return pt(x - pt1.x, y - pt1.y);
    }

    pt_type dot (pt pt1){
        return x * pt1.x + y * pt1.y;
    }

    pt_type cross (pt pt1){
        return x * pt1.y - y * pt1.x;
    }

    pt operator* (pt_type db){
        return pt(x * db, y * db);
    }

    bool operator== (pt pt1){
        return (x == pt1.x) && (y == pt1.y);
    }

    pt_type abs_square(){
        return x * x + y * y;
    }

    double abs(){
        return sqrt(x * x + y * y);
    }
};

int sign(pt_type a) {
    return a == 0? 0 : a > 0 ? 1 : -1;
}

int ori(pt a, pt b, pt c) {
    return sign((b - a).cross(c - a));
}

void solve () {
    pt p1(0, 0), p2(0, 0), p3(0, 0);
    cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y;
    int o = ori(p1, p2, p3);
    if (o > 0) {
        cout << "LEFT\n";
    } else if (o < 0) {
        cout << "RIGHT\n";
    } else {
        cout << "TOUCH\n";
    }
}

int main () {
    AC
    int T; cin >> T;
    while (T--)
        solve();
    return 0;
}