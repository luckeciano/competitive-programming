#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int T;
    cin >> T;
    int r [105];
    char t [105];
    int cont = 0;
    while (T--) {
        cont ++;
        int N, D;
        cin >> N >> D;
        for (int i = 0; i < N; i++) {
            scanf ("\n");
            scanf ("%c-%d", &t[i], &r[i]);
        }
        int maxDist = 0;
        for (int i = 0; i < N; i++) {
            int k;
            if (i - 1 < 0) k = 0;
            else k = r[i - 1];

            int u;
            if (i + 1 >= N) u = D;
            else u = r[i + 1];

            if (r[i] - k > maxDist)
                maxDist = r[i] - k;
            if (u - r[i] > maxDist)
                maxDist = u - r[i];

            if (t[i] == 'S') {
                if (u - k > maxDist)
                    maxDist = u - k;
            }

        }
        cout << "Case " << cont << ": " << maxDist << endl;
    }





}
