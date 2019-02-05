#include <cstdio>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

int main() {
    char aux;
    map<char, vector<int> > S;
    scanf ("%c", &aux);
    int cont = 0;
    while ((aux >= 'a' && aux <= 'z') || (aux >= 'A' && aux <= 'Z')) {
        if (S.find(aux) == S.end()) {
            vector<int> t;
            t.push_back(cont);
            S[aux] = t;
        }
        else S[aux].push_back(cont);
        scanf ("%c", &aux);
        cont++;
    }
    int Q;
    scanf ("%d", &Q);
    for (int i = 0; i < Q; i++) {
        string q;
        cin >> q;
        int minCont, maxCont, thisCont;
        thisCont = 0;
        int val = 0;
        bool noMatch = false;
        for (int j = 0; j < q.size() && !noMatch; j++) {
            bool found = false;
            for (int k = 0; k < S[q[j]].size() && !found; k++) {
                if (val <= S[q[j]][k]) {
                    val = S[q[j]][k];
                    found = true;
                }
            }
            if (j == 0) minCont = val;
            if (j == q.size()- 1) maxCont = val;
            if (!found) noMatch = true;
            val++;
        }

        if (noMatch) cout << "Not matched" << endl;
        else cout << "Matched " << minCont << " " << maxCont << endl;
    }

}
