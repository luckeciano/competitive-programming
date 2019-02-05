#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main() {


    int N;
    scanf ("%d\n\n", &N);

    for (int i = 0; i < N; i ++) {
        int cards[52];
        int aux [52];
        for (int i = 0; i < 52; i++) {
            cards[i] = i;
            aux[i] = i;
        }
        int shuffles;

        scanf ("%d", &shuffles);
        int shuffleMat[100][52];
        for (int j = 0; j < shuffles; j++) {
            int shuffle;
            for (int k = 0; k < 52; k++) {
                cin >> shuffleMat[j][k];
            }
        }
        scanf ("\n");
        string shuffleCase;
        while (getline(cin, shuffleCase)) {
            if (shuffleCase.empty())
                break;

            int j = atoi(shuffleCase.c_str()) - 1;
            for (int k = 0; k < 52; k++) {
                cards[k] = aux[shuffleMat[j][k]- 1];
            }

            for (int k = 0; k < 52; k++) {
                aux[k] = cards[k];
            }

        }

        for (int k = 0; k < 52; k++) {
            int card = cards[k];
            string cardDesc;

            if (card/13 == 3) {
                cardDesc = "Spades";
            } else if (card/13 == 2) {
                cardDesc = "Hearts";
            } else if (card/13 == 1) {
                cardDesc = "Diamonds";
            } else if (card/13 == 0) {
                cardDesc = "Clubs";
            }

            if (card%13 == 12) {
                cardDesc = "Ace of " + cardDesc;
            }
            else if (card % 13 == 11) {
                cardDesc = "King of " + cardDesc;
            }
            else if (card % 13 == 10) {
                cardDesc = "Queen of " + cardDesc;
            }
            else if (card % 13 == 9) {
                cardDesc = "Jack of " + cardDesc;
            }
            else if (card % 13 == 8) {
                cardDesc = "10 of " + cardDesc;
            }
            else {
                string number;
                number = (char)(card%13 + 48 +2);
                cardDesc = number + " of " + cardDesc;
            }

            cout << cardDesc << endl;
        }
        if (i != N - 1) cout << endl;


    }
}
