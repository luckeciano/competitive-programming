#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

typedef vector<int> vi;
#define LSOne(S) (S & (-S))

class FenwickTree {
private:
  vi ft;

public:
  FenwickTree() {}
  // initialization: n + 1 zeroes, ignore index 0
  FenwickTree(int n) { ft.assign(n + 1, 1); }

  int rpq(int b) {                                     // returns RPQ(1, b)
    int sum = 1; for (; b; b -= LSOne(b)) sum *= ft[b];
    return sum; }

  int rpq(int a, int b) {

    return rpq(b) * (a == 1 ? 1 : rpq(a - 1)); }

  // adjusts value of the k-th element by v (v can be +ve/inc or -ve/dec)
  void adjust(int k, int v) {                    // note: n = ft.size() - 1
    for (; k < (int)ft.size(); k += LSOne(k)) ft[k] *= v; }
};

int main () {
    int N, K;
    while (cin >> N >> K) {
        FenwickTree fT(N);
        vector<int> n;
        vector<int> hasZeroes;
        for (int i = 1; i <= N; i++) {
            int aux;
            cin >> aux;

            if (aux == 0) {
                n.push_back(1);
                hasZeroes.push_back(i);
            }
            else if (aux > 0)
               n.push_back(1);
            else {
                n.push_back(-1);
                fT.adjust(i, -1);
            }
        }
        for (int i = 0; i < K; i++) {
            char q; int a, b;
            cin >> q >> a >> b;
            if (q == 'C') {
                if (b == 0) {
                    hasZeroes.push_back(a);
                } else {
                    vector<int>::iterator it;
                    for (it = hasZeroes.begin(); it != hasZeroes.end(); it++) {
                        if (*it == a) {
                            hasZeroes.erase(it);
                            break;
                        }
                    }
                    if (n[a - 1] * b < 0) fT.adjust(a, -1);
                    if ( b > 0) n[a - 1] = 1;
                    else n[a - 1] = - 1;
                }
            }
            else if (q == 'P') {
                bool isZero = false;

                for (int j =0; j < hasZeroes.size() && !isZero; j++) {
                    if (hasZeroes[j] >= a && hasZeroes[j] <= b) {
                        isZero = true;
                        break;
                    }
                }

               // cout << "value: " << x << endl;
                if (isZero) cout << 0;
                else {
                    int x = fT.rpq(a, b);
                    if (x > 0) cout << "+";
                    else cout << "-";
                }
            }
        }
        cout << endl;
    }

}
