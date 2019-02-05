#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    while (N != 0) {
        int folhas = N/4;
        if (N%4 > 0) folhas++;
        int p1, p2, p3, p4;
        p1 = 4*folhas;
        p2 = 1;
        p3 = 2;
        p4 = 4*folhas - 1;
        cout << "Printing order for " << N << " pages:" << endl;
        for (int i = 0; i < folhas; i++) {
            if (p1 > N)
                cout << "Sheet " << i + 1 << ", front: " << "Blank, " << p2 << endl;
            else cout << "Sheet " << i + 1 << ", front: " << p1 << ", " << p2 << endl;

            if (N > 1) {
                if (p4 > N)
                    cout << "Sheet " << i + 1 << ", back : " << p3 << ", Blank" << endl;
                else cout << "Sheet " << i + 1 << ", back : " << p3 << ", " << p4 << endl;
            }

            p1 -= 2;
            p2 += 2;
            p3 += 2;
            p4 -= 2;
        }
        cin >> N;
    }


}
