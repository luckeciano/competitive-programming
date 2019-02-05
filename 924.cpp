#include <iostream>
#include <vector>
#include <queue>
#define INF 1000000
using namespace std;
int maxBoom, boomDay;
vector<vector<int> > AdjList;
int E, N , e, T, A;
void bfs (int s) {
    vector<int> dist(E, INF); dist[s] = 0; // distance from source s to s is 0
    vector<int> boom (E, 0);
    queue<int> q; q.push(s);
//    vi p; // addition: the predecessor/parent vector
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int j = 0; j < (int)AdjList[u].size(); j++) {
            int v = AdjList[u][j];
            if (dist[v] == INF) {
                boom[dist[u]]++;
                dist[v] = dist[u] + 1;
               // p[v] = u; // addition: the parent of vertex v.first is u
                q.push(v);
            }
        }
    }
    for (int i = 0; i < boom.size(); i++) {
        if (maxBoom < boom[i]) {
            maxBoom = boom[i];
            boomDay = i;
        }
    }

}

int main () {
    cin >> E;
    AdjList.clear();
    AdjList.resize(E);
    for (int i = 0; i < E; i++) {
        cin >> N;
        for (int j = 0; j < N; j++) {
            cin >> e;
            AdjList[i].push_back(e);
        }
    }

    cin >> T;
    for (int i = 0; i < T; i++) {
        cin >> A;
        maxBoom = 0; boomDay = 0;
        bfs(A);
        if (maxBoom != 0)
            cout << maxBoom << " " << boomDay + 1 << endl;
        else cout << 0 << endl;
    }


}

