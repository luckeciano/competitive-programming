#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;
    bool tries[10];
    for (int i = 0; i < 10; i++) {
        tries[i] = true;
    }

    while (N != 0) {
        string caseS[2];
        cin >> caseS[0];
        cin >> caseS[1];
        if (caseS[1] == "high") {
            for (int i = N - 1; i < 10; i++) {
                tries[i] = false;
            }
        }
        else if (caseS[1] == "low") {
            for (int i = N - 1; i >= 0; i--) {
                tries[i] = false;
            }
        }

        if (caseS[1] == "on") {
            if (tries[N - 1] == true)
                cout << "Stan may be honest" << endl;
            else cout << "Stan is dishonest" << endl;

            for (int i = 0; i < 10; i++) {
                tries[i] = true;
            }
        }
        cin >> N;
    }



}
