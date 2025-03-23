#include <bits/stdc++.h>
using namespace std;

int nxt[6000010][2];
int main () {
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    // 假設有n個字串要放上Trie, 0是根節點
	for (int i = 0; i < 6e6; i++) {
	    nxt[i][0] = -1;
	    nxt[i][1] = -1;
	}

    int node=0;
    // 插入n個字串到Trie中
    for(int i=0; i<m; i++){
        string s;
        cin>>s;
        int now = 0;
        for(int j = n - 1; j > -1; j--) {
            int c = 0;
            if (s[j] == 'p')
                c = 1;
            if(nxt[now][c]==-1) {
                nxt[now][c]=++node; // 如果轉移節點不存在，創建新節點
            }
            now = nxt[now][c]; // 移動到下一節點
        }
    }

    for (int i = 0; i < k; i++) {
        string s;
        cin >> s;
        int now = 0;
        unsigned long long sum = 0;
        for (int j = n - 1; j > -1; j--) {
            int c = 0;
            if (s[j] == 'm')
                c = 1;
            bool x = 1;
            if (nxt[now][c] == -1) {
                c = 1 - c;
                x = 0;
            }
            if (x)
                sum += (1LL << j);
            now = nxt[now][c];
        }
        cout << sum << endl;
    }

    return 0;
}