#include <iostream>

using namespace std;

int main() {
    int A, B;
    cin >> A;
    int layers [10010];
    while (A != 0) {
        cin >> B;
        int cont = 0;
        cin >> layers[0];
        cont += A - layers[0];
        for (int i  = 1; i < B; i++) {
            cin >> layers[i];
            int temp = layers[i - 1] - layers[i];

            if (temp > 0)
                cont += temp;
        }
        cout << cont << endl;
        cin >> A;
    }


}
