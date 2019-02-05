#include <iostream>
#include <vector>

using namespace std;

int cont = 0;


void compareWithGuess(vector<int> guessNumbers, int weak, int strong, vector<int> newTry) {
    int weakTry = 0;
    int strongTry = 0;
    vector<int> guessNumbersCopy = guessNumbers;
    vector<int> newTryCopy = newTry;

    for (int i = 0; i < guessNumbers.size(); i++) {
        if (guessNumbersCopy[i] == newTryCopy[i]) {
            strongTry++;
            guessNumbersCopy[i] = -1;
            newTryCopy[i] = -1;
        }
    }

    for (int i = 0; i < guessNumbers.size(); i++) {
        for (int j = 0; j < newTryCopy.size() && guessNumbersCopy[i] != -1; j++) {
            if (newTryCopy[j] == guessNumbersCopy[i]) {
                weakTry++;
                newTryCopy[j] = -1;
                guessNumbersCopy[i] = -1;
            }
        }
    }

    if (weak == weakTry && strong == strongTry) {
        cont ++;
    }

}

void testNewCode(vector<int> guessNumbers, int posit, int strong, int weak, vector<int> newTry) {

    if (posit == guessNumbers.size()) {
        //test code
        compareWithGuess (guessNumbers, weak, strong, newTry);
        return;
    }

    for (int i = 1; i <= 9 ; i++) {
        newTry[posit] = i;
        testNewCode (guessNumbers, posit + 1, strong, weak, newTry);
    }




}

void genCodes (vector<int> guessNumbers, int strong, int weak) {
    vector <int> newTry;
    for (int i = 0; i < guessNumbers.size() ; i++) {
        newTry.push_back(1);
    }
    for (int t = 1; t <= 9; t++) {
        newTry[0] = t;
        testNewCode(guessNumbers, 1, strong, weak, newTry);

    }
}


int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i ++) {
        cont = 0;
        string guess;
        cin >> guess;
        vector<int> guessNumbers;
        for (int j = 0; j < guess.size(); j++)
        {
            guessNumbers.push_back(guess[j] - 48);
        }
        int weak; int strong;
        cin >> strong;
        cin >> weak;

        genCodes(guessNumbers, strong, weak);
        cout << cont << endl;


    }


}
