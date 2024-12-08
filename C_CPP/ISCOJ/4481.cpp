// TLE

#include <bits/stdc++.h>
using namespace std;

int main () {
	int n, m, k;
	scanf("%d %d %d", &n, &m, &k);
	unsigned long long monsters[m];
	// unsigned long long *monsters = new unsigned long long [m];
	memset(monsters, 0, sizeof(monsters[0]) * m);
	char a;
	for (int i = 0; i < m; i++) {
		scanf("\n");
		for (int j = 0; j < n; j++) {
			scanf("%c", &a);
			if (a == 'p')
				monsters[i] += (1 << j);
		}
	}
	for (int i = 0; i < k; i++) {
		unsigned long long max_dmg;
		unsigned long long spell = 0;
		scanf("\n");
		for (int i = 0; i < n; i++) {
			scanf("%c", &a);
			if (a == 'p')
				spell += (1 << i);
		}
		for (int j = 0; j < m; j++) {
			if ((spell ^ monsters[j]) > max_dmg)
				max_dmg = spell ^ monsters[j];
		}
		printf("%llu \n", max_dmg);
	}
	// delete [] monsters;
	return 0;
}