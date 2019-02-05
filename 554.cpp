#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <cstdio>

using namespace std;

int main() {
    set<string> dict;
    string x;
    string text;
    while (cin >> x, x != "#") {
        dict.insert(x);
    }
    scanf ("\n");
    getline(cin, text);
    int bestMatch = 0;
    int kBest = 0;
    for (int K = 0; K < 27; K++) {
        int match = 0;
        string aux;
        for (int i = 0; i < text.size(); i++) {

            // 'A' = 1... Z = 26; Space = 0
            char c = text[i];
            if ((c - 'A' + 1 + K)%27 == 0) {
                if (dict.find(aux) != dict.end()) match++;
                aux = "";
            }
            else if (c  == ' ') {
                    aux += 26 + 'A';
            }
            else aux += (c - 'A' + 1 + K)%27 + 'A' - 1;

        }
        if (dict.find(aux) != dict.end()) match++;
        if (match > bestMatch) {
            bestMatch = match;
            kBest = K;
        }
    }
    string aux = "";
    int cCont = 0;
    bool firstWord = true;
    for (int i = 0; i < text.size(); i++) {

            // 'A' = 1... Z = 26; Space = 0
            char c = text[i];
            if ((c - 'A' + 1 + kBest)%27 == 0) {
                if (cCont + aux.size() >= 60){
                    cout << endl;
                    cout << aux;
                    cCont = aux.size() + 1;

                } else {
                    if (firstWord) {
                        cout << aux; firstWord = false;
                    } else {
                        cout << " " << aux;
                    }
                    cCont += aux.size() + 1;
                }
                aux = "";
            }
            else if (c == ' ') aux +=  kBest + 'A' - 1;
            else aux += (c - 'A' + 1 + kBest)%27 + 'A' - 1;

    }
            if (cCont + aux.size() >= 60) cout << endl;
            cout << aux << endl;


}
