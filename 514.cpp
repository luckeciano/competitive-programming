#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main () {
    int N;
    cin >> N;
    while (N != 0) {
       while (true) {
            bool isOver = false;
            vector<int> stC;
            stack<int> station;
            for (int i = 0; i < N; i++) {
                stC.push_back(0);
            }
            bool problem = false;
            for (int i = 0; i < N; i++) {
                int coach;
                cin >> coach;
                if (coach == 0) {
                    isOver = true;
                    break;
                }
                if (!problem) {
                    if (stC[coach - 1] == 0) {
                        for (int j = 0; j < coach; j++) {
                            if (stC[j] == 0) {
                                stC[j] = 1;
                                station.push(j + 1);
                            }
                        }
                        station.pop();
                        stC[coach - 1] = 2;
                    } else if (stC[coach - 1] == 1) {
                        if (!station.empty() && station.top() == coach) {
                            station.pop();
                            stC[coach - 1] = 2;
                        }
                        else problem = true;
                    } else if (stC[coach - 1] == 2) {
                        problem = true;
                    }
                }
            }
            if (isOver) break;
            if (problem) cout << "No" << endl;
            else cout << "Yes" << endl;

       }
       cin >> N;
        cout << endl;
    }



}
