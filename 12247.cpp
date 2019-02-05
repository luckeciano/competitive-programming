#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    vector<int> princess, prince;
    vector<bool> princessAux, princeAux;

    int firstCard;
    cin >> firstCard;
    while (firstCard != 0) {
        princess.push_back(firstCard);
        princessAux.push_back(false);
        for (int i = 0; i < 2; i++) {
            int aux;
            cin >> aux;
            princess.push_back(aux);
            princessAux.push_back(false);
        }
        for (int i = 0; i < 2;i++) {
            int aux;
            cin >> aux;
            prince.push_back(aux);
            princeAux.push_back(false);
        }

        sort(princess.begin(), princess.end());
        sort(prince.begin(), prince.end());
        int winPrincess = 0;
        int winPrince = 0;
        for (int i = prince.size() - 1; i >= 0 ;i--) {
            //the minimum cards in princess that wins from this card
            bool played = false;
            for (int j = 0; j< princess.size() && !played; j++) {
                if (prince[i] < princess[j] && !princessAux[j]) {
                    played = true;
                    winPrincess++;
                    princeAux[i] = true;
                    princessAux[j] = true;
                }
            }
            if (!played) {
                princeAux[i] = true;
                winPrince ++;
                for (int t = 0; t < princess.size() ; t++) {
                    if (!princessAux[t]) {
                        princessAux[t] = true;
                        break;
                    }
                }
            }
        }
        if (winPrincess == 2)
            cout << -1 << endl;
        else {
            //remaining card in princess

            int remainCard;
            for (int t = 0; t < princess.size(); t++) {
                if (!princessAux[t])
                    remainCard = princess[t];
            }
            bool getCard = false;
            int card = remainCard;
            if (winPrince == 2)
                card = 0;
            while (!getCard) {
                card ++;
                bool exists = false;
                for (int i = 0; i < prince.size() && !exists; i++) {
                    if (prince[i] == card)
                        exists = true;
                }
                for (int i = 0; i < princess.size() && !exists; i++) {
                    if (princess[i] == card)
                        exists = true;
                }
                if (!exists)
                    getCard = true;
            }
            if (card <= 52)
                cout << card << endl;
            else cout << -1 << endl;
        }

        cin >> firstCard;
        princess.clear(); princessAux.clear();
        prince.clear(); princeAux.clear();
    }





}
