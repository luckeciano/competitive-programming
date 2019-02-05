#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// when we need to print the shortest paths, we can call the method below:
int p[25][25][25]; float AdjMat[25][25][25];

void buildPath(int i, int j, int s) {
    if (s != 1) buildPath(i, p[i][j][s-1], s - 1);
    cout << p[i][j][s] + 1 << " ";
}
int n; float x;
int main () {
    while (cin >> n) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                p[i][j][0] = i;
                if (j == i) AdjMat [i][i][0] = 1.000;
                else {
                    cin >> x;
                    AdjMat[i][j][0] = x;
                }
            }
        }

        for (int s = 1; s < n; s++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    p[i][j][s] = 0; AdjMat[i][j][s] = 0;
                }
            }
        }

        bool solution = false;
        for (int s = 1; s < n && !solution; s++) {
         for (int k = 0; k < n; k++) // remember that loop order is k->i->j
            for (int i = 0; i < n; i++)
                for (int j = 0; j < n; j++) {
                    if (AdjMat[i][j][s] < AdjMat[i][k][s-1]*AdjMat[k][j][0]) {
                        AdjMat[i][j][s] = AdjMat[i][k][s-1]*AdjMat[k][j][0];
                        p[i][j][s] = k;
                    }
                }


            for (int i = 0 ; i < n && !solution; i++) {
                if (AdjMat[i][i][s] > 1.01) {
                    stack<int> st;
                    int j = i;
                    while (s) {
                        st.push(j = p[i][j][s--]);
                    }
                    cout << i + 1 << " ";
                    while (!st.empty()) {
                        cout << st.top() + 1 << " ";
                        st.pop();
                    }
                    cout << i + 1 << endl;
                    solution = true;
                }
            }
        }
        if (!solution) cout << "no arbitrage sequence exists" << endl;



     }



}
