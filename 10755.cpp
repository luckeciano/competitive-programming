#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <climits>
using namespace std;

int main() {
    long long g [25][25][25];
    long long max2D [25];
    int TC;
    cin >> TC;

    while (TC--) {
        long long mx = INT_MIN;
        int A, B, C;
        cin >> A >> B >> C;
        for (int i = 0; i < A; i++) {
            for (int j = 0; j < B; j++) {
                for (int k = 0; k < C; k++) {
                    cin >> g[i][j][k];
                    mx = max(mx, g[i][j][k]);
                    if (k > 0) g[i][j][k] += g[i][j][k - 1];
                    if (j > 0) g[i][j][k] += g[i][j - 1][k];
                    if (j > 0 && k > 0) g[i][j][k] -= g[i][j - 1][k - 1];
                }
            }
        }
        if (mx < 0) cout << mx << endl;
        else {
            long long maxSubRect = INT_MIN;   // the lowest possible value for this problem
              long long subRect;

                //long long ans = 0; long long sum = 0;

              for (int i = 0; i < B; i++) for (int j = 0; j < C; j++) // start coordinate
              for (int k = i; k < B; k++) for (int l = j; l < C; l++) {    // end coord
                    long long cur = 0 ;
                    for (int t = 0; t < A; t++) {
                          subRect = g[t][k][l];      // sum of all items from (0, 0) to (k, l): O(1)
                          if (i > 0) subRect -= g[t][i - 1][l];                              // O(1)
                          if (j > 0) subRect -= g[t][k][j - 1];                              // O(1)
                          if (i > 0 && j > 0) subRect += g[t][i - 1][j - 1];                 // O(1)
                          cur = max (0LL, cur + subRect);
                          maxSubRect = max(maxSubRect, cur);
                          //maxSubRect = max(maxSubRect, subRect);
                          //if (subRect < 0) subRect = 0;
                    }
              }


                      // the answer is here

           cout << maxSubRect << endl;
        }
       if (TC) cout << endl;




    }


}
