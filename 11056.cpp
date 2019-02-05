#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;

struct player {
    string name;
    int minutes, seconds, mili;

};
bool compareDudes (player a, player b) {
    if (a.minutes != b.minutes)
        return a.minutes < b.minutes;
    else if (a.seconds != b.seconds)
        return a.seconds < b.seconds;
    else if (a.mili != b.mili)
        return a.mili < b.mili;
    else {
        string nameA = a.name;
        string nameB = b.name;
        transform (nameA.begin(), nameA.end(), nameA.begin(), ::tolower);
        transform (nameB.begin(), nameB.end(), nameB.begin(), ::tolower);
        return nameA < nameB;
    }

}
int main() {
    vector<player> dudes;
    string aux;
    int N;
    while (cin >> N) {
        dudes.clear();
        for (int i = 0; i < N; i++) {
            player dude;
            cin >> dude.name >> aux >> dude.minutes >> aux >> dude.seconds >> aux >> dude.mili >> aux;
            //  cout <<  dude.name << aux << dude.minutes << aux << dude.seconds << aux << dude.mili << endl;

            //scanf (": %d min %d sec %d ms", &dude.minutes, &dude.seconds, &dude.mili);
            dudes.push_back(dude);
        }
        sort(dudes.begin(), dudes.end(), compareDudes);
        int R = 1;
        for (int i = 0; i < dudes.size(); i++) {
            if (i%2 == 0) {
                cout << "Row " << R << endl;
                R++;
            }
            cout << dudes[i].name << endl;
        }
        cout << endl;
    }


}
