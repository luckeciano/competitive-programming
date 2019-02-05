#include <iostream>
#include <vector>
#define MAX_V 1 + 100 + 50000 + 1 + 5
using namespace std;
int s = 0; int t = 50101;
int AdjMat [MAX_V][MAX_V];


void augment(int v, int minEdge) { // traverse BFS spanning tree from s->t
    if (v == s) { f = minEdge; return; } // record minEdge in a global var f
    else if (p[v] != -1) { augment(p[v], min(minEdge, AdjMat[p[v]][v]));
        AdjMat[p[v]][v] -= f;   AdjMat[v][p[v]] += f;
     } }


int main () {
    while (cin >> n, n) {
        cin >> m;

       for (int i = 0; i < n; i++) {
            cin >> v >> a >> b;
            bool aC = false; bool bC = false;
            for (int k = 0; k < in.size(); k++) {
                if (in[k] == a) aC = true;
                if (in[k] == b) bC = true;
            }
            if (!aC) in.push_back(a);
            if (!bC) in.push_back(b);

            //no solution

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
                    pair<int,int> v = AdjList[u][j];
                    if (AdjMat[u][v.first] > 0 && !vis[v.first]) {
                    vis[v.first] = true; q.push(v.first); p[v.first] = u;
                    }
                }
            }
            augment(t, INF);
            if (f == 0) break;
            mf += f;
        }


    }


}
