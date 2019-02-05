#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

bool isPrime (int k) {
    for (int i = 2; i <= (int)sqrt(k); i++) {
        if (k % i == 0) return false;
    }
    return true;
}

void backtrack (int n, vector<int> solution, vector<bool> used, int i) {
    if (i == n && isPrime(solution[n - 1] + solution[0])) {
        cout << solution[0];
        for (int k = 1; k < n; k++) {
            cout << " " << solution[k];
        }
        cout << endl;
        return;
    } else {
        for (int k = 0; k < n; k++) {
            if (!used[k] && isPrime(k + 1 + solution[i - 1])) {
                solution[i] = k + 1;
                used[k] = true;
                backtrack(n, solution, used, i + 1);
                used[k] = false;
            }
        }

    }


}


void solve (int n) {
    vector <bool> used;
    for (int i = 0; i < n; i++)
        used.push_back(false);

    vector<int> solution;
    solution.resize(n);

    solution[0] = 1;
    used[0] = true;
    backtrack(n, solution, used, 1);



}

int main() {
    int n;
    int cont = 0;
    while (cin >> n) {
        if (cont != 0) cout << endl;
        cont ++;
        cout << "Case " << cont << ":" << endl;
        solve (n);
    }


}
