#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    int secret[1000];
    int guess [1000];
    int secretOr[1000];
    int cont = 1;
    while (N!=0) {
        cout << "Game " << cont << ":" << endl;
        for (int i = 0; i  < N; i++) {
            cin >> secret[i];
            secretOr[i] = secret[i];
        }
        for (int i = 0; i < N; i++) {
            cin >> guess[i];
        }
        while (guess[0] != 0) {
            int strong = 0;
            int weak = 0;
            //calculo de perfect matches
            for (int i = 0; i < N; i++) {
                if (secret[i] == guess[i]) {
                    strong++;
                    secret[i] = -1;
                    guess[i] = -1;
                }
            }
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N && guess[i] > 0; j++) {
                    if (guess[i] == secret[j]) {
                        weak ++;
                        secret[j] = -1;
                        guess[i] = -1;
                    }
                }
            }

            cout << "    (" << strong << "," << weak << ")" << endl;

            for (int i = 0; i < N; i++) {
                cin >> guess[i];
                secret[i] = secretOr[i];
            }

        }

        cin >> N;
        cont ++;

    }


}
