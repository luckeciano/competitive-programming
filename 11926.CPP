#include <bitset>
#include <iostream>

using namespace std;

int main() {
    int n, m;
    while (cin >> n >> m, n || m) {
        bitset<1000001> bs;
        bool ovl = false;
        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            if (!ovl) {

                for (int j = a; j < b && !ovl; j++) {
                    if (!bs[j]) {
                        bs[j] = 1;
                    }
                    else ovl = true;
                }
            }

        }
        for (int i = 0; i < m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            if (!ovl) {
                for (int cont = 0; cont + b <= 1000000 && !ovl; cont += c) {
                    for (int j = a + cont; j < cont + b && !ovl; j++) {
                        if (!bs[j]) {
                           bs[j] = 1;
                        }
                        else ovl = true;
                    }
                }
            }
        }

        if (!ovl) cout << "NO CONFLICT" << endl;
        else cout << "CONFLICT" << endl;
    }


}
