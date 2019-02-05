#include <iostream>
#include <vector>

using namespace std;

int points (vector<char> rolls, int cont) {
    if (rolls[cont] == 'X')
        return 10;
    if (rolls[cont] == '/')
        return 10 - int(rolls[cont-1] - 48);
    else return int (rolls[cont] - 48);

}

int main() {
    string s;
    cin >> s;
    while (s != "Game") {
        char x;
        vector<char> rolls;
        rolls.push_back(s[0]);
        while ((cin.peek() != '\n') && (cin >> x)) {
            if (x != ' ')
                rolls.push_back(x);
        }
        //cout << rolls.size() << endl;
        int score = 0;
        int frame = 1;
        int roll = 1;
        for (int i = 0; i < rolls.size(); i++) {
            if (rolls[i] == 'X') {
                frame ++;
                roll = 1;
                score += 10;
                //cout << "roll: " << 10 << endl;
                if (frame <= 10) {
                    score += points(rolls, i+1);

                    //cout << "roll bonus: " <<  points (rolls, i+1) << endl;
                    score += points(rolls, i+2);

                    //cout << "roll bonus: " <<  points (rolls, i+2) << endl;

                }
            }

            else if (rolls[i] == '/') {
                frame ++;
                roll = 1;
                score += 10 - int(rolls[i-1] - 48);
                //cout << "roll: " << 10 - int(rolls[i-1] - 48) << endl;
                if (frame <= 10) {
                    score += points(rolls, i+1);
                   // cout << "roll bonus: " <<  points (rolls, i+1) << endl;
                }
            }
            else {
                roll ++;
                if (roll == 3) {
                    roll = 1;
                    frame++;
                }
                score += int (rolls[i] - 48);
                //cout << "roll: " << int (rolls[i] - 48) << endl;
            }

        }
        cout << score << endl;
        cin >> s;
    }

}
