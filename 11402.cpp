#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

typedef vector<int> vi;

class SegmentTree {         // the segment tree is stored like a heap array
private: vi st, A;            // recall that vi is: typedef vector<int> vi;
  int n;
  int left (int p) { return p << 1; }     // same as binary heap operations
  int right(int p) { return (p << 1) + 1; }

  void build(int p, int L, int R) {                           // O(n log n)
    if (L == R)
       st[p] = A[L];                        // store the index
    else {                                // recursively compute the values
      build(left(p) , L              , (L + R) / 2);
      build(right(p), (L + R) / 2 + 1, R          );
      int p1 = st[left(p)], p2 = st[right(p)];
      st[p] = p1 + p2;
    }
  }

   int rsq(int p, int L, int R, int i, int j) {                  // O(log n)
    if (i >  R || j <  L) return 0; // current segment outside query range
    else if (L >= i && R <= j) return st[p];
    else {
        return rsq(left(p) , L              , (L+R) / 2, i, j) +
                    rsq(right(p), (L+R) / 2 + 1, R          , i, j);

    }
   }

   void update_point(int p, int L, int R, int idx, int diff) {
    // this update code is still preliminary, i == j
    // must be able to update range in the future!
    int i = idx;

    // if the current interval does not intersect
    // the update interval, return this st node value!
    if (i > R || i < L)
      return;

    // if the current interval is included in the update range,
    // update that st[node]
    st[p] += diff;
    if (L != R) {
       update_point(left(p) , L              , (L + R) / 2, idx, diff);
       update_point(right(p), (L + R) / 2 + 1, R          , idx, diff);
    }
  }

  void updateRangeUtil (int p, int L, int R, int a, int b, int new_value) {
    if (L > R ||  L > b || R < a)
        return;

    if (L == R) {

        st[p] = new_value;
        return;
    }

    updateRangeUtil(left(p) , L              , (L + R) / 2, a, b,  new_value);
    updateRangeUtil(right(p), (L + R) / 2 + 1, R   , a , b, new_value);

    st[p] = st[right(p)] + st[left(p)];


  }

  void updateRangeUtil (int p, int L, int R, int a, int b, char inv) {
    if (L > R ||  L > b || R < a)
        return;

    if (L == R) {

        if (st[p] == 1) st[p] = 0;
        else st[p] = 1;
        return;
    }

    updateRangeUtil(left(p) , L              , (L + R) / 2, a, b,  inv);
    updateRangeUtil(right(p), (L + R) / 2 + 1, R   , a , b, inv);

    st[p] = st[right(p)] + st[left(p)];


  }


public:
  SegmentTree(const vi &_A) {
    A = _A; n = (int)A.size();              // copy content for local usage
    st.assign(4 * n, 0);            // create large enough vector of zeroes
    build(1, 0, n - 1);                                  // recursive build
  }
  int rsq(int i, int j) {return rsq(1, 0, n-1, i, j); }

  void update_point(int idx, int new_value) {
    int diff = new_value - A[idx];
    A[idx] = new_value;
    update_point(1, 0, n - 1, idx, diff); }

    void updateRange (int a, int b, int new_value) {
        updateRangeUtil (1, 0, n-1, a, b, new_value);
    }

    void updateRange (int a, int b, char inv) {
        updateRangeUtil (1, 0, n-1, a, b, inv);
    }

    void printST() {
        for (int i = 0; i < n; i++) {
            cout << st[i] << " ";
        }
        cout << endl;
    }
};


int main() {
    int T;
    cin >> T;
    int caseL = 0;
    while (T--) {
        caseL++;
        cout << "Case " << caseL << ":" << endl;
        int M; cin >> M;
        vector<int> land;
        for (int i = 0; i < M; i++) {
            int T; cin >> T;
            string pir;
            cin >> pir;
            for (int k = 0; k < T; k++) {
                for (int j = 0; j < pir.size(); j++) {
                    land.push_back(pir[j] - '0');
                }
            }
        }
        int Q;
        cin >> Q;
        SegmentTree st(land);
        int godQ = 0;
        for (int i = 0; i < Q; i++) {

            char k; int a; int b;
            cin >> k >> a >> b;
            if (k == 'F') {
                st.updateRange(a, b, 1);
            }
            else if (k == 'E') {
                st.updateRange(a, b, 0);
            }
            else if (k == 'I') {
                    st.updateRange(a, b, 'I');
            }
            else if (k == 'S') {
                godQ++;
                cout << "Q" << godQ << ": ";
                cout << st.rsq(a, b) << endl;

            }
        }
    }


}
