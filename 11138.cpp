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



int main() {
    int TC; cin >> TC;
    int b, n, k; int cont =0;
    while (TC--) {
        cont++;
        cin >> b >> n;
        AdjList.clear(); AdjList.resize(b + n);
        for (int i = 0; i < b; i++) {
            for (int j = 0; j < n; j++) {
                cin >> k;
                if (k) {
                    AdjList[i].push_back(b + j);
                }
            }
        }

        int MCBM = 0;
        match.assign(n + b, -1); // V is the number of vertices in bipartite graph
        for (int l = 0; l < b; l++) { // n = size of the left set
            vis.assign(b, 0); // reset before each recursion
            MCBM += Aug(l);
        }
        cout << "Case " << cont << ": a maximum of " << MCBM << " nuts and bolts can be fitted together" << endl;
    }

}
