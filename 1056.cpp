#include <iostream>
#include <map>
#define INF 10000000

using namespace std;
int P, R;
string A, B;
int main() {
    int AdjMat[55][55];
    int cont = 0;
    map <string, int> verts;
    while (cin >> P >> R, P || R){
        verts.clear();
        cont++;
        int v = 0;
        for (int i = 0; i < P; i++) {
            for (int j = 0; j < P; j++) {
                AdjMat[i][j] = INF;
                if (j == i) AdjMat[i][j] = 0;
            }
        }
        for (int i = 0; i < R; i++) {
            cin >> A >> B;
            if (verts.find(A) == verts.end()) {
                verts[A] = v;
                v++;
            }
            if (verts.find(B) == verts.end()) {
                verts[B] = v;
                v++;
            }

            AdjMat[verts[A]][verts[B]] = 1;
            AdjMat[verts[B]][verts[A]] = 1;

        }



        for (int k = 0; k < P; k++) // remember that loop order is k->i->j
            for (int i = 0; i < P; i++)
                for (int j = 0; j < P; j++)
                    AdjMat[i][j] = min(AdjMat[i][j], AdjMat[i][k] + AdjMat[k][j]);
        int ans = -1;
        for (int i = 0; i < P; i++) {
            for (int j = 0; j < P; j++) {
                ans = max (ans, AdjMat[i][j]);
            }
        }
        cout << "Network " << cont << ": ";
        if (ans == INF) cout << "DISCONNECTED" << endl;
        else cout << ans << endl;

        cout << endl;
    }


}
