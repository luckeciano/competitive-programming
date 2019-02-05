#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <sstream>
#include <map>

using namespace std;
struct reg {
    int id;
    int solved;
    map <int, int> iTries;
    bool solvedP [10];
    int penalty;
};

bool compar(reg a, reg b) {
    if (a.solved != b.solved)
        return a.solved > b.solved;
    else if (a.penalty != b.penalty)
        return b.penalty > a.penalty;
    else return a.id < b.id;


}
int main () {
    int N;
    cin >> N;
    string aux;
    scanf ("\n");
    while (N--) {
        vector<reg> c;
        string str;
        while (getline(cin, str) && str.size()) {

            int cont = 0;
            int input[3];
            for (int i = 0; i < 3; i++) {
                string aux;
                for (int j = cont; j < str.size(); j++) {
                    if (str[j] == ' ') {
                        stringstream ss(aux);
                        ss >> input[i];
                        break;
                    }
                    else aux.push_back(str[cont]);
                    cont++;
                }
                cont += 1;
            }
            int x = input[0];
            int p = input[1];
            int t = input[2];
            char L = str[str.size() - 1];

            bool found = false;
            for (int i = 0; i < c.size() && !found; i++) {
                if (c[i].id == x) {
                    if (L == 'C') {
                        if (!c[i].solvedP[p]) {
                            c[i].solvedP[p] = true;
                            c[i].solved++;
                            c[i].penalty += t;
                            if (c[i].iTries.find(p) != c[i].iTries.end())
                                c[i].penalty += 20*c[i].iTries[p];
                        }
                    }
                    else if (L == 'I') {
                        if (c[i].iTries.find(p) == c[i].iTries.end())
                            c[i].iTries[p] = 1;
                        else c[i].iTries[p]++;
                    }

                    found = true;
                }
            }
            if (!found) {
                reg newOne;
                newOne.id = x;
                for (int i = 0; i < 10; i++)
                    newOne.solvedP[i] = false;
                if (L == 'C') {
                    newOne.solved = 1;
                    newOne.solvedP[p] = true;
                    newOne.penalty = t;
                } else if (L == 'I') {
                    newOne.solved = 0;
                    newOne.iTries[p] = 1;
                    newOne.penalty = 0;
                } else {
                    newOne.solved = 0;
                    newOne.penalty = 0;
                }

                c.push_back(newOne);
            }
        }

        sort (c.begin(), c.end(), compar);
        for (int i = 0; i < c.size(); i++) {
            cout << c[i].id << " " << c[i].solved << " " << c[i].penalty << endl;
        }
        if (N) cout << endl;
    }

}
