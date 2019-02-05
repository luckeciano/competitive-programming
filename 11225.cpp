#include <iostream>

using namespace std;

int main () {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        if (i != 0)
            cout << endl;
        int cards;
        cin >> cards;
        int midPoints = 0;
        int need = 0;
        for (int i = 0; i < cards; i++) {
            string card;
            cin >> card;
            string aux;
            if (card == "fool") {
                need++;
                midPoints += 9;
            }
            else if (card == "king"){
                midPoints +=9;
                cin >> aux;
                cin>> aux;
            }
            else if (card == "queen") {
                midPoints +=7;
                cin >> aux;
                cin >> aux;
            }
            else if (card == "knight") {
                midPoints +=5;
                cin >> aux;
                cin >> aux;
            }

            else if (card == "jack") {
                midPoints +=3;
                cin >> aux;
                cin >> aux;
            }
            else if (card == "one" || card == "twenty-one") {

                cin >> aux;
                cin >> aux;
                if (aux == "trumps") {
                    need++;
                    midPoints += 9;
                }
            }
            else {
                midPoints += 1;
                cin >> aux;
                cin >> aux;
            }
        }
        int pointsNeeded;
        if (need == 0) pointsNeeded = 56;
        else if (need == 1) pointsNeeded = 51;
        else if (need == 2) pointsNeeded = 41;
        else if (need == 3) pointsNeeded = 36;

        cout << "Hand #" << i+1 << endl;
        float x = 0.5*midPoints - 1.0*pointsNeeded;
         if (x >= 0 ) {
            cout << "Game won by " << x << " point(s)." << endl;
        }
        else cout << "Game lost by " << -x << " point(s)." << endl;


    }


}
