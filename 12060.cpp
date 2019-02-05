#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int getDigits (int i) {
    return i > 0 ? (int) log10((double)i) + 1 : 1;
}


int main() {
    int N;
    cin >> N;
    int cont = 0;
    while (N != 0) {
        cont++;
        int sum = 0;
        for (int i = 0; i < N; i++) {
            int aux;
            cin >> aux;
            sum += aux;
        }
        bool isNeg = false;
        if (sum < 0) {
            sum = - sum;
            isNeg = true;
        }
        int integer = sum/N;
        int num = sum%N;
        int den = N;
        for (int i = 2; i <= den; i++) {
            while (num%i == 0 && den%i == 0) {
                num = num/i;
                den = den/i;
            }

        }
        int numberOfDigits = getDigits(den);
        int digitsInt = getDigits(integer);
        cout << "Case " << cont << ":" << endl;

        if (num == 0) {
            if (isNeg)
                cout << "- ";
            cout << integer << endl;
        }
        else if (integer == 0) {
            if (isNeg) {
                cout << setw(numberOfDigits + 2) << num << endl;
                cout << "- ";
            } else
                cout << setw(numberOfDigits) << num << endl;
            for (int k = 0; k < numberOfDigits; k++)
                cout << "-";
            cout << endl;
            if (isNeg) {
                cout << setw(numberOfDigits + 2) << den << endl;
            } else
                cout << setw(numberOfDigits) << den << endl;
        }
        else {
            if (isNeg) {
                    cout << setw(digitsInt + numberOfDigits + 2) << num << endl;
                    cout << "- ";
            } else
                cout << setw(digitsInt + numberOfDigits) << num << endl;
            cout << integer;
            for (int k = 0; k < numberOfDigits; k++)
                cout << "-";
            cout << endl;
            if (isNeg) {
                cout << setw(digitsInt + numberOfDigits + 2) << den << endl;
            } else
                cout << setw(digitsInt + numberOfDigits) << den << endl;
        }




        cin >> N;
    }



}
