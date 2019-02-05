#include <iostream>
#include <cstdio>
#include <cstring>


using namespace std;


long long  memo[55][55];
int n, k, m;

long long ways (int N, int K) {
    if (K == 0 && N == 0) return 1;
    if (N < 0 || K < 0) return 0;

    if (memo[N][K] != -1) return memo[N][K];

    long long ans = 0;

    for (int i = 1; i <= m; i++) {
        ans += ways (N - i, K - 1);
    }

    return memo[N][K] = ans;
}


int main() {

    while (cin >> n >> k >> m) {
        memset (memo, -1LL, sizeof memo);
        printf ("%lld\n", ways(n, k));
        //cout << ways (n, k) << endl;
    }


}
