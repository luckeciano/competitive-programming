#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<string> possibleChild (string p1, string p2) {
    if (p1.size() == 2) {
        p1 = "O" + p1;
    }
    if (p2.size() == 2) {
        p2 = "O" + p2;
    }
    bool bothNegative = false;
    if (p2[2] == '-' && p1[2] == '-') bothNegative = true;
    vector<string> r;
    for (int i = 0; i < p1.size() - 1; i++) {
        for (int j = 0; j < p2.size() - 1; j++) {
            string aux;
            aux.push_back(p1[i]);
            aux.push_back(p2[j]);
            if (aux == "BA") {
                aux[0] = p2[j];
                aux[1] = p1[i];
            }
            string aux1 = aux + "-";
            r.push_back(aux1);

            if (!bothNegative) {
                aux = aux + "+";
                r.push_back(aux);
            }

        }
    }

    for (int i = 0; i < r.size(); i++) {
        if (r[i][0] == 'O') {
            string aux;
            aux.push_back(r[i][1]);
            aux.push_back(r[i][2]);
            r[i] = aux;
        } else if (r[i][1] == 'O') {
            string aux;
            aux.push_back(r[i][0]);
            aux.push_back(r[i][2]);
            r[i] = aux;
        }
        else if (r[i][0] == r[i][1]) {
            string aux;
            aux.push_back(r[i][1]);
            aux.push_back(r[i][2]);
            r[i] = aux;
        }

    }

    vector<string> finalR;
    for (int x = 0; x < r.size(); x++) {
        bool exists = false;
        for (int y = 0; y < finalR.size(); y++) {
            if (finalR[y] == r[x])
                exists = true;
        }
        if (!exists) finalR.push_back(r[x]);
    }

    return finalR;


}

vector<string> possibleParent (string p, string ch) {
    vector<string> bloods = {"A+", "A-", "B+", "B-", "O+", "O-", "AB+", "AB-"};
    vector<string> result;
    for (int i = 0; i < bloods.size(); i++) {
        string blood = bloods[i];
        vector<string> posC = possibleChild (blood, p);
        for (int j = 0; j < posC.size(); j++) {
            if (posC[j] == ch)
                result.push_back(blood);
        }
    }

    return result;

}


int main() {
    string p1, p2, ch;
    cin >> p1 >> p2 >> ch;
    int cont = 0;
    while (p1 != "E") {
        cont ++;
        if (p1 == "?") {
            vector<string> posP = possibleParent (p2, ch);
            cout << "Case " << cont << ": ";
            if (posP.size() != 0) {
                if (posP.size() > 1) cout << "{" ;
                for (int i = 0; i < posP.size(); i++) {
                    cout << posP[i];
                    if (i != posP.size() - 1) cout << ", ";
                }
                if (posP.size() > 1) cout << "}";
                cout << " " << p2 << " " << ch << endl;
            } else {
                cout << "IMPOSSIBLE " << p2 << " " << ch << endl;
            }
        }
        else if (p2 == "?") {
            vector<string> posP = possibleParent (p1, ch);
            cout << "Case " << cont << ": ";
            cout << p1 << " ";
            if (posP.size() != 0) {
                if (posP.size() > 1) cout << "{" ;
                for (int i = 0; i < posP.size(); i++) {
                    cout << posP[i];
                    if (i != posP.size() - 1) cout << ", ";
                }
                if (posP.size() > 1) cout << "}";
                cout << " " << ch << endl;
            } else {
                cout << "IMPOSSIBLE " << ch << endl;
            }
        }
        else {
            vector<string> posC = possibleChild (p1,p2);
            cout << "Case " << cont << ": ";
            cout << p1 << " " << p2 << " ";
            if (posC.size() > 1) cout << "{";
            for (int i = 0; i < posC.size(); i++) {
                cout << posC[i];
                if (i != posC.size() - 1) cout << ", ";
            }
            if (posC.size() > 1) cout << "}" ;
            cout << endl;

        }
        cin >> p1 >> p2 >> ch;
    }

}
