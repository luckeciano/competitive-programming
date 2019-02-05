#include <iostream>

using namespace std;

int main() {
    int TC; cin >> TC;
    string steps, str, aux, rep; bool solution;
    while (TC--) {
        steps.clear(); str.clear(); aux.clear(); rep.clear();
        cin >> str;
        for (int k = 1; k <= str.size(); k++) {
            aux = str.substr(0, k);
            solution = true;
            int cont = 0;
            for (int i = 0; i < str.size() && solution; i += aux.size()) {
                rep = str.substr(i, aux.size());
                if (rep.size() != aux.size()) break;
                if (rep != aux) solution = false;
                else cont++;
            }

            if (solution && cont == 2) {
                steps = aux;
                break;
            }
        }
        int startsIn = str.size()%steps.size();
        for (int i = 0; i < 8; i++) {
            cout << steps[(startsIn + i)%steps.size()];
        }
        cout << "..." << endl;
    }

}
