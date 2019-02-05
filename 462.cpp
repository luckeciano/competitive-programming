#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <string>

using namespace std;

int main() {

    char inputChar[3];
    while (scanf("%s", &inputChar) == 1) {
        map<char, vector<int> > suit;
        char rankNum = inputChar[0];
        if (rankNum == 'A')
            suit[inputChar[1]].push_back(4);
        else if (rankNum == 'K')
            suit[inputChar[1]].push_back(3);
        else if (rankNum == 'Q')
            suit[inputChar[1]].push_back(2);
        else if (rankNum == 'J')
            suit[inputChar[1]].push_back(1);
        else
            suit[inputChar[1]].push_back(0);

        for (int i = 0; i < 12 ; i++) {
            scanf("%s", &inputChar);
            char rankNum = inputChar[0];
            if (rankNum == 'A')
                suit[inputChar[1]].push_back(4);
            else if (rankNum == 'K')
                suit[inputChar[1]].push_back(3);
            else if (rankNum == 'Q')
                suit[inputChar[1]].push_back(2);
            else if (rankNum == 'J')
                suit[inputChar[1]].push_back(1);
            else
                suit[inputChar[1]].push_back(0);

        }
        //check all suits for punctuation
        int points = 0;
        int noTrump = 0;
        vector<bool> stopped;
        vector<char> suitChars = {'S', 'H', 'D','C'};
        for (int k = 0; k < suitChars.size(); k++) {
            char j = suitChars[k];
            stopped.push_back(false);
            for (int i = 0; i < suit[j].size(); i++) {
                points += suit[j][i]; noTrump += suit[j][i];

                if (suit[j][i] == 4) stopped[k] = true;
                else if (suit[j][i] == 3) {
                        if (suit[j].size() == 1) {
                            points--;
                            noTrump --;
                        }
                        if (suit[j].size() >= 2)
                            stopped[k] = true;
                }
                 else if (suit[j][i] == 2) {
                        if (suit[j].size() == 1 || suit[j].size() == 2) {
                            points--;
                            noTrump --;
                        }

                        if (suit[j].size() >= 3)
                            stopped[k] = true;
                }
                else  if (suit[j][i] == 1 && (suit[j].size() == 1 || suit[j].size() == 2 || suit[j].size() == 3)) {
                    points--;
                    noTrump --;
                }

            }
            if (suit[j].size() == 2) points ++;
            if (suit[j].size() == 1) points += 2;
            if (suit[j].size() == 0) points += 2;
        }
        bool allStopped = false;
        if (stopped[0] && stopped[1] && stopped[2] && stopped[3])
            allStopped = true;
        if (points < 14) cout << "PASS" << endl;
        else {
            if (noTrump >= 16 && allStopped) cout << "BID NO-TRUMP" << endl;
            else {
                    vector<pair <int, char> > SHDC;
                    SHDC.push_back(make_pair(suit['S'].size(), 'S'));
                    SHDC.push_back(make_pair(suit['H'].size(), 'H'));
                    SHDC.push_back(make_pair(suit['D'].size(), 'D'));
                    SHDC.push_back(make_pair(suit['C'].size(), 'C'));
                    char SHDCMax = 'S';
                    int SHDCMaxSize = suit['S'].size();
                    for (int i = 0; i < 4; i++) {
                        if (SHDC[i].first > SHDCMaxSize) {
                            SHDCMaxSize = SHDC[i].first;
                            SHDCMax = SHDC[i].second;
                        }
                    }

                    cout << "BID " << SHDCMax << endl;
            }
        }
    }

}
