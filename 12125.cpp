#include <iostream>
#include <vector>
#include <queue>
#include <bitset>
#define MAX_V 203
#define INF 100000
using namespace std;

int f, mf;
vector<int> p;
int AdjMat[205][205], aux[205][205];
int s = 200;
void augment(int v, int minEdge) { // traverse BFS spanning tree from s->t
    if (v == s) { f = minEdge; return; } // record minEdge in a global var f
    else if (p[v] != -1) { augment(p[v], min(minEdge, AdjMat[p[v]][v]));
        AdjMat[p[v]][v] -= f;   AdjMat[v][p[v]] += f;
     } }

int N; float D;
vector<vector<int> > AdjList;
int main () {
    int TC;
    cin >> TC;
    int x[105], y[105], n[105], m[105];
    while (TC--) {
        int totalP  = 0;
        AdjList.clear();
        AdjList.resize(202);
        for (int i = 0; i < 205; i++)
            for (int j = 0; j < 205; j++)
                AdjMat[i][j] = 0;
        cin >> N >> D;
        for (int i = 0 ; i < N; i++) {
            cin >> x[i] >> y[i] >> n[i] >> m[i];
            totalP += n[i];

            AdjMat[s][i] = n[i];
            AdjList[s].push_back(i);
            AdjList[i].push_back(s);

            AdjMat[i][100 + i] = m[i];
            AdjList[i].push_back(100 + i);
            AdjList[100 + i].push_back(i);
        }
        for (int i =0 ; i < N; i++) {
            for (int j = i + 1; j < N; j++) {
                if ((x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]) <= D * D) {
                        AdjMat[100 + i][j] = INF;
                        AdjList[100 + i].push_back(j);
                        AdjList[j].push_back(100 + i);
                        AdjMat[100 + j][i] = INF;
                        AdjList[100 + j].push_back(i);
                        AdjList[i].push_back(100 + j);
                }
            }
        }
       /* for (int i = 0; i < N; i++) {
            cout << AdjMat[i][t] << " ";
        }
        cout << endl;*/
       for (int i = 0; i < 203; i++)
            for (int j = 0; j < 203; j++)
                aux[i][j] = AdjMat[i][j];

        vector<int> res;
        for (int t = 0; t < N; t++) {

            //AdjMat[K][t] = INF;
            //AdjList[K].push_back(t);
            //AdjList[t].push_back(K);
            mf = 0;
             while (1) { // now a true O(VE^2) Edmonds Karp’s algorithm
                f = 0;
                bitset<MAX_V> vis; vis[s] = true; // we change vi dist to bitset!
                queue<int> q; q.push(s);
                p.assign(MAX_V, -1);
                while (!q.empty()) {
                    int u = q.front(); q.pop();
                    if (u == t) break;
                    for (int j = 0; j < (int)AdjList[u].size(); j++) { // AdjList here!
                        int v = AdjList[u][j];
                        if (AdjMat[u][v] > 0 && !vis[v]) {
                        vis[v] = true; q.push(v); p[v] = u;
                        }
                    }
                }
                augment(t, INF);
                if (f == 0) break;
                mf += f;
            }
            if (mf == totalP) res.push_back(t);
            for (int i = 0; i < 203; i++)
                for (int j = 0; j < 203; j++)
                    AdjMat[i][j] = aux[i][j];

        }
        if (res.size() == 0) cout << -1 << endl;
        else {
            for (int k = 0; k < res.size(); k++) {
                if (k) cout << " ";
                cout << res[k];
            }
            cout << endl;
        }



    }

}
