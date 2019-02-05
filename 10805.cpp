#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#define INF 10000000

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;


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
    int TC; cin >> TC;
    int cont = 0;
    vector<pair<int, int > > EdgeList, finalTree;
    vector<vector<int> > AdjList;
    int n, m, a, b;
    while (TC --) {
        cont++;
        EdgeList.clear();
        finalTree.clear();
        cin >> n >> m;
        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            pair<int, int> edge; edge.first = a; edge.second = b;
            EdgeList.push_back(edge);
        }
        sort(EdgeList.begin(), EdgeList.end());
        int mst_cost = 0;
        UnionFind UF(n); // all V are disjoint sets initially
        for (int i = 0; i < EdgeList.size(); i++) { // for each edge, O(E)
            pair<int, int> front = EdgeList[i];
            if (!UF.isSameSet(front.first, front.second)) { // check
                finalTree.push_back(front);
                mst_cost ++; // add the weight of e to MST
                UF.unionSet(front.first, front.second); // link them
            }
        }
        AdjList.clear();
        AdjList.resize(n);
        for (int i = 0; i < finalTree.size(); i++) {
            AdjList[finalTree[i].first].push_back(finalTree[i].second);
            AdjList[finalTree[i].second].push_back(finalTree[i].first);
        }

         int nodeA, nodeB;
            int maxDist = 0; int node = 0;
            vector<int> distA(n, INF); distA[0] = 0; // distance from source s to s is 0
            queue<int> q; q.push(0);
            //vector<int> p; // addition: the predecessor/parent vector
            while (!q.empty()) {
            int u = q.front(); q.pop();
                for (int j = 0; j < (int)AdjList[u].size(); j++) {
                int v = AdjList[u][j];
                if (distA[v] == INF) {
                    distA[v] = distA[u] + 1;
                    if (distA[v] > maxDist) {
                        maxDist = distA[v];
                        nodeA = v;
                    }
                    q.push(v);
            } } }



            vector<int> distB(n, INF);
            distB[nodeA] = 0;
            maxDist = 0;
            q.push(nodeA);
            while (!q.empty()) {
            int u = q.front(); q.pop();
                for (int j = 0; j < (int)AdjList[u].size(); j++) {
                int v = AdjList[u][j];
                if (distB[v] == INF) {
                    distB[v] = distB[u] + 1;
                    if (distB[v] > maxDist) {
                        maxDist = distB[v];
                        nodeB = v;
                        //vMaxMax.clear();
                        //vMaxMax.push_back(v + 1);
                    } //else if (distB[v] == maxDist) vMaxMax.push_back(v + 1);
                    q.push(v);
            } } }

            cout << "Case #" << cont << ":" << endl;
            cout << maxDist << endl;
            cout << endl;

    }



}
