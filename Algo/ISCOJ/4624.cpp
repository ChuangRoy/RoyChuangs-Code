#include <iostream>
using namespace std;

int main() {
    long long N, M;
    char c;
    cin >> N >> c >> M;
    if (c == '+') {
        cout << N + M << endl;
    }
    if (c == '-') {
        cout << N - M << endl;
    }
    return 0;
}