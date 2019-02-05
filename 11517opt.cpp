#include <iostream>
#include <cstring>
#include <cmath>
#include <cstdio>

using namespace std;
#define INF 1000000

int dp [30001];
int coinValue[105];

int V, N;
int main() {
   // ofstream myf;
    //myf.open ("lulu.txt");
    int TC;
    cin >> TC;
    while (TC--) {
        cin >> V;
        cin >> N;
        memset(dp, INF, sizeof dp);
        dp[0] = 0;
        for (int i = 0; i < N; i++) {
            scanf ("%d", &coinValue[i]);
        }
        for (int i = 0; i < N; i++) {
            for (int v = 30001 - coinValue[i] - 1; v >=0; v--) {
                if (dp[v] < INF)
                    dp[v + coinValue[i]] = min (dp[v + coinValue[i]], dp[v] + 1);
            }
        }

        int minValue = 100000; int minCoin = 100000;
        for (int i = V; i < 30001; i++) {
            if (dp[i] < INF) {
                minValue = i;
                minCoin = dp[i];
                break;
            }
        }
        printf ("%d %d\n", minValue, minCoin);
        //myf << val << " " << coins << endl;
    }





}

