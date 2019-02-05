#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;
int N, M, Q, TOTAL;
int K[20];
long long C[55][55], P[55], memo[60][1 << 13];

long long solve (int pos, int bitmask) {
    if (bitmask == TOTAL) return -C[pos][0];
    if (memo[pos][bitmask] != -1) return memo[pos][bitmask];

    long long ans = -C[pos][0];
    for (int nxt = 0; nxt < Q; nxt++) {
        if (!(bitmask & (1 << nxt))) {
            ans = max (ans, -C[pos][K[nxt]] + P[nxt] + solve(K[nxt], bitmask | (1 << nxt)));
        }
    }

    return  memo[pos][bitmask] = ans;
}


int main() {
	int T, a, b;
	long long c, d;
	scanf("%d", &T);
	while (T--) {
        scanf ("%d%d", &N, &M);
        N++;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                C[i][j] = 1e17;
            }
        }

        for (int i = 0; i < N; i++) C[i][i] = 0;

        for (int i = 0; i < M; i++) {
            scanf("%d %d %lld.%lld", &a, &b, &c, &d), c=(c*100)+d, C[a][b] = C[b][a] = min(c, C[a][b]);
        }

        for (int k = 0; k < N; k++) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    C[i][j] = min (C[i][j], C[i][k] + C[k][j]);
                }
            }
        }

        scanf("%d", &Q);
		TOTAL = (1<<Q)-1;

		for (int i = 0; i < Q; i++)
            scanf("%d %lld.%lld", &a, &c, &d), c=(c*100)+d, K[i] = a, P[i] = c;
        memset(memo, -1, sizeof memo);
        long long ret = solve(0,0);
		if (ret > 0) printf("Daniel can save $%lld.%.2lld\n", ret/100, ret%100);
		else printf("Don't leave the house\n");

	}
}
