#include <algorithm>
#include <cstdio>
#include <vector>
#include <iomanip>
#include <cmath>
#include <iostream>
#include <fstream>
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
  int sizeOfSet(int i) { return
   setSize[findSet(i)]; }
};

int N, M, a, b, l;
vector<pair<int, ii> > EdgeList;
vi mstEdges;
int mst_cost, sec_mst_cost;
int main() {
   // ofstream myf("oloco.txt");
    int TC; cin >> TC;
    while (TC--) {
        cin >> N >> M;
        EdgeList.clear();
        mstEdges.clear();
        for (int i = 0; i < M; i++) {
            cin >> a >> b >> l;
            pair<int, ii> edge = make_pair(l, make_pair(a - 1, b - 1));
            EdgeList.push_back(edge);
        }
        mst_cost = 0;
        sort(EdgeList.begin(), EdgeList.end());
        UnionFind UF(N);                     // all V are disjoint sets initially
      for (int i = 0; i < EdgeList.size(); i++) {                      // for each edge, O(E)
        pair<int, ii> frontE = EdgeList[i];
        if (!UF.isSameSet(frontE.second.first, frontE.second.second)) {  // check
            mstEdges.push_back(i);
          mst_cost += frontE.first;                // add the weight of e to MST
          UF.unionSet(frontE.second.first, frontE.second.second);    // link them
      } }
      int new_mst_cost = 0;
      sec_mst_cost = 10000000;
      for (int j = 0; j < mstEdges.size(); j++) {
            new_mst_cost = 0;
          UnionFind UF(N);                     // all V are disjoint sets initially
          for (int i = 0; i < EdgeList.size(); i++) {
              if (i != mstEdges[j]) {                      // for each edge, O(E)
                    pair<int, ii> frontE = EdgeList[i];
                    if (!UF.isSameSet(frontE.second.first, frontE.second.second)) {  // check
                      new_mst_cost += frontE.first;                // add the weight of e to MST
                      UF.unionSet(frontE.second.first, frontE.second.second);    // link them
                    }
              }
           }
           if (UF.numDisjointSets() == 1 && new_mst_cost < sec_mst_cost) sec_mst_cost = new_mst_cost;

      }

      cout << mst_cost << " " << sec_mst_cost << endl;
      //myf << mst_cost << " " << sec_mst_cost << endl;
    }

}
