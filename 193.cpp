#include <iostream>
#include <vector>

using namespace std;



void backtrack (vector<vector<int> > graph, vector<bool> colored, int &maxNodes, vector<int> &nodesFromMax, int i) {
    if (i == colored.size()) {
        int cont = 0;
        for (int k = 0; k < colored.size(); k++) {
            if (colored[k]) cont++;
        }
        if (cont > maxNodes) {
            maxNodes = cont;
            nodesFromMax.clear();
            for (int k = 0; k < colored.size(); k++)
                if (colored[k]) nodesFromMax.push_back(k + 1);
        }

        return;
    }
    else if (colored[i]) {
        for (int k = 0; k < graph[i].size(); k++) {
            if (colored[graph[i][k]]) return;
        }

    }

    if (i + 1 != colored.size()) colored[i + 1] = true;
    backtrack(graph, colored, maxNodes, nodesFromMax, i + 1);
    if (i + 1 != colored.size()) colored[i + 1] = false;
    backtrack(graph, colored, maxNodes, nodesFromMax, i + 1);


}

void solve (vector<vector<int> > graph, vector<bool> colored) {
    int maxNodes = 0;
    vector<int> nodesFromMax;

    colored[0] = true;
    backtrack(graph, colored, maxNodes, nodesFromMax, 0);
    colored[0] = false;
    backtrack(graph, colored, maxNodes, nodesFromMax, 0);

    cout << maxNodes << endl;
    for (int i = 0; i < nodesFromMax.size(); i++) {
        cout << nodesFromMax[i];
        if (i != nodesFromMax.size() - 1) cout << " ";
    }
    cout << endl;


}



int main() {
    int TC;
    cin >> TC;
    vector<bool> colored;
    vector<vector<int> > graph;
    while (TC--) {
        colored.clear();
        graph.clear();
        int n, e;
        cin >> n >> e;
        for (int i = 0; i < n; i++)
            colored.push_back(false);
        graph.resize(n);
        for (int i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a-1].push_back(b-1);
            graph[b-1].push_back(a-1);
        }

        solve (graph, colored);

    }


}
