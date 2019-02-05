#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void checkSnake (vector<int> &players, int num, vector<pair<int, int> > sLs) {
        for (int k = 0; k < sLs.size(); k++) {
            if (players[num] == sLs[k].first) {
                players[num] = sLs[k].second;
                break;
            }
        }
}


int main() {
    int N;
    cin >> N;

    for (int i = 0; i < N; i++) {
        vector<int> players;
        int a, b, c;
        cin >> a >> b >> c;
        vector<pair<int, int> > sLs;
        for (int j = 0; j < a; j++) {
            players.push_back(1);
        }
        for (int j = 0; j < b; j++) {
            int prevS, postS;
            cin >> prevS >> postS;
            //cout << prevS << " " << postS << endl;
            sLs.push_back(make_pair(prevS, postS));
        }
        bool isEnded = false;
        for (int j = 0; j < c; j++) {
            int aux;
            cin >> aux;
            if (!isEnded) {
                players[j%a] += aux;
                checkSnake(players, j%a, sLs);
                if (players[j%a] >= 100) {
                    players[j%a] = 100;
                    isEnded = true;
                }

            }
        }

        for (int k = 0; k < a; k++) {
            cout << "Position of player " << k + 1 << " is " << players[k] << "." <<  endl;
        }


    }



}
