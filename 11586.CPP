#include <iostream>

using namespace std;

int main() {
    int L;
    cin >> L;
    string aux;
    getline(cin, aux);

    for (int i = 0; i < L; i++) {
        string track;
        int M = 0;
        int F = 0;
        getline(cin, track);
        for (int k = 0; k < track.size(); k++) {
            if (track[k] == 'M') M++;
            else if (track[k] == 'F') F++;
        }

        if (F == 1 && M == 1) cout << "NO LOOP" << endl;
        else {
            if (M != F) cout << "NO LOOP" << endl;
            else cout << "LOOP" << endl;
        }

    }


}
