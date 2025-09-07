#pragma GCC optimize("Ofast")
#include <iostream>
#include <vector>
#define fastio cin.tie(0)->sync_with_stdio(false)
#define SZ(x) ((int) x.size())

using namespace std;
typedef long long int lli;

vector<vector<lli>> transfering_matrix = 
        {{2, 0, 3, 0, 0},
         {0, 0, 0, 0, 4},
         {0, 1, 1, 0, 0},
         {0, 0, 0, 2, 2},
         {0, 0, 0, 1, 1}};

vector<vector<lli>> dp_matrix_initiator = {{0}, {0}, {0}, {0}, {0}};

const int mod = 1e9 + 7;

vector<vector<lli>> matrices_multiply(vector<vector<lli>> &A, vector<vector<lli>> &B) {
    if (SZ(A[0]) != SZ(B)) return {};
    vector<vector<lli>> res(SZ(A), vector<lli> ( SZ(B[0]), 0LL ));
    for (int i = 0; i < SZ(A); i++) {
        for (int j = 0; j < SZ(B[0]); j++) {
            for (int k = 0; k < SZ(A[0]); k++) {
                res[i][j] += A[i][k] * B[k][j];
                if (res[i][j] >= mod) res[i][j] %= mod;
            }
        }
    }
    return res;
}

vector<vector<lli>> matrix_fast_power(vector<vector<lli>> &A, int power) {
    if (SZ(A) != SZ(A[0])) return {};
    vector<vector<lli>> res(SZ(A), vector<lli> ( SZ(A[0]), 0LL ));
    for (int i = 0; i < SZ(A); i++) res[i][i] = 1;
    while (power > 0) {
        if (power & 1) res = matrices_multiply(res, A);
        power >>= 1;
        A = matrices_multiply(A, A);
    }
    return res;
}

void solve() {
    int n; cin >> n;
    int a, b, c;
    cin >> a >> b >> c;
    vector<vector<lli>> dp_matrix = dp_matrix_initiator;
    dp_matrix[0][0] = a;
    dp_matrix[1][0] = b;
    dp_matrix[3][0] = c;
    vector<vector<lli>> transfer = matrix_fast_power(transfering_matrix, n);
    dp_matrix = matrices_multiply(transfer, dp_matrix);
    cout << (dp_matrix[0][0]) % mod << ' '
         << (dp_matrix[1][0] + dp_matrix[2][0]) % mod << ' '
         << (dp_matrix[3][0] + dp_matrix[4][0]) % mod << '\n';
}

int main() {
    fastio;
    solve();
    return 0;
}