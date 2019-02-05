#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
void backtrack (vector<string> inter, int n, set<string> &solutions, int i, string sol, bool &ended) {
    if (ended) return;
    if (sol.size() == 5) {
        if (solutions.find(sol) == solutions.end())
            solutions.insert(sol);
        if (solutions.size() == n) {
            cout << sol << endl;
            ended = true;
        }
        return;
    }
    for (int k = 0; k < inter[i].size() && !ended; k++){
        sol.push_back(inter[i][k]);
        backtrack(inter, n, solutions, i + 1, sol, ended);
        sol.erase(prev(sol.end()));
    }



}

void solve (vector<string> inter, int k) {
    string sol;
    bool ended = false;
    set<string> solutions;
    for (int i = 0; i < inter[0].size() && !ended; i++) {
        sol.push_back(inter[0][i]);
        backtrack(inter, k, solutions, 1, sol, ended);
        sol.clear();
    }
    if (solutions.size() < k) cout << "NO" << endl;



}



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
        string line;
        vector<string> inter;
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

        solve (inter, k);


    }




}
