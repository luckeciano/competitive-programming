#include <iostream>

using namespace std;

bool isNewGuess (string guess, int i) {
    for (int t = 0; t < i; t++) {
        if (guess[t] == guess [i])
            return false;
    }
    return true;

}

int main () {
    int N;
    cin >> N;
    string secret;
    string guess;
    while (N != -1) {
        cout << "Round " << N << endl;
        cin >> secret;
        cin >> guess;
        bool isStroke;
        int stroke = 0;
        int discovered = 0;
        bool finished = false;
        for (int i = 0; i < guess.size() && !finished; i++) {

            isStroke = true;
            if (isNewGuess(guess, i)) {
                for (int j = 0; j < secret.size(); j++) {
                    if (guess[i] == secret[j]) {
                        discovered++;
                        isStroke = false;
                    }
                }
                if (isStroke) stroke++;

                if (discovered == secret.size()) {
                  cout << "You win." << endl;
                    finished = true;
                 }

                 if (stroke == 7) {
                    cout << "You lose." << endl;
                    finished = true;
                 }
            }
        }
        if (!finished) cout << "You chickened out." << endl;
        cin >> N;


    }



}
