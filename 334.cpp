#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;


int main() {
    int n, x;
    string sA, A, B;
    vector<string> rOrder;
    vector<vector<string> > total;
    map<string, int> verts;
    vector<vector<int> > AdjMat;
    int cont = 0;
    while (cin >> n, n) {
        cont++;
        int v = 0;
        rOrder.clear();
        total.clear();
        verts.clear();
        AdjMat.clear();
        for (int i = 0; i < n; i++) {
            vector<string> aux;
            cin >> x;
            for (int j = 0; j < x; j++) {
                cin >> sA;
                if (verts.find(sA) == verts.end()) {
                    verts[sA] = v;
                    rOrder.push_back(sA);
                    v++;
                }
                aux.push_back(sA);
            }
        total.push_back(aux);
        }
        AdjMat.resize(v);
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                AdjMat[i].push_back(0);
                if (i == j) AdjMat[i][j] = 1;
            }
        }
        for (int i = 0; i < total.size(); i++) {
            for (int j = 1; j < total[i].size(); j++) {
                    AdjMat[verts[total[i][j-1]]][verts[total[i][j]]] = 1;
            }
        }
        cin >> x;
        for (int i = 0; i < x; i++) {
            cin >> A >> B;
            AdjMat[verts[A]][verts[B]] = 1;
        }/*
        for (int i = 0; i < v; i++) {
            for (int j = 0; j < v; j++) {
                cout << AdjMat[i][j] << " ";
            }
            cout << endl;
        }*/
        for (int k = 0; k < v; k++)
            for (int i = 0; i < v; i++)
                for (int j = 0; j < v; j++)
                    AdjMat[i][j] |= (AdjMat[i][k] & AdjMat[k][j]);
        vector<pair<int,int> > conc;
        for (int i = 0; i < v; i++) {
            for (int j = i + 1; j < v; j++) {
                if (!(AdjMat[i][j] || AdjMat[j][i]))
                    conc.push_back(make_pair(i, j));
            }
        }
        cout << "Case " << cont << ", ";
        if (conc.size() == 0) cout << "no concurrent events." << endl;
        else {
            cout << conc.size() << " concurrent events:" << endl;
            if (conc.size() == 1) cout << "(" << rOrder[conc[0].first] << "," << rOrder[conc[0].second] << ") " << endl;
            else {
                cout << "(" << rOrder[conc[0].first] << "," << rOrder[conc[0].second] << ") (" << rOrder[conc[1].first] << "," <<
                rOrder[conc[1].second]  << ") " << endl;
            }
        }
    }


}
