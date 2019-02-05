#include <algorithm>
#include <cstdio>
#include <vector>
#include <iomanip>
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
int S, P;
vi cityX, cityY;
vector< pair<float, ii> > EdgeList;
float maxDist;
int main() {
    int TC; cin >> TC;
    while (TC--) {
        cin >> S >> P;
        cityX.clear(); cityY.clear();

        EdgeList.clear();
        cityX.resize(P); cityY.resize(P);
        for (int i = 0; i < P; i++) {
            cin >> cityX[i] >> cityY[i];
        }
        for (int i = 0; i < P; i++) {
            for (int j = i; j < P; j++) {
                float distance = sqrt((cityX[i] - cityX[j])*(cityX[i] - cityX[j]) + (cityY[i] - cityY[j])*(cityY[i] - cityY[j]));
                pair<float, ii> edge = make_pair(distance, make_pair(i, j));
                EdgeList.push_back(edge);
            }
        }

         sort(EdgeList.begin(), EdgeList.end());
        UnionFind UF(P);
        maxDist = -1;                    // all V are disjoint sets initially
      for (int i = 0; i < EdgeList.size() && UF.numDisjointSets() != S; i++) {                      // for each edge, O(E)
        pair<float, ii> frontE = EdgeList[i];
        if (!UF.isSameSet(frontE.second.first, frontE.second.second)) {  // check
          if (frontE.first > maxDist) maxDist = frontE.first;              // add the weight of e to MST
          UF.unionSet(frontE.second.first, frontE.second.second);    // link them
      } }

      cout << fixed << setprecision(2) << maxDist << endl;
    }


}
