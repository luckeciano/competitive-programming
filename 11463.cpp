#include <iostream>
#define INF 10000000
using namespace std;

int N, R, a, b;
int AdjMat [105][105];
int main() {
    int TC; cin >> TC;
    int cont = 0;
    while (TC--) {
        cont++;
        cin >> N >> R;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                AdjMat[i][j] = INF;
                if (j == i) AdjMat[i][i] = 0;
            }
        }
        for (int i = 0; i < R; i++) {
            cin >> a >> b;
            AdjMat[a][b] = 1;
            AdjMat[b][a] = 1;
        }

        for (int k = 0; k < N; k++) // remember that loop order is k->i->j
            for (int i = 0; i < N; i++)
                for (int j = 0; j < N; j++)
                    AdjMat[i][j] = min(AdjMat[i][j], AdjMat[i][k] + AdjMat[k][j]);

        cin >> a >> b;
        int ans = -1;
        for (int i = 0; i < N; i++) {
            ans = max (ans, AdjMat[a][i] + AdjMat[i][b]);
        }
        cout << "Case " << cont << ": " << ans << endl;
    }


}
