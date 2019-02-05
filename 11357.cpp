#include <iostream>

using namespace std;
bool checkClause (string clause) {
    int used [30] = {0};
    for (int i = 0; i < clause.size(); i++) {
        if (clause[i] >= 'a' && clause[i] <= 'z') {
            if (used[clause[i] - 'a'] == -1) return false;
            else {
                used[clause[i] - 'a'] = 1;
            }
        }
        if (clause[i] == '~') {
            if (used[clause[i + 1] - 'a'] == 1) return false;
            else {
                used[clause[i + 1] - 'a'] = -1;
            }
            i++;
        }
    }
    return true;
}


int main() {
    int TC; cin >> TC;
    string str;
    while (TC--){
        cin >> str;
        int cont = 0;
        bool isTrue = false;
        while (cont < str.size()) {
            if (str[cont] == '(') {
                string clause;
                cont++;
                while (str[cont] != ')') {
                    clause += str[cont];
                    cont++;
                }
                if (checkClause(clause)) {
                    isTrue = true;
                    break;
                }
            }
            cont++;
        }
        if (isTrue) cout << "YES" << endl;
        else cout << "NO" << endl;
    }


}
