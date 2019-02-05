#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <iostream>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

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
int n, m, a, b, l;
vector<int> chords;
vector<pair < int, ii> > EdgeList;
int main() {
    while (cin >> n >> m, n || m) {
        EdgeList.clear();
        chords.clear();
        for (int i = 0; i < m ; i++) {
            cin >> a >> b >> l;
            pair<int, ii> edge = make_pair(l, make_pair(a, b));
            EdgeList.push_back(edge);
        }


         sort(EdgeList.begin(), EdgeList.end());
        UnionFind UF(n);                     // all V are disjoint sets initially
      for (int i = 0; i < EdgeList.size(); i++) {                      // for each edge, O(E)
        pair<int, ii> frontE = EdgeList[i];
        if (!UF.isSameSet(frontE.second.first, frontE.second.second)) {  // check
          //mst_cost += frontE.first;                // add the weight of e to MST
          UF.unionSet(frontE.second.first, frontE.second.second);    // link them
      } else chords.push_back(frontE.first);
       }
       if (chords.size() == 0) cout << "forest" << endl;
       else {
            sort(chords.begin(), chords.end());
            for (int i = 0; i < chords.size(); i++) {
                if (i != 0) cout << " ";
                cout << chords[i];
            }
            cout << endl;
       }

    }



}
