#include <iostream>
#include <vector>
#include <queue>
#include <bitset>
#define INF 1000000
#define MAX_V 38
using namespace std;

int s = 36; int t = 37; int f, mf;
vector<int> p;
int AdjMat[40][40];
vector<vector<pair<int,int> > > AdjList;
void augment(int v, int minEdge) { // traverse BFS spanning tree from s->t
    if (v == s) { f = minEdge; return; } // record minEdge in a global var f
    else if (p[v] != -1) { augment(p[v], min(minEdge, AdjMat[p[v]][v]));
        AdjMat[p[v]][v] -= f;   AdjMat[v][p[v]] += f;
     } }

int main() {
    string aux;
    while (getline(cin, aux)) {
        if (aux.size() == 0) break;
        int users = 0;
        AdjList.clear();
        AdjList.resize(MAX_V);
        for (int i = 0; i < 38; i++)
            for (int j = 0; j < 38; j++)
                AdjMat[i][j] = 0;
        do {
            AdjList[s].push_back(make_pair(aux[0] - 'A', aux[1] - '0'));
            AdjList[aux[0] - 'A'].push_back(make_pair(s, aux[1] - '0'));
            AdjMat[s][aux[0] - 'A'] = aux[1] - '0';
            users += aux[1] - '0';
            for (int i = 3; aux[i] != ';'; i++) {
                AdjList[26 + aux[i] - '0'].push_back(make_pair(t, 1));
                AdjList[t].push_back(make_pair(26 + aux[i] - '0', 1));
                AdjMat[26 + aux[i] - '0'][t] = 1;

                AdjList[aux[0] - 'A'].push_back(make_pair(26 + aux[i] - '0', INF));
                AdjList[26 + aux[i] - '0'].push_back(make_pair(aux[0] - 'A', INF));
                AdjMat[aux[0] - 'A'][26 + aux[i] - '0'] = INF;
            }
        } while (getline(cin, aux), aux.size() != 0);


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
        //cout << users << "~" << mf << endl;
        if (mf != users) cout << "!" << endl;
        else {
            for (int i = 26; i < 36; i++) {
                bool exists = false;
                for (int j = 0; j < 26; j++) {
                    if (AdjMat[i][j]  == 1) {
                        cout << char(j + 'A');
                        exists = true;
                    }
                }
                if (!exists) cout << "_";
            }
            cout << endl;
        }



    }


}
