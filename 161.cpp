#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main () {

    vector<int> traffics;
    int x;
    cin >> x;
    while (x != 0) {
        int minPeriod = x;
        while (x != 0) {
            traffics.push_back(x);
            if (minPeriod > x) minPeriod = x;
            cin >> x;
        }
        vector<int> currT;
        for (int i = 0; i < traffics.size(); i++) {
            currT.push_back(1);
        }
        int time;
        bool getResult = false;
        for (int i = 1; i <= 5 * 3600; i++) {
            int sum = 0;
            for (int j = 0; j < traffics.size(); j++) {
                int period = traffics[j];
                if (i%period == 0) {
                    if (currT[j] == 2) currT[j] = 3;
                    else if (currT[j] == 3) currT[j] = 1;
                }
                else if (i%period == period - 5 && currT[j] == 1)
                    currT[j] = 2;
                sum += currT[j];
            }
            if (sum == traffics.size() && i > minPeriod - 5){
                    time = i;
                    getResult = true;
                    break;
            }
        }
        if (!getResult) cout << "Signals fail to synchronise in 5 hours" << endl;
        else {
            int minutes, seconds, hours;
            minutes = time / 60;
            seconds = time % 60;
            hours = minutes/60;
            minutes = minutes%60;
            //cout << time << endl;
            cout << setfill('0') << setw(2) << hours << ":";
            cout << setfill ('0') << setw(2) << minutes << ":";
            cout << setfill ('0') << setw(2) << seconds << endl;
        }

        cin >> x;
        traffics.clear();
    }




}
