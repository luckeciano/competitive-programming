#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;
vector<int> dfs_low, dfs_num, dfs_parent, articulation_vertex;
int dfsNumberCounter, dfsRoot, rootChildren;
vector<vector<int> > AdjList;
int N; int aux;
void articulationPointAndBridge(int u) {
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++; // dfs_low[u] <= dfs_num[u]
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
        int v = AdjList[u][j];
        if (dfs_num[v] == -1) { // a tree edge
            dfs_parent[v] = u;
            if (u == dfsRoot) rootChildren++; // special case if u is a root

            articulationPointAndBridge(v);

            if (dfs_low[v] >= dfs_num[u]) // for articulation point
                articulation_vertex[u] = true; // store this information first
            //if (dfs_low[v] > dfs_num[u]) // for bridge
             //   printf(" Edge (%d, %d) is a bridge\n", u, v.first);
            dfs_low[u] = min(dfs_low[u], dfs_low[v]); // update dfs_low[u]
        }
        else if (v != dfs_parent[u]) // a back edge and not direct cycle
            dfs_low[u] = min(dfs_low[u], dfs_num[v]); // update dfs_low[u]
    }
}

int main() {
    while (cin >> N, N) {
        scanf ("\n");
        AdjList.clear();
        AdjList.resize(N);
        while ((cin >> aux), aux != 0) {
            int startVertex = aux;
            while (cin.peek() != '\n') {
                int endVertex; cin >> endVertex;
                AdjList[startVertex - 1].push_back(endVertex - 1);
                AdjList[endVertex - 1].push_back(startVertex - 1);

            }
        }
        int articP = 0;


        dfsNumberCounter = 0; dfs_num.assign(N, -1); dfs_low.assign(N, 0);
        dfs_parent.assign(N, 0); articulation_vertex.assign(N, 0);
        for (int i = 0; i < N; i++) {
            if (dfs_num[i] == -1) {
                dfsRoot = i; rootChildren = 0; articulationPointAndBridge(i);
                articulation_vertex[dfsRoot] = (rootChildren > 1); } // special case
        }
        for (int i = 0; i < N; i++)
            if (articulation_vertex[i])
                articP++;

        cout << articP << endl;
    }



}
