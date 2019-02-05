#include <iostream>
#include <vector>

using namespace std;

int main() {
    int A, B;
    cin >> A;
    while (A != 0) {
        cin >> B;
        int layers[B];
        int initialLayer[B];
        int minW = 99999999;
        int minWIndex;
        for (int i = 0; i < B; i++) {
            int aux;
            cin >> aux;
            if (aux < minW) {
                minW = aux;
                minWIndex = i;
            }
            layers[i] = aux;
            initialLayer[i] = A;
        }
        int cont = 0;
        while (true) {
            bool turnedOn = false;
            for (int i = 0; i < B; i++) {
                if (layers[i] == initialLayer[i]) {
                    if (turnedOn) {
                        turnedOn = false;
                    }
                }
                else {
                    initialLayer[i]--;
                    if (!turnedOn) {
                        turnedOn = true;
                        cont++;
                    }
                }
            }
            if (initialLayer[minWIndex] == layers[minWIndex]) break;
        }
        cout << cont << endl;
        cin >> A;


    }


}
