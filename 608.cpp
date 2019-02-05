#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        vector <int> w;
        for (int t = 0; t < 12; t++)
            w.push_back(0);
        string r, l, f;

        for (int k = 0; k < 3; k ++) {
            cin >> l >> r >> f;
            bool markedThisTime [12] = {false};
            if (f == "even") {
                for (int j = 0; j < r.size(); j++) {
                    int num = int (r[j] - 'A');
                    w[num] = 1;
                }
                for (int j = 0; j < l.size(); j++) {
                    int num = int (l[j] - 'A');
                    w[num] = 1;
                }

            }
            else if (f == "up") {
                for (int j = 0; j < r.size(); j++) {
                    int num = int (r[j] - 'A');
                    if (w[num] == 0)
                        w[num] = 2;
                    else if (w[num] == 3)
                        w[num] = 1;
                    markedThisTime[num] = true;
                }
                for (int j = 0; j < l.size(); j++) {
                    int num = int (l[j] - 'A');
                    if (w[num] == 0)
                        w[num] = 3;
                    else if (w[num] == 2)
                        w[num] = 1;
                    markedThisTime[num] = true;
                }

                for (int j = 0; j < 12; j++) {
                    if (!markedThisTime[j])
                        w[j] = 1;
                }


            }
            else if (f == "down") {

                for (int j = 0; j < r.size(); j++) {
                    int num = int (r[j] - 'A');
                    if (w[num] == 0)
                        w[num] = 3;
                    else if (w[num] == 2)
                        w[num] = 1;
                    markedThisTime[num] = true;
                }
                for (int j = 0; j < l.size(); j++) {
                    int num = int (l[j] - 'A');
                    if (w[num] == 0)
                        w[num] = 2;
                    else if (w[num] == 3)
                        w[num] = 1;
                    markedThisTime[num] = true;
                }

                for (int j = 0; j < 12; j++) {
                    if (!markedThisTime[j])
                        w[j] = 1;
                }

            }
        }


        for (int k = 0; k < 12; k++) {
            if (w[k] == 2)
                cout << char(k + 'A') << " is the counterfeit coin and it is light." << endl;
            else if (w[k] == 3)
                cout << char(k + 'A') << " is the counterfeit coin and it is heavy." << endl;
        }


    }

}
