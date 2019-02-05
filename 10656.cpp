#include <iostream>

using namespace std;

int main() {
    int N;
    while (cin >> N, N) {
        int num;
        int sum = 0;
        bool first = true;
        for (int i = 0; i < N; i++) {
            cin >> num;
            sum += num;
            if (num > 0) {
                if (first) first = false;
                else cout << " ";
                cout << num;
            }
        }
        if (sum == 0) cout << 0 << endl;
        else cout << endl;
    }


}
