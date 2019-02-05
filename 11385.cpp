#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int fibon[110];
int Fib (int u) {
    if (fibon[u] != -1) return fibon[u];

    return fibon[u] = Fib(u - 1) + Fib(u - 2);

}

int main() {
    memset(fibon, -1, sizeof fibon);
    fibon [1] = 1;
    fibon [2] = 2;
    Fib(46);
    int numberos[105];
    int T; cin >> T;
    while (T--) {
        int num; cin >> num;
        int len = 0;
        for (int i = 0; i < num; i++) {
            cin >> numberos[i];
            len = max(len, numberos[i]);
        }
        for (int i = 0; i < 46; i++) {
            if (len == fibon[i]) {
                len = i; break;
            }
        }
        scanf("\n");
        string input;
        getline (cin, input);
        string res(len, ' ');
        string aux;
        for (int i = 0; i < input.size(); i++) {
            if (input[i] >= 'A' && input[i] <= 'Z')
                aux.push_back(input[i]);
        }
        input = aux;
        int letter = -1;
        for (int i = 0; i < num; i++) {
            for (int j =0 ; j < 46; j++) {
                if (numberos[i] == fibon[j]) {
                    res[j - 1] = input[i];
                }
            }
        }

        cout << res << endl;

    }


}
