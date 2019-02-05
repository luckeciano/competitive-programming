#include <iostream>
#include <queue>
#include<string>
#include <map>

using namespace std;

int main() {
    int test;
    cin >> test;
    while (test--) {

        int n, t, m;
        cin >> n >> t >> m;
        queue <pair <int, int> > carsL;
        queue <pair <int, int> > carsR;
        map<int, int> toPrint;
        for (int i = 0; i < m; i++) {
            int time; string side;
            cin >> time >> side;
            if (side == "left")
                carsL.push(make_pair(time, i));
            else if (side == "right")
                carsR.push(make_pair(time, i));
        }
        int T = 0;
        int ferrySide = 0; // 0 - left
        int capacity = 0;
        bool hasCarInThisSide = false;
        int it = 0;
        while (!(carsL.empty() && carsR.empty())) {
            //cout << carsL.size() << " " << carsR.size() << " ~" << T <<  endl;
            //cout << ferrySide << endl;
           // cout << "sizes>" << carsL.size() << " " << carsR.size() << endl;
            capacity = 0;
            hasCarInThisSide = false;
            if (ferrySide == 0) {
                while (!carsL.empty() && T >= carsL.front().first && capacity < n ) {
                    toPrint[carsL.front().second] = T+t;
                    carsL.pop();
                    capacity++;
                    ferrySide = 1;
                    hasCarInThisSide = true;
                }

                if (hasCarInThisSide) T += t;
                else {
                    if (!carsR.empty() && T >= carsR.front().first && capacity < n) {
                        ferrySide = 0;
                        hasCarInThisSide = true;
                        T += t;
                        while (!carsR.empty() && T >= carsR.front().first && capacity < n) {
                            toPrint[carsR.front().second] = T+t;
                            carsR.pop();
                            capacity++;
                        }

                    }

                    if (hasCarInThisSide) T += t;
                    else  {
                        if (!carsL.empty() && carsR.empty()) T = carsL.front().first;
                        else if (carsL.empty() && !carsR.empty()) {
                                T = carsR.front().first + t;
                                ferrySide = 1;
                        }
                        else if (carsL.front().first <= carsR.front().first) T = carsL.front().first;
                        else if (carsL.front().first > carsR.front().first){
                            T = carsR.front().first + t;
                            ferrySide = 1;
                        }
                    }
                }

            }
            else {

                 while (!carsR.empty() && T >= carsR.front().first && capacity < n ) {
                    toPrint[carsR.front().second] = T+t;
                    carsR.pop();
                    ferrySide = 0;
                    capacity++;
                    hasCarInThisSide = true;
                }

                if (hasCarInThisSide) T += t;
                else {
                    if (!carsL.empty() && T >= carsL.front().first && capacity < n) {
                        ferrySide = 1;
                        hasCarInThisSide = true;
                        T += t;
                        while (!carsL.empty() && T >= carsL.front().first && capacity < n) {
                            toPrint[carsL.front().second] = T+t;
                            carsL.pop();
                            capacity++;
                        }
                    }

                    if (hasCarInThisSide) T += t;
                    else  {
                        if (!carsR.empty() && carsL.empty()) T = carsR.front().first;
                        else if (carsR.empty() && !carsL.empty()) {
                                T = carsL.front().first + t;
                                ferrySide = 0;
                        }
                        else if (carsR.front().first <= carsL.front().first) T = carsR.front().first;
                        else if (carsR.front().first > carsL.front().first){
                            T = carsL.front().first + t;
                            ferrySide = 0;
                        }

                    }
                }
            }
        }
        for (int i = 0; i < m; i++) {
            cout << toPrint[i] << endl;
        }
        if (test != 0) cout << endl;



    }


}
