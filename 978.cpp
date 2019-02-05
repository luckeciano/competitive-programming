#include <iostream>
#include <set>
#include <vector>

using namespace std;

int main() {
    int test;
    cin >> test;
    while (test--) {
        int S, SG, SB;
        cin >> S >> SG >> SB;
        multiset<int> green, blue;
        for (int i = 0; i < SG; i++) {
            int aux;
            cin >> aux;
            green.insert(aux);
        }
        for (int j = 0; j < SB; j++) {
            int aux;
            cin >> aux;
            blue.insert(aux);
        }
        while (!(green.empty() || blue.empty())) {
           // cout << green.size() << " " << blue.size() << endl;
            vector<int> rG, rB;
            for (int i = 0; i < S; i++) {
                if (!green.empty() && !blue.empty()) {
                    //fight!
                    int gr = *green.rbegin();
                    int bl = *blue.rbegin();
                    if (gr > bl)
                        rG.push_back(gr-bl);
                    else if (gr < bl) rB.push_back(bl-gr);
                    green.erase(prev(green.end()));
                    blue.erase(prev(blue.end()));
                }
            }
            for (int k = 0; k < rG.size(); k++) {
                green.insert(rG[k]);
            }
            for (int k = 0; k < rB.size(); k++){
                blue.insert(rB[k]);
            }

           // cout << "now: " << green.size() << " " << blue.size() << endl;
        }

        if (green.empty() && blue.empty())
            cout << "green and blue died" << endl;
        else if (green.empty()) {
            cout << "blue wins" << endl;
            multiset<int>::reverse_iterator it;
            for (it = blue.rbegin(); it != blue.rend(); it++)
                cout << *it << endl;
        } else if (blue.empty()) {
            cout << "green wins" << endl;
            multiset<int>::reverse_iterator it;
            for (it = green.rbegin(); it != green.rend(); it++)
                cout << *it << endl;
        }
        if (test != 0) cout << endl;



    }


}
