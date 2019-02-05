#include <iostream>
#include <cstdlib>

using namespace std;

int main() {
    int N, B;
    cin >> N >> B;

    while (N!=0 && B!=0) {
        bool isPossible [100] = {false};
        int balls [100];
        for (int i = 0; i < B; i++) {
            int aux;
            cin >> aux;
            balls[i] = aux;
        }

        for (int i = 0; i < B; i++) {
            for (int j = i; j < B; j++) {
                int number = abs(balls[i] - balls[j]);
                //cout << number << " ";
                isPossible[number] = true;
            }
            //cout << endl;
        }
        bool possible = true;
        for (int i = 0; i < N + 1 && possible; i++) {
            if (!isPossible[i])
                possible = false;
        }

        if (possible) cout << "Y" << endl;
        else cout << "N" << endl;

        cin >> N >> B;
    }


}
