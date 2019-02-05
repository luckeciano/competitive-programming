#include <iostream>
#include <map>
#include <set>
#include <bitset>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    map<int, string> fing;
    set<char> s;
    vector<string> res;
    //bool broke[11];
    string str; int aux, F, N;
    fing[1] = "qaz";
    fing[2] = "wsx";
    fing[3] = "edc";
    fing[4] = "rfvtgb";
    fing[5] = " ";
    fing[6] = " ";
    fing[7] = "yhnujm";
    fing[8] = "ik,";
    fing[9] = "ol.";
    fing[10] = "p;/";

    while (cin >> F >> N) {
        bitset<11> broke;
        res.clear();
        s.clear();
        for (int i = 0; i < F; i++) {
            cin >> aux;
            broke[aux - 1] = true;
        }
        for (int i = 0; i < 10; i++) {
            if (!broke[i]) {
                string letters = fing[i + 1];
                for (int j = 0; j < letters.size(); j++) {
                    if (s.find(letters[j]) == s.end())
                        s.insert(letters[j]);
                }
            }
        }
        int maxSize = 0;
        for (int i = 0; i < N; i++) {
            cin >> str;
            bool canType = true;
            for (int j = 0; j < str.size() && canType; j++) {
                if (s.find(str[j]) == s.end())
                    canType = false;
            }
            if (canType) {
                if (str.size() > maxSize) {
                    res.clear(); res.push_back(str);
                    maxSize = str.size();
                } else if (str.size() == maxSize) res.push_back(str);
            }
        }
        cout << res.size() << endl;
        sort(res.begin(), res.end());
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << endl;
        }
    }



}
