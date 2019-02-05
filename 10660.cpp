#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main() {
    int city[5][5];
    int t;
    cin >> t;
    while (t--) {
        for (int i = 0; i < 5; i++)
            for (int j = 0; j < 5; j++)
                city[i][j] = 0;
        int n;
        cin >> n;
        for (int i = 0; i < n; i++) {
            int r, c, s;
            cin >> r >> c >> s;
            city[r][c] = s;
        }

        int minDist = 9999999;
        int sol[5];
        for (int a = 0; a < 21; a++)
            for (int b = a + 1; b < 22; b++)
                for (int c = b + 1; c < 23; c++)
                    for (int d = c + 1; d < 24; d++)
                        for (int e = d + 1; e < 25; e++) {
                            int distTotal = 0;
                            for (int i = 0; i < 5; i++) {
                                for (int j = 0; j < 5; j++) {
                                    int distA = city[i][j]*(abs(a/5 - i) + abs(a%5 - j));
                                    int distB = city[i][j]*(abs(b/5 - i) + abs(b%5 - j));
                                    int distC = city[i][j]*(abs(c/5 - i) + abs(c%5 - j));
                                    int distD = city[i][j]*(abs(d/5 - i) + abs(d%5 - j));
                                    int distE = city[i][j]*(abs(e/5 - i) + abs(e%5 - j));
                                    distTotal += min(min(min(min(distA, distB), distC), distD), distE);
                                }
                            }
                            if (distTotal < minDist) {
                                minDist = distTotal;
                                sol[0] = a; sol[1] = b; sol[2] = c; sol[3] = d; sol[4] = e;
                            }
                        }

        printf ("%d %d %d %d %d\n", sol[0], sol[1], sol[2], sol[3], sol[4]);






    }



}
