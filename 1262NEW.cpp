#include <cstdio>
#include <algorithm>
#include <set>
#include <vector>
#include <iostream>
using namespace std;


int main () {
    int TC;
    cin >> TC;
    vector<string > a;
    vector<string > b;
    while (TC--) {
        a.clear();
        b.clear();
        int k;
        cin >> k;
        string aux;
        for (int i = 0; i < 6; i++) {
            cin >> aux;
            a.push_back(aux);
        }
        for (int i = 0; i < 6; i++) {
            cin >> aux;
            b.push_back(aux);
        }
        vector<string> inter;
        string line;
        for (int col = 0; col < 6; col++) {
            line.clear();
            for (int l =0 ; l < 6; l++) {
                for (int k = 0; k < 6; k++) {
                    if (a[l][col] == b[k][col])
                        line.push_back(a[l][col]);
                }
            }
            inter.push_back(line);
        }

       for (int i = 0; i < inter.size(); i++) {
            sort(inter[i].begin(), inter[i].end());
       }
        int cont = 0;
        string pw; pw.resize(5);
        vector<string> solutions;
        int r = 0;
        string lastSol = "";
        for (int a = 0; a < inter[0].size() && cont != k; a++) {
                if (a > 0 && inter[0][a] == inter[0][a - 1]) continue;
            for (int b = 0; b < inter[1].size() && cont != k; b++) {
                if (b > 0 && inter[1][b] == inter[1][b - 1]) continue;
                for (int c = 0; c < inter[2].size() && cont != k; c++) {
                    if (c > 0 && inter[2][c] == inter[2][c - 1]) continue;
                    for (int d = 0; d < inter[3].size() && cont != k; d++) {
                        if (d > 0 && inter[3][d] == inter[3][d - 1]) continue;
                        for (int e = 0; e < inter[4].size() && cont != k; e++) {
                            if (e > 0 && inter[4][e] == inter[4][e - 1]) continue;
                            cont++;
                            if (cont == k) {
                                pw[0] = inter[0][a];
                                pw[1] = inter[1][b];
                                pw[2] = inter[2][c];
                                pw[3] = inter[3][d];
                                pw[4] = inter[4][e];
                            }

                        }
                    }
                }
            }
        }
        if (cont == k) cout << pw << endl;
        else cout << "NO" << endl;


    }




}
