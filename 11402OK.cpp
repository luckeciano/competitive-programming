#include <cstdio>
#include <vector>
#include <algorithm>
#define INF (1<<30)
#include <iostream>
using namespace std ;

const int neutral = 0 ; //comp ( x , n e u t r a l ) = x
int comp ( int a , int b ) {
return a+b ;
}



typedef enum {
  op_0,
  op_F,
  op_E,
  op_I,
  op_S
} OP;

typedef vector<int> vi;
typedef vector<OP> vOP;

class SegmentTree {
private:
    vector<int> st;
    vOP opt;
    int sizeS;
    #define parent(p) (p>>1)
    #define left(p) (p << 1)
    #define right(p) ((p << 1) + 1)

     void build (int p, int L, int R, int *A) {
        opt[p] = op_0;
        if (L == R) {
            st[p] = A[L];
        }
        else {
            build (left(p), L, (L+R)/2, A);
            build (right(p), (L+R)/2 + 1, R, A);
            st[p] = comp(st[left(p)], st[right(p)]);
        }
     }

     int push (int p, int L, int R) {
        switch (opt[p]) {
          case op_F: {
            return (R-L+1);
          }
          case op_E: {
            return 0;
          }
          case op_I: {
            return (R-L+1)-st[p];
          }
          default:
            return st[p];
        }
     }

     inline OP mult(OP op1, OP op2) {
        static OP table[][4] = {
          {op_0, op_F, op_E, op_I},  //op1 = op_0
          {op_F, op_F, op_E, op_E},  //op1 = op_F
          {op_E, op_F, op_E, op_F},  //op1 = op_E
          {op_I, op_F, op_E, op_0}   //op1 = op_I
        };
        return table[op1][op2];
      }

     inline void propagate(int p, int L, int R) {
        if (opt[p]!=op_0) {

          opt[left(p)]=mult(opt[left(p)],opt[p]);
          opt[right(p)]=mult(opt[right(p)],opt[p]);

          int p1 = push(left(p), L          , (L+R) / 2);
          int p2 = push(right(p), (L+R) / 2+1, R);
          st[p] = p1+p2;
          opt[p] = op_0;
        }
  }

     int update (int p, int L, int R, int a, int b, OP op) {
        if ( a > R || b < L) return push(p, L, R);


        if (L >= a && R <= b) {
            opt[p] = mult(opt[p], op);
            return push(p, L, R);
        }

        propagate(p, L ,R);

        int p1 = update(left(p), L, (L+R)/2, a, b, op);
        int p2 = update(right(p), (L+R)/2 + 1, R, a, b, op);
        return st[p] = p1 + p2;

     }

     int query (int p, int L, int R, int a, int b) {
        if (a > R || b < L) return neutral;
        if (L >= a && R <= b) return push (p, L, R);

        propagate (p, L ,R);

        int p1 = query (left(p),L ,(L+R)/2 ,a ,b) ;
        int p2 = query ( right(p) ,(L+R)/2+1, R , a , b ) ;

        return comp(p1, p2);
     }
public:
    SegmentTree(int* beginS, int* endS) {
        sizeS = (int)(endS - beginS);
        st.assign(4*sizeS, 0);
        opt.assign(4*sizeS, op_0);
        build (1, 0, sizeS -1, beginS);
    }

    int query (int a, int b) {
        return query(1, 0, sizeS - 1, a, b);
    }

    void update (int a, int b, OP k) {
        update (1, 0, sizeS - 1, a, b, k);
    }

    void printST() {
        for (int i = 0; i < sizeS; i++) {
            cout << st[i] << " ";
        }
        cout << endl;
    }

};

int main() {
  OP idx[255];
  idx[(int)'F']=op_F;
  idx[(int)'E']=op_E;
  idx[(int)'I']=op_I;
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
        SegmentTree st(&(*land.begin()), &(*land.end()));
        //st.printST();
        int godQ = 0;
        for (int i = 0; i < Q; i++) {

            char k; int a; int b;
            cin >> k >> a >> b;
            if (k == 'F' || k == 'E' || k == 'I') {
                st.update(a, b, idx[(int)k]);
                //st.printST();
            }
            else if (k == 'S') {
                godQ++;
                cout << "Q" << godQ << ": ";
                cout << st.query(a, b) << endl;

            }
        }
    }


}

