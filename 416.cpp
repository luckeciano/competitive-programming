#include <iostream>
#include <vector>
#include <set>
#include <map>

using namespace std;


void backtrack (string led, set<int> &pos, map<string, int> numbers, int i, vector<bool> &func) {
     if (numbers.find(led) != numbers.end())
        pos.insert(numbers[led]);

    if (i == led.size()) return;


    if (led[i] == 'N') {
        if (!func[i]) {
            led[i] = 'Y';
            backtrack (led, pos, numbers, i + 1, func);
        }
        led[i] = 'N';
        backtrack(led, pos, numbers, i + 1, func);
    } else {
        func[i] = true;
        backtrack (led, pos, numbers, i + 1, func);
    }

}


void calcPoss(string led, set<int> &pos, map<string, int> numbers, vector<bool> &func) {
    if (numbers.find(led) != numbers.end())
        pos.insert(numbers[led]);
    if (led[0] == 'N') {
        if (!func[0]) {
            led[0] = 'Y';
            backtrack (led, pos, numbers, 1, func);
        }
        led[0] = 'N';
        backtrack (led, pos, numbers, 1, func);
    } else {
        func[0] = true;
        backtrack (led, pos, numbers, 1, func);
    }
}

void solve (vector<string> led, map<string, int> numbers, map<int, string> strings) {
    bool match = false;
    vector<set<int> > possN;
    possN.resize(led.size());
    vector<bool> functional;
    for (int i = 0; i < 8; i++) {
        functional.push_back(false);
    }
    for (int i = 0; i < led.size(); i++) {
        calcPoss (led[i], possN[i], numbers, functional);

        vector<int> toDelete;
        for (int q = 0; q < i; q++) {
            set<int>::iterator it;
            toDelete.clear();
            for (it = possN[q].begin(); it != possN[q].end(); it++) {
                string numbString = strings[*it];
                for (int k = 0; k < numbString.size(); k++) {
                    if (led[q][k] == 'N' && numbString[k] == 'Y' && functional[k]) {
                        toDelete.push_back(*it);
                        break;
                    }
                }
            }
            for (int t = 0; t < toDelete.size(); t++) {
                possN[q].erase(possN[q].find(toDelete[t]));
            }
        }

        for (int r = 0; r < 8; r++)
            functional[r] = false;
    }

    set<int>::iterator it;
    for (it = possN[0].begin(); it != possN[0].end() && !match; it++) {
        int x = *it;
        bool countDown = true;
        for (int k = 1; k < possN.size() && countDown; k++) {
            if (possN[k].find(x - k) == possN[k].end()) {
                countDown = false;
            }
        }
        if (countDown) match = true;

    }

    if (match) cout << "MATCH" << endl;
    else cout << "MISMATCH" << endl;


}



int main() {
    map<string, int> numbers;
    numbers["YYYYYYN"] = 0;
    numbers["NYYNNNN"] = 1;
    numbers["YYNYYNY"] = 2;
    numbers["YYYYNNY"] = 3;
    numbers["NYYNNYY"] = 4;
    numbers["YNYYNYY"] = 5;
    numbers["YNYYYYY"] = 6;
    numbers["YYYNNNN"] = 7;
    numbers["YYYYYYY"] = 8;
    numbers["YYYYNYY"] = 9;

    map<int, string> strings;
    strings[0] = "YYYYYYN";
    strings[1] = "NYYNNNN";
    strings[2] = "YYNYYNY";
    strings[3] = "YYYYNNY";
    strings[4] = "NYYNNYY";
    strings[5] = "YNYYNYY";
    strings[6] = "YNYYYYY";
    strings[7] = "YYYNNNN";
    strings[8] = "YYYYYYY";
    strings[9] = "YYYYNYY";

    int n;
    cin >> n;
    vector<string> led;
    while (n) {
        led.clear();
        string aux;
        for (int i = 0; i < n; i++) {
            cin >> aux;
            led.push_back(aux);
        }
        solve (led, numbers, strings);
        cin >> n;
    }

}
