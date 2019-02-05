#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    while(N--) {
        int mat [3][3];
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++) {
                char aux;
                cin >> aux;
                mat[i][j] = int(aux - '0');
            }
        }
        int cont = -1;
        while (true) {

            bool isZero = true;
            for (int i = 0; i < 3 && isZero; i++) {
                for (int j = 0; j < 3 && isZero; j++) {
                    if (mat[i][j] != 0)
                        isZero = false;
                }
            }
            if (isZero) break;

            int matR [3][3];
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int sum = 0;
                    if (i - 1 >= 0)
                        sum += mat[i-1][j];
                    if (i + 1 < 3)
                        sum += mat[i+1][j];
                    if (j - 1 >= 0)
                        sum += mat[i][j-1];
                    if (j + 1 < 3)
                        sum += mat[i][j+1];

                    matR[i][j] = sum%2;
                }
            }

            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    mat[i][j] = matR[i][j];
                }
            }
            cont ++;
        }
        cout << cont << endl;

    }


}
