#include <iostream>
#include <cmath>

using namespace std;

int main () {
    int N;
    cin >> N;
    while (N!=0) {
        int num = 1;
        bool isA = true;
        int a = 0; int b = 0;
        for (int i = 0; i <= log2(N); i++) {
//            cout << N&num << endl;
            if (int(N&num) == num) {
                if (isA) {
                    a += num;
                    isA = !isA;
                } else  {
                    b += num;
                    isA = !isA;
                }
            }
            num *= 2;
        }
        cout << a << " " << b << endl;

        cin >> N;
    }



}
