#include <iostream>
#include <vector>
#include <list>
#define MAX_COLOR 55
using namespace std;
typedef pair<int, int> ii;
list<int> cyc; // we need list for fast insertion in the middle
vector<vector<pair<int, int> > > AdjList;
vector<int> visited;
void dfs(int u) {
    visited[u] = true;
    for (int i = 0; i < AdjList[u].size(); i++) {
        int v = AdjList[u][i].first;
        if (!visited[v]) dfs(v);
    }
}
void EulerTour(list<int>::iterator i, int u) {
    for (int j = 0; j < (int)AdjList[u].size(); j++) {
        ii v = AdjList[u][j];
        if (v.second) { // if this edge can still be used/not removed
            AdjList[u][j].second = 0;
            v.second = 0; // make the weight of this edge to be 0 (‘removed’)
            for (int k = 0; k < (int)AdjList[v.first].size(); k++) {
                ii uu = AdjList[v.first][k]; // remove bi-directional edge
                if (uu.first == u && uu.second) {
                    AdjList[v.first][k].second = 0;
                    break;
        } }
    EulerTour(cyc.insert(i, u), v.first);
} } }


int main () {
    int TC; cin >> TC;
    int N, a, b;
    vector<int> quantity;
    int cont = 0;
    while (TC--) {
        cont++;
        cout << "Case #" << cont << endl;
        AdjList.clear();
        quantity.clear();
        cin >> N;
        quantity.assign(MAX_COLOR + 1, 0);
        AdjList.resize(MAX_COLOR);
        int start;
        for (int i = 0; i < N; i++) {
            cin >> a >> b;
            quantity[a - 1]++; quantity[b - 1]++;
            AdjList[a - 1].push_back(make_pair(b - 1, 1));
            AdjList[b - 1].push_back(make_pair(a - 1, 1));
            start = a - 1;
        }
        bool eulerian = true;

        for (int i = 0; i < MAX_COLOR && eulerian; i++) {
            //cout << quantity[i] << " ";
            if (quantity[i] % 2 != 0) eulerian = false;
        }
        visited.assign(MAX_COLOR, 0);
        int connected = 0;
        for (int i = 0; i < MAX_COLOR && eulerian; i++) {
                if (visited[i] == 0 && quantity[i] != 0) {
                    connected++;
                    dfs(i);
                }
                if (connected > 1) eulerian = false;
        }

        if (eulerian) {
            cyc.clear();
            EulerTour(cyc.begin(), start);
            list<int>::iterator it = cyc.begin();
            while (next(it) != cyc.end()) {
                cout << *it + 1 << " " << *next(it) + 1 << endl;
                it = next(it);

            }
            cout << *it + 1 << " " << *cyc.begin() + 1 << endl;

        } else cout << "some beads may be lost" << endl;
        if (TC) cout << endl;

    }


}
