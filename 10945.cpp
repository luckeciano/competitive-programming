#include <iostream>

using namespace std;

int main () {
    string aux;
    cin >> aux;
    while (aux != "DONE") {
        string s = "";
        for (int i = 0; i < aux.size(); i++) {
            if ((aux[i] >= 'a' && aux[i] <= 'z') || (aux[i] >= 'A' && aux[i] <= 'Z'))
                s += tolower(aux[i]);
        }
        while ((cin.peek()!='\n') && (cin >> aux)) {
            for (int i = 0; i < aux.size(); i++) {
                if ((aux[i] >= 'a' && aux[i] <= 'z') || (aux[i] >= 'A' && aux[i] <= 'Z'))
                    s += tolower(aux[i]);
            }
        }
        bool pal = true;
        for (int i = 0; i < s.size()/2; i++) {
            if (!(s[i] == s[s.size()-i-1]))
                pal = false;
        }
        if (pal) cout << "You won't be eaten!" << endl;
        else cout << "Uh oh.." << endl;

        cin >> aux;

    }





}
