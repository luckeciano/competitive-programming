#include <iostream>
#include <map>
#include <vector>
#include <cstdio>
#include <string>

using namespace std;
int cont = 0;
map <char, vector<char> > graph;
void topsort (char node, map<char, bool> visited, string res) {
    res.push_back(node);
    visited[node] = true;
    if (res.size() == graph.size()) {
        cont++;
        for (int i = 0; i < res.size(); i++) {
            if (i != 0) cout << " ";
            cout << res[i];

        }
        cout << endl; return;
    }
    map<char, bool>::iterator vis;
    for (vis = visited.begin(); vis != visited.end(); vis++) {
        if (!vis->second) {
            for (int t = 0; t < graph[vis->first].size(); t++) {
                if (graph[vis->first][t] == node)
                    return;
            }

        }
    }

    for (vis = visited.begin(); vis != visited.end(); vis++) {
        if (!vis->second) {
            topsort(vis->first, visited, res);
        }
    }


}

int main() {
    int TC; cin >> TC;
    string aux = "";
    map<char, bool> visited;
    while (TC--) {
        scanf ("\n");
        graph.clear();
        visited.clear();
        getline(cin, aux);
        for (int i = 0; i < aux.size(); i++) {
            if (aux[i] != ' ') {
                vector<char> vec;
                graph[aux[i]] = vec;
                visited[aux[i]] = false;
            }
        }
        getline (cin, aux);
        for (int i = 0; i < aux.size(); i += 4) {
            graph[aux[i]].push_back(aux[i + 2]);
        }

        map<char, vector<char> > :: iterator it;
        string res;
        cont = 0;
        for (it = graph.begin(); it != graph.end(); it++) {
            res = "";
            topsort(it->first, visited, res);
        }

        if (cont == 0) cout << "NO" << endl;
        if (TC != 0) cout << endl;
    }



}
