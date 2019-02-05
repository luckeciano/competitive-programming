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
vector<int> cityX, cityY;
int n, r;
vector< pair<double,ii> > EdgeList;
double roads, railroads;
int main() {
    int TC; cin >> TC;
    int cont = 0;
    while (TC --) {
        cityX.clear(); cityY.clear();
        EdgeList.clear();
        cont++;
        cin >> n >> r;
        cityX.resize(n); cityY.resize(n);
        for (int i = 0; i < n; i++) {
            cin >> cityX[i] >> cityY[i];
        }
        UnionFind states (n);
        for (int i = 0 ; i < n; i++) {
            for (int j = i; j < n; j++) {
                pair<double, ii > edge;
                double distance = sqrt((cityX[i] - cityX[j])*(cityX[i] - cityX[j]) + (cityY[i] - cityY[j])*(cityY[i] - cityY[j]));
                edge = make_pair(distance, make_pair(i, j));
                EdgeList.push_back(edge);
                if (distance <= r) states.unionSet(i, j);
            }
        }
        sort(EdgeList.begin(), EdgeList.end());
        roads = 0;
        railroads = 0;
        int mst_cost = 0;
        UnionFind UF(n); // all V are disjoint sets initially
        for (int i = 0; i < EdgeList.size(); i++) { // for each edge, O(E)
            pair<double, ii> frontE = EdgeList[i];
            if (!UF.isSameSet(frontE.second.first, frontE.second.second)) { // check
                if (states.isSameSet(frontE.second.first, frontE.second.second))
                    roads += frontE.first;
                else railroads += frontE.first;
                UF.unionSet(frontE.second.first, frontE.second.second); // link them
            }
        }
        cout << "Case #" << cont << ": " << states.numDisjointSets() << " " << roundf(roads) << " " << roundf(railroads) << endl;
    }
}

