#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 10000000
#define MAX_N 25
using namespace std;



int main() {
    int TC; cin >> TC;
    int n, m, a, b;
    vector<pair<int, int> > EdgeList;
    int AdjMat[700][700];
    int cont = 0;
    while (TC--) {
        cont++;
        cin >> n >> m;
        for (int i = 0; i < n + m; i++) {
            for (int j = 0; j < n + m; j++) {
                if (i == j) AdjMat[i][j] = 0;
                else AdjMat[i][j] = INF;

            }
        }


        for (int i =0; i < m; i++) {
            cin >> a >> b;
           // EdgeList.push_back(make_pair(a,b));
            AdjMat[a][n + i] = 1;
            AdjMat[n + i][a] = 1;
            AdjMat[b] [n + i] = 1;
            AdjMat[n + i][b] = 1;
           // AdjMat[2*b][2*a] = 1;
        }

        for (int k = 0; k < n + m; k++) // remember that loop order is k->i->j
            for (int i = 0; i < n + m; i++)
                for (int j = 0; j < n + m; j++)
                    AdjMat[i][j] = min(AdjMat[i][j], AdjMat[i][k] + AdjMat[k][j]);
       int maxDist = INF;
       for (int i = 0; i < n + m; i++) {
            int first = 0; int second = 0;
            for (int j = 0; j < n; j++) {
                if (AdjMat[i][j] >= first) {
                    second = first;
                    first = AdjMat[i][j];
                } else if (AdjMat[i][j] > second) second = AdjMat[i][j];
            }
            maxDist = min (maxDist, first + second);
       }



       /* int minMax = INF;
        int maxThisNode;
        for (int i = 0; i < n; i++) {
            maxThisNode = 0;
            for (int j = 0; j < n; j++){
                maxThisNode = max (maxThisNode, AdjMat[i][j]);
            }
            if (maxThisNode < minMax)
                minMax = maxThisNode;
        }
        minMax *= 2;
        int minMaxEdge = INF;
        for (int k = 0; k < n; k++) {
            maxThisNode = 0;
            for (int i = 0; i < EdgeList.size(); i++) {
                pair<int, int> edge;
                maxThisNode = max (maxThisNode, (AdjMat[edge.first][k] + AdjMat[edge.second][k]));
            }
            if (maxThisNode < minMaxEdge)
                minMaxEdge = maxThisNode;
        }
        int maxDist;
        maxDist = min (minMax, minMaxEdge);*/

        cout << "Case #" << cont << ":" << endl;
        cout << maxDist/2 << endl;
        cout << endl;

    }
}
