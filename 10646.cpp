#include <iostream>
#include <stack>
#include <string>
using namespace std;

int value(string card) {
    if (card[0] == 'A' || card[0] == 'K' || card[0] == 'Q' || card[0] == 'J' || card[0] == 'T')
        return 10;
    else return (card[0] - 48);

}


int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        stack<string> deck;
        for (int j = 0; j < 52; j++) {
            string aux;
            cin  >> aux;
            deck.push(aux);
        }
        stack<string> hand;
        for (int j = 0; j < 25; j++) {
            string aux;
            aux = deck.top();
            deck.pop();
            hand.push(aux);
        }
        int y  = 0;
        int x;
        for (int j = 0; j < 3; j++) {
            string topCard;
            topCard = deck.top();
            deck.pop();
            x = value(topCard);
            y += x;
            for (int t = 0; t < 10 - x; t++) {
                deck.pop();
            }
        }
        for (int j = 0; j < 25; j++) {
            string aux;
            aux = hand.top();
            hand.pop();
            deck.push(aux);
        }
        while (deck.size() != y) {
            deck.pop();
        }
        cout << "Case " << i+1 << ": " << deck.top() << endl;



    }



}
