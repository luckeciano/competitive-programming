#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

void backtrack (vector<int> tr, vector<bool> c, int i, int sum, int N, int &minDif, vector<bool> &finalSol) {
    if (i == tr.size())
        return;
    else if (c[i]) {
        sum += tr[i];
        if (sum == N) {
            minDif = 0;
            finalSol = c;
        } else if (sum > N) {
            return;
        } else if (N - sum <= minDif) {
            minDif = N - sum;
            finalSol = c;
        }
    }

    c[i + 1] = true;
    backtrack (tr, c, i+1, sum, N, minDif, finalSol);

    c[i + 1] = false;
    backtrack (tr, c, i+1, sum, N,  minDif, finalSol);



}


vector<bool> solve (vector<int> tr, vector<bool> c, int N) {
    int sum = 0;
    vector<bool> finalSol;
    int minDif = N - 0;
    int finalWeight = 0;
    c[0] = true;
    backtrack (tr, c, 0, sum,N, minDif, finalSol);
    c[0] = false;
    backtrack (tr, c, 0, sum, N,  minDif, finalSol);


    return finalSol;

}

int main() {
    int N;
    vector<int> tr;
    vector<bool> c;
    while (cin >> N) {
        tr.clear();
        int t;
        cin >> t;
        int aux;
        for (int i = 0; i < t; i++) {
            cin >> aux;
            tr.push_back(aux);
            c.push_back(false);
        }

        vector<bool> solution;
        solution = solve (tr, c, N);
        int sum = 0;
        for (int i = 0; i < solution.size(); i++) {
            if (solution[i]) {
                cout << tr[i] << " ";
                sum += tr[i];
            }
        }
        cout << "sum:" << sum << endl;


    }







}
