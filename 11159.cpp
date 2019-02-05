#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;
vector<vector<int> > AdjList;
vi match, vis; // global variables
int Aug(int l) { // return 1 if an augmenting path is found
    if (vis[l]) return 0; // return 0 otherwise
    vis[l] = 1;
    for (int j = 0; j < (int)AdjList[l].size(); j++) {
        int r = AdjList[l][j]; // edge weight not needed -> vector<vi> AdjList
        if (match[r] == -1 || Aug(match[r])) {
            match[r] = l; return 1; // found 1 matching
    } }
    return 0; // no matching
}

bool isMultiple (int a, int b) {
    if (b == 0 && a == 0) return true;
    if (a == 0) return false;
    if (b%a == 0) return true;

    return false;


}

int main() {
    int TC; cin >> TC;
    int n, m; int vLeft[105], vRight[105];
    int cont = 0;
    while (TC--) {
        cont++;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> vLeft[i];
        }
        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> vRight[i];
        }
        AdjList.clear(); AdjList.resize(n + m);
        for (int i = 0; i < n ; i++) {
            for (int j = 0; j < m; j++) {
                if (isMultiple(vLeft[i], vRight[j])) {
                    AdjList[i].push_back(n + j);
                }
            }
        }

        int MCBM = 0;
        match.assign(n + m, -1); // V is the number of vertices in bipartite graph
        for (int l = 0; l < n; l++) { // n = size of the left set
            vis.assign(n, 0); // reset before each recursion
            MCBM += Aug(l);
        }
        cout << "Case " << cont << ": " << MCBM << endl;
    }


}
