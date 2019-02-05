#include <iostream>
#include <set>
#include <iomanip>
#define INF 10000000
using namespace std;
int a, b;
int main() {
    int cont = 0;
    set<int> vertices;
    int AdjMat[105][105];
    while (cin >> a >> b, a || b) {
        vertices.clear();
        cont++;
        for (int i = 0; i < 100; i++)
            for (int j = 0; j < 100; j++ )
                AdjMat[i][j] = INF;
        AdjMat[a-1][b-1] = 1;
        if (vertices.find(a - 1) == vertices.end())
            vertices.insert(a-1);

        if (vertices.find(b - 1) == vertices.end())
            vertices.insert(b-1);

        while (cin >> a >> b, a || b) {
            AdjMat[a-1][b-1] = 1;

            if (vertices.find(a - 1) == vertices.end())
                vertices.insert(a-1);

            if (vertices.find(b - 1) == vertices.end())
                vertices.insert(b-1);

        }

        for (int k = 0; k < 100; k++) // remember that loop order is k->i->j
            for (int i = 0; i < 100; i++)
                for (int j = 0; j < 100; j++)
                    AdjMat[i][j] = min(AdjMat[i][j], AdjMat[i][k] + AdjMat[k][j]);

        set<int>::iterator it1, it2;
        int num = 0; int deno = 0;
        for (it1 = vertices.begin(); it1 != vertices.end(); it1++) {
            for (it2 = vertices.begin(); it2 != vertices.end(); it2++) {
                if (*it1 != *it2) {
                    deno++;
                    num += AdjMat[*it1][*it2];
                }
            }
        }

        float res = (num * 1.000)/ (deno * 1.000);
        cout << "Case " << cont << ": average length between pages = ";
        cout << fixed << setprecision (3) << res << " clicks" << endl;
    }


}
