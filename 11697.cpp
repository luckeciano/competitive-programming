#include <iostream>
#include <cstdio>
using namespace std;
char grid[7][7];
string applyRules (string aux) {

    int firstR, firstC, secondR, secondC;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (aux[0] == grid[i][j]) {
                firstR = i; firstC = j;
            }
            if (aux[1] == grid[i][j]) {
                secondR = i; secondC = j;
            }
        }
    }

    if (firstR == secondR) {

        firstC = (firstC + 1)%5;
        secondC = (secondC + 1)%5;
    }
    else if (firstC == secondC) {
        firstR = (firstR + 1)%5;
        secondR = (secondR + 1)%5;
    }
    else {
        int a = firstC;
        firstC = secondC;
        secondC = a;
    }
    string res;
    char c = toupper(grid[firstR][firstC]);
    res += c;
    c = toupper(grid[secondR][secondC]);
    res += c;

    return res;
}

int main() {
    int TC; cin >> TC;
    int used[30];
    string input, order, res, aux;

    while (TC--) {
        input.clear(); order.clear();
        res.clear(); aux.clear();
        for (int i = 0; i < 30; i++) {
            used [i] = 0;
        }
        used ['q' - 'a'] = 1;
        scanf ("\n");
        getline(cin, input);
        for (int i = 0; i < input.size(); i++) {
            if (input[i] >= 'a' && input[i] <= 'z') {
                if (used[input[i] - 'a'] == 0) {
                    order.push_back(input[i]);
                    used[input[i] - 'a'] = 1;
                }
            }
        }
        for (int i = 0; i < 26; i++) {
            if (used[i] == 0) {
                order.push_back(char(i + 'a'));
                used[i] = 1;
            }
        }
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                grid[i][j] = order[5*i + j];
            }
        }
        getline(cin, input);
        int cont = 0;
        for (int i = 0; i < input.size(); i++) {
            if (input[i] != ' ') {
                cont++;
                aux.push_back(input[i]);

                if (cont == 2) {
                    if (aux[0] == aux[1]) {
                        char letter = aux[0];
                        aux[1] = 'x';
                        res += applyRules(aux);
                        aux.clear(); aux.push_back(letter);
                        cont = 1;
                    } else {
                        res += applyRules(aux);
                        cont = 0;
                        aux.clear();
                    }
                }
            }

        }
        if (cont == 1) {
            res += applyRules (aux + 'x');
        }
        cout << res << endl;

    }


}
