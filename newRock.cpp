#include <iostream>
#include <vector>

using namespace std;



int main() {
    int t;
    cin >> t;

    while (t--) {
        char terr[101][101];
        int r, c, n;
        cin >> r >> c >> n;
        for (int i = 0; i < r; i ++) {
            for (int j = 0; j < c; j++) {
                cin >> terr[i][j];
            }
        }

        char finalBoard[101][101];
        while (n--) {
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    char result = terr[i][j];

                    if (terr[i][j] == 'R') {
                        if (i - 1 >= 0 )
                            if (terr[i-1][j] == 'P')
                                result = 'P';
                        if (i + 1 < r)
                            if (terr[i+1][j] == 'P')
                                result = 'P';
                        if (j - 1 >= 0)
                            if (terr[i][j - 1] == 'P')
                                result = 'P';
                        if (j + 1 < c)
                            if (terr[i][j+1] == 'P')
                                result = 'P';
                    }

                    else if (terr[i][j] == 'P') {
                        if (i - 1 >= 0)
                            if (terr[i-1][j] == 'S')
                                result = 'S';
                        if (i + 1 < r)
                            if (terr[i+1][j] == 'S')
                                result = 'S';
                        if (j - 1 >= 0)
                            if (terr[i][j - 1] == 'S')
                                result = 'S';
                        if (j + 1 < c)
                            if (terr[i][j+1] == 'S')
                                result = 'S';
                    }

                    else if (terr[i][j] == 'S') {
                        if (i - 1 >= 0)
                            if (terr[i-1][j] == 'R')
                                result = 'R';
                        if (i + 1 < r)
                            if (terr[i+1][j] == 'R')
                               result = 'R';
                        if (j - 1 >= 0)
                            if (terr[i][j - 1] == 'R')
                                result = 'R';
                        if (j + 1 < c)
                            if (terr[i][j+1] == 'R')
                                result = 'R';
                    }

                    finalBoard[i][j] = result;
                }
            }


            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    terr[i][j] = finalBoard[i][j];
                }
            }

           /* cout << "Parcial: ";
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    cout << terr[i][j];
                }
                cout << endl;
            }*/

        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
               cout << terr[i][j];
            }
            cout << endl;

        }
        if (t != 0) cout << endl;


    }

    return 0;


}

