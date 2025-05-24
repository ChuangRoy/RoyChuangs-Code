#pragma GCC optimize("Ofast")
#include <iostream>
#include <utility>
#include <cmath>
#include <vector>
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
    return fabs(a) < eps ? 0 : a > 0 ? 1 : -1;
}

int ori(pt a, pt b, pt c) {
    return sign((b - a).cross(c - a));
}

bool collinearity(pt p1, pt p2, pt p3) {
    return sign((p1 - p3).cross(p2 - p3)) == 0;
}

bool between(pt p1, pt p2, pt p3) { // check if p3 on seg (p1, p2)
    if (!collinearity(p1, p2, p3)) { return 0; }
    else { return sign((p1 - p3).dot(p2 - p3)) <= 0; }
}

bool intersect(pt p1, pt p2, pt p3, pt p4) {
    int a123 = ori(p1, p2, p3);
    int a124 = ori(p1, p2, p4);
    int a341 = ori(p3, p4, p1);
    int a342 = ori(p3, p4, p2);
    if (between(p1, p2, p3) || between(p1, p2, p4)
        || between(p3, p4 ,p1) || between(p3, p4, p2)) {
        return true;
    }
    else {
        return a123 * a124 < 0 && a341 * a342 < 0;
    }
}

void solve () {
    vector<pt> p(4, pt(0, 0));
    for (int i = 0; i < 4; i++) cin >> p[i].x >> p[i].y;
    if (intersect(p[0], p[1], p[2], p[3]))
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main () {
    AC
    int T; cin >> T;
    while (T--)
        solve();
    return 0;
}