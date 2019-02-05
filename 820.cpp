#include <iostream>
#include <vector>
#include <queue>
#include <bitset>
#define MAX_V 105
#define INF 10000000
using namespace std;
int s, t; int f, mf;
vector<int> p;
int n, c, a, b, w;
int AdjMat[105][105];
vector<vector<pair<int,int> > > AdjList;

void augment(int v, int minEdge) { // traverse BFS spanning tree from s->t
    if (v == s) { f = minEdge; return; } // record minEdge in a global var f
    else if (p[v] != -1) { augment(p[v], min(minEdge, AdjMat[p[v]][v]));
        AdjMat[p[v]][v] -= f;   AdjMat[v][p[v]] += f;
     } }


int main() {
    int cont = 0;
    while (cin >> n, n) {
        cont++;
        AdjList.clear();
        AdjList.resize(n);
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                AdjMat[i][j] = 0;
        cin >> s >> t >> c;
        for (int i = 0; i < c; i++) {
            cin >> a >> b >> w;
            AdjList[a-1].push_back(make_pair(b-1, w));
            AdjList[b-1].push_back(make_pair(a - 1, w));
            AdjMat[a - 1][b - 1] += w;
            AdjMat[b - 1][a - 1] += w;
        }

        s--; t--;
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

        cout << "Network " << cont << endl;
        cout << "The bandwidth is " << mf << "." << endl;
        cout << endl;
    }


}
