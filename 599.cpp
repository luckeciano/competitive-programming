#include <iostream>
#include <vector>
#include <bitset>

using namespace std;


void dfs (vector<vector<int> > graph, int i, bitset<26> &visited, int &nEdges) {
    for (int j = 0; j < graph[i].size(); j++) {
        if (!visited[graph[i][j]]) {
            visited[graph[i][j]] = true;
            nEdges++;
            dfs(graph, graph[i][j], visited, nEdges);
        }
    }


}

int main(){
    int N;
    cin >> N;
    while (N--) {
        int trees = 0;
        int corns = 0;
        string aux;
        cin >> aux;
        bitset<26> visited = {false};
        while (aux[0] != '*') {
            int F = aux[1];
            int T = aux[3];
            if (!visited[F - 'A'] && !visited[T-'A']) {
                trees++;
            }
            else if (visited[F - 'A'] && visited[T-'A']) {
                trees--;
            }
            visited[F-'A'] = true;
            visited[T - 'A'] = true;
            cin >> aux;
        }
        cin >> aux;
        for (int i = 0; i < aux.size(); i++) {
            if (aux[i] != ',') {
                if (!visited[aux[i] - 'A'])
                    corns++;
            }
        }

        cout << "There are " << trees << " tree(s) and " << corns << " acorn(s)." << endl;



    }




}
