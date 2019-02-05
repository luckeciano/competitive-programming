#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

vector<int> dfs_low, dfs_num, dfs_parent, articulation_vertex;
int dfsNumberCounter, dfsRoot, rootChildren;
vector<vector<int> > AdjList;
int bridge; vector<pair<int, int> > res;
int N; int a, b; int k;

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
            if (dfs_low[v] > dfs_num[u]) { // for bridge
                bridge++;
                if (u > v)
                    res.push_back(make_pair(v, u));
                else res.push_back(make_pair(u, v));
            }
            dfs_low[u] = min(dfs_low[u], dfs_low[v]); // update dfs_low[u]
        }
        else if (v != dfs_parent[u]) // a back edge and not direct cycle
            dfs_low[u] = min(dfs_low[u], dfs_num[v]); // update dfs_low[u]
    }
}

char aux;
int main() {

    while (cin >> N) {
        AdjList.clear();
        AdjList.resize(N);
        for (int i = 0; i < N; i++) {
            cin >> a;
            cin >> aux;
            cin >> k; cin >> aux;
            for (int j = 0; j < k; j++) {
                cin >> b;
                AdjList[a].push_back(b);
            }

        }

        bridge = 0;
        res.clear();
        dfsNumberCounter = 0; dfs_num.assign(N, -1); dfs_low.assign(N, 0);
        dfs_parent.assign(N, 0); articulation_vertex.assign(N, 0);
        for (int i = 0; i < N; i++) {
            if (dfs_num[i] == -1) {
                dfsRoot = i; rootChildren = 0; articulationPointAndBridge(i);
                articulation_vertex[dfsRoot] = (rootChildren > 1); } // special case
        }
        cout << bridge << " critical links" << endl;
        sort(res.begin(), res.end());
        for (int i = 0; i < bridge; i++) {
            cout << res[i].first << " - " << res[i].second << endl;
        }
        cout << endl;


    }


}

