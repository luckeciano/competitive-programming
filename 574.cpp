#include <iostream>
#include <vector>
#include <set>
using namespace std;


void backtrack (vector<int> v, vector<bool> c, int n, int sum, int i, set<vector<int> > &solutions) {
    if (i == v.size())
        return;
    else if (c[i]) {
        sum += v[i];
        if (sum == n) {
            vector<int> sol;
            for (int k = 0; k < v.size(); k++) {
                if (c[k]) {
                    sol.push_back(v[k]);
                }
            }
            if (solutions.find(sol) == solutions.end()){
                solutions.insert(sol);
            }
            return;
        } else if (sum > n) return;
    }

    if (i + 1 != c.size()) c[i + 1] = true;
    backtrack(v, c, n, sum, i + 1, solutions);
    if (i + 1 != c.size()) c[i + 1] = false;
    backtrack (v,c, n, sum, i + 1, solutions);


}

void solve (vector<int> v, vector<bool> c, int n, set<vector<int> > &solutions) {
    int sum = 0;

    c[0] = true;
    backtrack (v, c, n, sum, 0, solutions);
    c[0] = false;
    backtrack (v, c, n, sum, 0, solutions);
}



int main() {
    int t, n;
    cin >> t >> n;
    vector<int> v;
    vector<bool> c;
    set<vector<int> > solutions;
    while (n != 0) {
        v.clear();
        solutions.clear();
        c.clear();
        int aux;
        for (int i = 0; i < n; i++) {
            cin >> aux;
            v.push_back(aux);
            c.push_back(false);
        }
        cout << "Sums of " << t << ":" << endl;
        solve(v, c, t,solutions);
        if (solutions.size() == 0)
            cout << "NONE" << endl;
        else {
            set<vector<int> >::reverse_iterator it;
            for (it = solutions.rbegin(); it != solutions.rend(); it++) {
                vector<int> sol = *it;
                for (int s = 0; s < sol.size(); s++) {
                    if (s != 0) cout << "+";
                    cout << sol[s];
                }
                cout << endl;
            }
        }
        cin >> t >> n;
    }





}

