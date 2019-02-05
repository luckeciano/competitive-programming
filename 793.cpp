#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
using namespace std;

typedef vector<int> vi;

// Union-Find Disjoint Sets Library written in OOP manner, using both path compression and union by rank heuristics
class UnionFind {                                              // OOP style
private:
  vi p, rankS, setSize;                       // remember: vi is vector<int>
  int numSets;
public:
  UnionFind(int N) {
    setSize.assign(N, 1); numSets = N; rankS.assign(N, 0);
    p.assign(N, 0); for (int i = 0; i < N; i++) p[i] = i; }
  int findSet(int i) { return (p[i] == i) ? i : (p[i] = findSet(p[i])); }
  bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }
  void unionSet(int i, int j) {
    if (!isSameSet(i, j)) { numSets--;
    int x = findSet(i), y = findSet(j);
    // rank is used to keep the tree short
    if (rankS[x] > rankS[y]) { p[y] = x; setSize[x] += setSize[y]; }
    else                   { p[x] = y; setSize[y] += setSize[x];
                             if (rankS[x] == rankS[y]) rankS[y]++; } } }
  int numDisjointSets() { return numSets; }
  int sizeOfSet(int i) { return setSize[findSet(i)]; }
};


int main() {
    int N;
    cin >> N;
    while (N--) {
        int t;
        cin >> t;
        UnionFind uF (t);
        int sucessf = 0;
        int unsucessf = 0;
        scanf ("\n");
        while (true) {
            string aux;
            getline(cin, aux);
            if (aux.size() == 0) break;
            char c = aux[0];
            int c1, c2;
            char a = aux[2];
            int cont = 2;
            string s = "";
            while (a != ' ') {
                s.push_back(a);
                cont++;
                a = aux[cont];
            }
            stringstream ss(s);
            ss >> c1;
            s = "";
            cont++;
            a = aux[cont];
            while (cont != aux.size()) {
                s.push_back(a);
                cont++;
                a = aux[cont];
            }
            stringstream ss2 (s);
            ss2 >> c2;
            if (c == 'c'){
                uF.unionSet(c1-1, c2-1);
            }
            else if (c == 'q') {
                if (uF.isSameSet(c1-1, c2-1))
                    sucessf++;
                else unsucessf++;
            }
        }


        cout << sucessf << "," << unsucessf << endl;

        if (N != 0) cout << endl;
    }



}
