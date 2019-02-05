#include <iostream>
#include <stack>
#include <string>
using namespace std;


int winner;
int playState;// non dealer's turn
int cardsToFace;
bool gameEnd;
bool faceCard;
stack<string> dealer;
stack<string> nonDealer;
stack<string> deck;

void setPlayState() {
	if (playState == 1)
		playState = 2;
	else playState = 1;
}

void makeTurn () {
	string cover;
	if (playState == 1) {
		if (dealer.empty())
		{
			gameEnd = true;
			winner = 2;
			return;
		}

		cover = dealer.top();
		dealer.pop();
		deck.push(cover);
	}
	else {
		if (nonDealer.empty())
		{
			gameEnd = true;
			winner = 1;
			return;
		}

		cover = nonDealer.top();
		nonDealer.pop();	
		deck.push(cover);

	}

	cardsToFace = 0;
	faceCard = false;

	if (cover[1] == 'J') {
		cardsToFace = 1;
		setPlayState();
		faceCard = true;
	}
	else if (cover[1] == 'Q') {
		cardsToFace = 2;
		setPlayState();

		faceCard = true;
	}
	else if (cover[1] == 'K') {
		cardsToFace = 3;
		setPlayState();
		faceCard = true;
	}
	else if (cover[1] = 'A') {
		cardsToFace = 4;
		setPlayState();
		faceCard = true;
	}

}

int main() {
	int state = 1;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 13; j++) {
			string card;
			cin >> card;
			if (state == 1) {
				nonDealer.push(card);
				state = 2;
			}
			else {
				dealer.push(card);
				state = 1;
			}
		}
	} 
	cardsToFace = 0;
	gameEnd = false;
	faceCard = false;
	playState = 2;
	while (!gameEnd) {			

		if (cardsToFace == 0) {
			cout << "Oi";
			makeTurn();
			if (!faceCard)
				setPlayState();
		}
		else {

			for (int i = 0; i < cardsToFace && !faceCard;  i++) {
				makeTurn();
			}

			stack<string> aux;
			while (!deck.empty()) {
				string card = deck.top();
				deck.pop();
				aux.push(card);
			}
			stack <string> aux2;
			if (playState == 1) {
				aux2 = nonDealer;
			} else aux2 = dealer;

			while (!aux2.empty()) {
				string card = aux2.top();
				aux2.pop();
				aux.push(card);
			}


			if (playState == 1) {
				nonDealer = aux;
			} else dealer = aux;
		}
	}

	if (winner == 1) {
		cout << "1 " << dealer.size() << endl;
	} else cout << "2 " << nonDealer.size() << endl;



}