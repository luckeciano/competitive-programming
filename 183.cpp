#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

void binToD(char B[][200],int a, int b,  int r, int c, string &result) {
    bool allZero = true;
    bool allOne = true;
    for (int i = a; i < r && (allZero || allOne); i++) {
        for (int j = b; j < c && (allZero || allOne); j++) {
            if (B[i][j] == '1') allZero = false;
            else allOne = false;
        }
    }
    if (allZero) {
        result.push_back('0');
    }
    else if (allOne) {
        result.push_back('1');
    }
    else {
        result.push_back('D');
        int newR = (a + r)/2;
        if ((a+r) % 2 != 0) newR++;
        int newC = (b + c)/2;
        if ((b+c) % 2 != 0) newC++;
        binToD (B, a , b, newR, newC, result);
        if (c - newC > 0) {
            binToD (B, a, newC, newR, c, result);
        }
        if (r - newR > 0 && newC - b > 0)
            binToD (B, newR, b, r, newC, result);
        if (r - newR > 0 && c - newC > 0)
            binToD (B, newR, newC, r, c, result);
    }



}

void dToBin (string D, int &p, int a, int b, int r, int c, int res[][205]) {
    if (D[p] == '0') {
        for (int i = a; i < r; i++) {
            for (int j = b; j < c; j++) {
                res[i][j] = 0;
            }
        }
        p++;
    } else if (D[p] == '1') {
        for (int i = a; i < r; i++) {
            for (int j = b; j < c; j++) {
                res[i][j] = 1;
            }
        }
        p++;
    } else {
        p++;
        int newR = (a+r)/2;
        if ((a+r) % 2 != 0) newR++;
        int newC = (b+c)/2;
        if ((b+c) % 2 != 0) newC++;
        dToBin (D, p, a , b, newR, newC, res);
        if (c - newC > 0)
            dToBin (D, p, a, newC, newR, c, res);
        if (r - newR > 0 && newC - b > 0)
            dToBin (D,p,  newR, b, r, newC, res);
        if (r - newR > 0 && c - newC > 0)
            dToBin (D, p, newR, newC, r, c, res);

    }


}

int main() {
    char B [200][200];
    string D;
    char symbol;
    string result = "";
    while (cin >> symbol, symbol != '#') {
        result.clear();
        int r, c;
        cin >> r >> c;
        if (symbol == 'B') {
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    cin >> B[i][j];
                }
            }

            binToD(B, 0, 0, r, c, result);
            printf ("D%4d%4d\n", r, c );
            int cont = 0;
            for (int i = 0; i < result.size(); i++) {
                cont++;
                cout << result[i];
                if (cont % 50 == 0) cout << endl;
            }
            if (cont % 50 != 0) cout << endl;
        } else {
            cin >> D;
            int res [205][205];
            int p = 0;
            for (int i = 0; i < r; i++)
                for (int j = 0; j < c; j++)
                res[i][j] = 3;
            dToBin(D, p, 0, 0, r, c, res);
            printf ("B%4d%4d\n", r, c);
            int cont = 0;
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    cont++;
                    cout << res[i][j];
                    if (cont % 50 == 0) cout << endl;
                }
            //cout << endl;

            }
            if (cont % 50 != 0) cout << endl;
        }
    }

}
