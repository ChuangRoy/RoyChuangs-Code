/*
# Description
給定一個字串 s
找出滿足 s_i ∼ s_j 是 2024的倍數的區間 [i,j] (1≤i≤j≤|s|) 總數

# Input
第一行包含一個正整數 T (1≤T≤10^3) 表示測資數量
接下來有 T 筆測資，對於每筆測資：包含一個字串 s (1≤|s|≤10^6)
保證所有測資的 |s| 之和不超過 10^6

# Output
對於每筆測資，輸出一個整數：滿足 s_i ∼ s_j 是 2024的倍數的區間 [i,j] 的總數

# Example
## Input
2
6881688162744
1984
## Output
3
0
## Note
對於第一筆測資，有三組 (i,j) 為 (1,5)、(5,9)、(9,13)滿足條件，分別為 68816、68816、62744
*/

#include <bits/stdc++.h>
using namespace std;

int rec[1000000];
int remain[2024];

int main () {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        long long cnt = 0;
        for (int i = 0; i < 2024; i++) remain[i] = 0;
        int k = s.length() - 1;
        rec[0] = s[k] - '0';
        remain[rec[0]]++;
        if (rec[0] == 0) cnt++;
        int times = 1;
        for (int i = 1; i <= k; i++) {
            int input = s[k-i] - '0';
            times = times * 10 % 2024;
            rec[i] = (long long) (rec[i-1] + times * input) % 2024;
            remain[rec[i]]++;
            if (rec[i] == 0) cnt += remain[0];
            else if (remain[rec[i]] >= 2) cnt += (remain[rec[i]] - 1);
        }
        cout << cnt << endl;
    }
    return 0;
}