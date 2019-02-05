#include <iostream>
#include <vector>
using namespace std;
vector<string> dict;
bool Find(string str) {
    for (int i = 0; i < dict.size(); i++) {
        if (dict[i] == str) return true;
    }
    return false;

}

int main() {
    int N, q;

    string str;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> str;
        dict.push_back(str);
    }
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> str;
        if (Find(str)) cout << str << " is correct" << endl;
        else {
            bool mispel = false;
            for (int m = 0; m < dict.size() && !mispel; m++) {
                if (dict[m].size() == str.size() - 1) {
                    int cnt = 0; int eq = 0;
                    for (int k = 0; k < dict[m].size() && cnt < str.size(); k++) {
                        while (cnt < str.size() && str[cnt] != dict[m][k]) {
                            cnt++;
                        }
                        if (cnt < str.size() && str[cnt] == dict[m][k]) eq++, cnt++;
                    }
                    if (eq == dict[m].size()) {
                        cout << str << " is a misspelling of " << dict[m] << endl;
                        mispel = true;
                    }
                }
                else if (dict[m].size() == str.size() + 1) {
                    int cnt = 0; int eq = 0;
                    for (int k = 0; k < str.size() && cnt < dict[m].size() ; k++) {
                        while (cnt < dict[m].size() && dict[m][cnt] != str[k]) {
                            cnt++;
                        }
                        if (cnt < dict[m].size() && str[k] == dict[m][cnt]) eq++, cnt++;
                    }
                    if (eq == str.size()) {
                        cout << str << " is a misspelling of " << dict[m] << endl;
                        mispel = true;
                    }
                }
                else if (dict[m].size() == str.size()) {
                    int eq = 0;
                    for (int k = 0; k < dict[m].size(); k++) {
                        if (dict[m][k] == str[k]) eq++;
                    }
                    if (eq == str.size() - 1) {
                        cout << str << " is a misspelling of " << dict[m] << endl;
                        mispel = true;
                    }

                    for (int e = 1; e < str.size() && !mispel; e++) {
                        string aux = str;
                        char c; c = aux[e - 1];
                        aux[e - 1] = aux[e];
                        aux[e] = c;
                        if (aux == dict[m]) {
                            cout << str << " is a misspelling of " << dict[m] << endl;
                            mispel = true;
                        }
                    }
                }

            }

            if (!mispel) cout << str << " is unknown" << endl;

        }



    }

}
