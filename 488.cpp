#include <iostream>

using namespace std;

int main() {
    int TC; cin >> TC;
    int a, b;
    while (TC--) {
        cin >> a >> b;
        for (int i = 0; i < b; i++) {
            //waves
            for (int j = 1; j <= a; j++) {
                for (int k =0 ; k < j; k++) {
                    cout << j;
                }
                cout << endl;
            }
            for (int j = a - 1; j >= 1; j--) {
                for (int k = 0; k < j; k++) {
                    cout << j;
                }
                cout << endl;
            }
            if (i != b - 1) cout << endl;
        }

        if (TC) cout << endl;
    }



}
