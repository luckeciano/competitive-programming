#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

typedef vector<int> vi;

// Union-Find Disjoint Sets Library written in OOP manner, using both path compression and union by rank heuristics
class UnionFind {                                              // OOP style
private:
  vi p, rank, setSize;                       // remember: vi is vector<int>
  int numSets;
public:
  UnionFind(int N) {
    setSize.assign(N, 1); numSets = N; rank.assign(N, 0);
    p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; }
  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) {
    if (!isSameSet(i, j)) { numSets--;
    int x = findSet(i), y = findSet(j);
    // rank is used to keep the tree short
    if (rank[x] > rank[y]) { p[y] = x; setSize[x] += setSize[y]; }
    else                   { p[x] = y; setSize[y] += setSize[x];
                             if (rank[x] == rank[y]) rank[y]++; } } }
  int numDisjointSets() { return numSets; }
  int sizeOfSet(int i) { return setSize[findSet(i)]; }
};

int main() {
    int t;
    while (cin >> t) {
        int M; cin >> M;
        int years = 0;
        char initialWake[3];
        UnionFind uF (26);
        for (int i = 0; i < 3; i++) {
            cin >> initialWake[i];
        }
        uF.unionSet(initialWake[0] - 'A', initialWake[1] - 'A');
        uF.unionSet(initialWake[0] - 'A', initialWake[2] - 'A');
        bool conn[26][26] = {{false}};
        bool area[26] = {false};
        for (int i = 0; i < M; i++) {
            char a, b;
            cin >> a >> b;
            area[a-'A'] = true;
            area[b - 'A'] = true;
            conn[a-'A'][b-'A'] = true;
            conn[b-'A'][a-'A'] = true;
        }
        bool changed = true;
        int N = t - 3;
        while (changed) {
            changed = false;
            bool wakeIt[26] = {false};
            for (int i = 0; i < 26; i++ ){
                if (uF.isSameSet(i, initialWake[0] - 'A')) {
                    continue;
                }
                int cont = 0;
                for (int j = 0; j < 26; j++) {
                    if(conn[i][j] && uF.isSameSet(j, initialWake[0] - 'A'))
                        cont++;
                }
                if (cont > 2) {
                    changed = true;
                    wakeIt[i] = true;
                    N--;
                }
            }
            for (int i = 0; i < 26; i++ ){
                if (wakeIt[i])
                    uF.unionSet(i, initialWake[0] - 'A');
            }
            if (changed) years++;
        }
        if (N <= 0) cout << "WAKE UP IN, " << years << ", YEARS" << endl;
        else cout << "THIS BRAIN NEVER WAKES UP" << endl;

    }

}
