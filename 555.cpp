#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>


using namespace std;

int main() {
    int hands[4][13]; //0 = S  1 = W 2 = N 3 = E
    char dealer;
    cin >> dealer;
    while (dealer != '#') {
        int player;
        if (dealer == 'S')
            player = 0;
        else if (dealer == 'W')
            player = 1;
        else if (dealer == 'N')
            player = 2;
        else if (dealer == 'E')
            player = 3;
        for (int i = 0; i < 13; i++) {
            for (int j = 0; j < 4; j++) {
                int cont = (player + j + 1)%4;
                char suit;
                cin >> suit;
                int points = 0;
                if (suit == 'C')
                    points += 0;
                else if (suit == 'D')
                    points += 13;
                else if (suit == 'S')
                    points += 26;
                else if (suit == 'H')
                    points += 39;

                char value;

                cin >> value;
                if (value == 'A')
                    points += 12;
                else if (value == 'K')
                    points += 11;
                else if (value == 'Q')
                    points += 10;
                else if (value == 'J')
                    points += 9;
                else if (value == 'T')
                    points += 8;
                else
                    points += value - 50;

                hands[cont][i] = points;
            }

        }

        sort(hands[0], hands[0] + 13);
        sort(hands[1], hands[1] + 13);
        sort(hands[2], hands[2] + 13);
        sort(hands[3], hands[3] + 13);

        vector<string> print = {"S:", "W:", "N:", "E:"};
        for (int t = 0; t < 4; t++) {
            cout << print[t];
            for (int i = 0; i < 13; i++) {
                printf (" ");
                int pts = hands[t][i];
                char suit;
                char value;
                if (pts/13 == 0)
                    suit = 'C';
                else if (pts/13 == 1)
                    suit = 'D';
                else if (pts/13 == 2)
                    suit = 'S';
                else if (pts/13 == 3)
                    suit = 'H';

                if (pts%13 == 12)
                    value = 'A';
                else if (pts%13 == 11)
                    value = 'K';
                else if (pts%13 == 10)
                    value = 'Q';
                else if (pts%13 == 9)
                    value = 'J';
                else if (pts%13 == 8)
                    value = 'T';
                else value = (50 + pts%13);
                printf ("%c%c", suit, value);

            }
            printf ("\n");
        }
        cin >> dealer;
    }




}
