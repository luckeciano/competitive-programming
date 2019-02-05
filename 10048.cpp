#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
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
  int sizeOfSet(int i) { return setSize[findSet(i)]; }
};
int maxEdge;
bool found;
vi dfs_num;
vector<vii> AdjList;

void dfs(int u,int k) {          // DFS for normal usage: as graph traversal algorithm
  //printf(" %d", u);                                    // this vertex is visited
  dfs_num[u] = 1;      // important step: we mark this vertex as visited
  if (u == k) {
    found = true;
    return;
  }
  for (int j = 0; j < (int)AdjList[u].size() && !found; j++) {
    ii v = AdjList[u][j];                      // v is a (neighbor, weight) pair
    if (dfs_num[v.first] == 0)         // important check to avoid cycle
      dfs(v.first, k);      // recursively visits unvisited neighbors v of vertex u

      if (found && v.second > maxEdge)
        maxEdge = v.second;

    }

}

int C, S, Q, a, b, l;
vector<pair<int, ii> > EdgeList;

int main() {
    //ofstream myf ("outs.txt");
    int cont = 0;
    while (cin >> C >> S >> Q, C || S || Q){
        if (cont != 0) {
            cout << endl;
            //myf << endl;
        }
        AdjList.clear();
        cont++;
        EdgeList.clear();
        for (int i = 0; i < S; i++) {
            cin >> a >> b >> l;
            pair<int, ii> edge = make_pair(l, make_pair(a - 1, b - 1));
            EdgeList.push_back(edge);
        }
         sort(EdgeList.begin(), EdgeList.end());
        UnionFind UF(C);
        AdjList.resize(C);                    // all V are disjoint sets initially
      for (int i = 0; i < EdgeList.size(); i++) {                      // for each edge, O(E)
        pair<int, ii> frontE = EdgeList[i];
        if (!UF.isSameSet(frontE.second.first, frontE.second.second)) {  // check
          //mst_cost += frontE.first;
          AdjList[frontE.second.first].push_back(make_pair(frontE.second.second, frontE.first));
          AdjList[frontE.second.second].push_back(make_pair(frontE.second.first, frontE.first));
          UF.unionSet(frontE.second.first, frontE.second.second);    // link them
      } }
        cout << "Case #" << cont  << endl;
       // myf << "Case #" << cont  << endl;
        for (int i = 0; i < Q; i++) {
            cin >> a >> b;
            dfs_num.assign(C, 0);
            maxEdge = -1;
            found = false;
            dfs(a - 1, b - 1);
            if (maxEdge == -1) {
                    cout << "no path" << endl;
                   // myf << "no path" << endl;
            }
            else {
            cout << maxEdge << endl;
            //myf << maxEdge << endl;
            }
        }

    }


}
