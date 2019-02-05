#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cstdio>
#include <queue>
using namespace std;
vector<vector<int> > AdjList;
map<int, string> rOrder;
map<string, int> order;

int shortestPath(int a, int b) {
    vector<int> dist(AdjList.size(), 10000000);
    dist[a] = 0;
    queue<int> q; q.push(a);
    while (!q.empty() && q.front() != b) {
        int u = q.front(); q.pop();
        for (int j = 0; j < (int)AdjList[u].size(); j++) {
            int v = AdjList[u][j];
            if (dist[v] == 10000000) {
                dist[v] = dist[u] + 1;
                q.push(v);
        } } }
    return dist[b];
}

int main() {
    int TC; cin >> TC;
    while (TC --) {
        AdjList.clear();
        order.clear();
        rOrder.clear();
        int number = 0;
        string aux = "";
        while (cin >> aux, aux != "*") {
            vector<int> x;
            AdjList.push_back(x);
            order[aux] = number;
            rOrder[number] = aux;
            number++;
        }
        for (int i = 0; i < AdjList.size(); i++) {
            for (int j = i + 1; j < AdjList.size(); j++) {
                if (rOrder[i].size() == rOrder[j].size()) {
                    int dif = 0;
                    for (int k = 0; k < rOrder[i].size(); k++) {
                        if (rOrder[i][k] != rOrder[j][k])
                            dif++;
                    }
                    if (dif == 1) {
                        AdjList[i].push_back(j);
                        AdjList[j].push_back(i);
                    }
                }
            }
        }
        string auxS = "";
        string firstS, secondS;
        scanf ("\n");
        while (true) {
            getline(cin, auxS);
            if (auxS.size() == 0) break;
            for (int i = 0; i < auxS.size(); i++) {
                if (auxS[i] == ' ') {
                    firstS = string(auxS.begin(), auxS.begin() + i);
                    secondS = string(auxS.begin() + i + 1, auxS.end());
                }
            }
            cout << firstS << " " << secondS << " " << shortestPath(order[firstS], order[secondS]) << endl;
        }

        if (TC != 0) cout << endl;

    }

}
