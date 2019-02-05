#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <map>
using namespace std;

map<string, int> order;
vector<string> rOrder;
vector<int> dfs_num, dfs_low, S, visited;
vector<vector<int> > AdjList;
int dfsNumberCounter, numSCC;
int N, M; string a, b;
void tarjanSCC(int u) {
    dfs_low[u] = dfs_num[u] = dfsNumberCounter++; // dfs_low[u] <= dfs_num[u]
    S.push_back(u); // stores u in a vector based on order of visitation
    visited[u] = 1;
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
        int v = AdjList[u][j];
        if (dfs_num[v] == -1)
        tarjanSCC(v);
        if (visited[v]) // condition for update
        dfs_low[u] = min(dfs_low[u], dfs_low[v]);
    }
    if (dfs_low[u] == dfs_num[u]) { // if this is a root (start) of an SCC
        //printf("SCC %d:", ++numSCC); // this part is done after recursion
        bool first = true;
        while (1) {
            int k = S.back(); S.pop_back(); visited[k] = 0;
            if (first) first = false;
            else cout << ", ";
            cout << rOrder[k];
            if (u == k) break;
        }
        printf("\n");
    }
}

int main() {
    int cont = 0;
    while (cin >> N >> M, N || M) {
        if (cont != 0) cout << endl;
        cont++;
        AdjList.clear();
        AdjList.resize(N);
        order.clear();
        rOrder.clear();
        for (int i = 0; i < M; i++) {
            cin >> a >> b;
            if (order.find(a) == order.end()) {
                rOrder.push_back(a);
                order[a] = rOrder.size() - 1;
            }
            if (order.find(b) == order.end()) {
                rOrder.push_back(b);
                order[b] = rOrder.size() - 1;
            }
            bool put = true;
            for (int k = 0; k < (int) AdjList[order[a]].size() && put; k++) {
                if (AdjList[order[a]][k] == order[b])
                    put = false;
            }
            if (put) AdjList[order[a]].push_back(order[b]);

        }
        cout << "Calling circles for data set " << cont << ":" << endl;
        dfs_num.assign(N, -1); dfs_low.assign(N, 0); visited.assign(N, 0);
        dfsNumberCounter = numSCC = 0;
        for (int i = 0; i < N; i++)
            if (dfs_num[i] == -1)
                tarjanSCC(i);
    }


}
