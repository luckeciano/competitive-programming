#include <iostream>
#include <vector>
#include <queue>
#include <bitset>
#define INF 10000000
#include <fstream>
#define MAX_V 115
using namespace std;
int s = 1; int t; int M, W;
int a, b, c;
vector<vector<int> > AdjList;
int AdjMat [115][115];
int f, mf;
vector<int> p;

void augment(int v, int minEdge) { // traverse BFS spanning tree from s->t
    if (v == s) { f = minEdge; return; } // record minEdge in a global var f
    else if (p[v] != -1) { augment(p[v], min(minEdge, AdjMat[p[v]][v]));
        AdjMat[p[v]][v] -= f;   AdjMat[v][p[v]] += f;
     } }

int main() {
  //  ofstream myf ("11506.txt");
    while (cin >> M >> W , M || W) {
        s = 0; t = M - 1;
        AdjList.clear();
        AdjList.resize(102);
        for (int i = 0; i < 110; i++) {
            for (int j = 0; j < 110; j++)
                AdjMat [i][j] = 0;

        }

        AdjMat[s][50 + s] = INF;
        AdjList[s].push_back(50 + s);
        AdjList[50 + s].push_back(s);
        AdjMat[t][50 + t] = INF;
        AdjList[t].push_back(50 + t);
        AdjList[50 + t].push_back(t);
        for (int i = 0; i < M - 2; i++) {
            cin >> a >> b;
            AdjMat[a - 1][50 + a - 1] = b;
            AdjList[a - 1].push_back(50 + a - 1);
            AdjList[50 + a - 1].push_back(a - 1);

        }
        for (int i = 0; i < W; i++) {
            cin >> a >> b >> c;
            AdjMat[50 + a - 1][b - 1] = c;
            AdjList[50 + a - 1].push_back(b-1);
            AdjList[b - 1].push_back(50 + a - 1);

            AdjMat[50 + b - 1][a - 1] = c;
            AdjList[50 + b - 1].push_back(a - 1);
            AdjList[a  - 1].push_back(50 + b - 1);
        }

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
        cout << mf << endl;
       // myf << mf << endl;
    }



}
