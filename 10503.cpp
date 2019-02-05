#include <iostream>
#include <vector>

using namespace std;

void backtrack (vector<pair<int, int> > dominoes, vector<bool> used, pair<int, int> r, pair<int, int> lastPiece, int n, bool &sol, int i) {
    if (i == n && lastPiece.second == r.first) {
        sol = true;
        return;
    } else if (!sol) {
        pair<int, int> aux = lastPiece;
        for (int k = 0; k < dominoes.size() && !sol; k++) {
            if (!used[k] && dominoes[k].first == lastPiece.second) {
                used[k] = true;
                lastPiece = dominoes[k];
                backtrack(dominoes, used, r, lastPiece, n, sol, i + 1);
                used[k] = false;
            }
            else if (!used[k] && dominoes[k].second == lastPiece.second) {
                used[k] = true;
                lastPiece = make_pair (dominoes[k].second, dominoes[k].first);
                backtrack(dominoes, used, r, lastPiece, n, sol, i + 1);
                used[k] = false;
            }

            lastPiece = aux;
        }

    }


}


void solve (vector<pair<int, int> > dominoes,vector<bool> used,  pair<int, int> l, pair<int, int> r, int n, int m) {

    bool sol = false;
    pair<int, int> lastPiece;
    for (int i = 0; i < dominoes.size() && !sol; i++) {
        if (l.second == dominoes[i].first) {
            used[i] = true;
            lastPiece = dominoes[i];
            backtrack (dominoes, used, r, lastPiece, n, sol, 1);
            used[i] = false;
        }
        else if (l.second == dominoes[i].second) {
            used [i] = true;
            lastPiece = make_pair(dominoes[i].second, dominoes[i].first);
            backtrack (dominoes, used, r, lastPiece, n, sol, 1);
            used[i] = false;
        }

    }

    if (sol) cout << "YES" << endl;
    else cout << "NO" << endl;



}


int main() {
    int n;
    cin >> n;
    vector<pair<int,int> > dominoes;
    vector<bool> used;
    while (n != 0) {
        dominoes.clear();
        used.clear();
        int m; cin >> m;
        pair<int, int> l, r;
        int a, b;
        cin >> a >> b;
        l = make_pair(a, b);
        cin >> a >> b;
        r = make_pair(a, b);
        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            dominoes.push_back(make_pair(a,b));
            used.push_back(false);
        }

        solve (dominoes, used,  l, r, n, m);

        cin >> n;
    }



}
