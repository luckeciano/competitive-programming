#include <iostream>
#include <vector>
#include <bitset>
#include <queue>
using namespace std;
#define MAX_V 1805
#define INF 10000000
int AdjMat[2000][2000];
int s = 1800; int t = 1801;
int mf, f;
vector<int> p;

void augment(int v, int minEdge) { // traverse BFS spanning tree from s->t
    if (v == s) { f = minEdge; return; } // record minEdge in a global var f
    else if (p[v] != -1) { augment(p[v], min(minEdge, AdjMat[p[v]][v]));
        AdjMat[p[v]][v] -= f;   AdjMat[v][p[v]] += f;
     } }


int X, Y, P;
char grid[35][35];

int main() {

    vector<vector<int> > AdjList;
    while (cin >> X >> Y >> P) {
        AdjList.clear();
        AdjList.resize(1802);
        for (int i = 0; i < X; i++) {
            for (int j = 0; j < Y; j++) {
                cin >> grid[i][j];
                AdjMat[s][i*Y + j] = 0;
                AdjMat[i*Y + j][s] = 0;
                AdjMat[t][i*Y + j] = 0;
                AdjMat[i*Y + j][t] = 0;

            }
        }

       for (int i = 0; i < 1802; i++)
        for (int j = 0; j < 1802; j++)
            AdjMat[i][j] = 0;

        for (int i = 0; i < X; i++) {
            for (int j = 0; j < Y; j++) {
                if (grid[i][j] == '~') continue;
                if (i - 1 >= 0 && grid[i - 1][j] != '~'){
                    AdjMat[900 + (i-1)*Y + j][i*Y + j] = 1000;
                    AdjList[900 + (i-1)*Y + j].push_back(i*Y + j);
                     AdjList[i*Y + j].push_back(900 + (i-1)*Y + j);
                }
                if (i + 1 < X && grid[i + 1][j] != '~') {
                    AdjMat[900 + (i+1)*Y + j][i*Y + j] = 1000;
                    AdjList[900 + (i+1)*Y + j].push_back(i*Y + j);
                    AdjList[i*Y + j].push_back(900 + (i+1)*Y + j);
                }
                if (j - 1 >= 0 && grid[i][j - 1] != '~'){
                    AdjMat[900 + (i)*Y + j - 1][i*Y + j] = 1000;
                    AdjList[900 + (i)*Y + j - 1].push_back(i*Y + j);
                    AdjList[i*Y + j].push_back(900 + (i)*Y + j - 1);
                }
                if (j + 1 < Y && grid[i][j + 1] != '~'){
                    AdjMat[900 + (i)*Y + j + 1][i*Y + j] = 1000;
                    AdjList[900 + (i)*Y + j + 1].push_back(i*Y + j);
                    AdjList[i*Y + j].push_back(900 + (i)*Y + j + 1);
                }


            }
        }
        for (int i = 0; i < X; i++) {
            for (int j = 0; j < Y; j++) {
                if (grid[i][j] == '~') continue;

                if (grid[i][j] == '*') {
                    AdjList[s].push_back(i*Y + j);
                    AdjList[i*Y + j].push_back(s);
                    AdjMat[s][i*Y + j] = 1;
                }
                if (grid[i][j] == '#') {
                    AdjList[t].push_back(2*(i*Y + j));
                    AdjList[900 + (i*Y + j)].push_back(t);
                    AdjMat[900 + (i*Y + j)][t] = P;
                }

                if (grid[i][j] == '#' || grid[i][j] == '@') {
                    AdjMat[i*Y + j][900 + (i*Y + j)] = 1000;
                    AdjList[i * Y + j].push_back(900 + (i*Y + j));
                    AdjList[900 + (i*Y + j)].push_back(i * Y + j);
                }

                if (grid[i][j] == '.' || grid[i][j] == '*') {
                    AdjMat[i*Y + j][900 + (i*Y + j)] = 1;
                    AdjList[i * Y + j].push_back(900 + (i*Y + j));
                     AdjList[900 + (i*Y + j)].push_back(i * Y + j);
                }

            }
        }/*
        for (int iR = 0; iR < X; iR++) {
            for (int iC = 0; iC < Y; iC++) {
                for (int fR = 0; fR < X; fR++) {
                    for (int fC = 0; fC < Y; fC++)
                        cout << AdjMat[iR*Y + iC][fR*Y + fC] << " ";
                }
                cout << endl;
            }
        }*/

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
    }




}
