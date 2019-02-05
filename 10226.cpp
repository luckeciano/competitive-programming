#include <iostream>
#include <map>
#include <iomanip>
#include <cstdio>

using namespace std;

int main() {
    int test;
    cin >> test;
    string tree;
    scanf ("\n");
    while (test--) {
        map<string, int> maps;
        getline(cin, tree);
        int all = 0;
        while (tree.size() != 0) {
            if (maps.find(tree) == maps.end())
                maps[tree] = 1;
            else maps[tree]++;
            all++;
            getline(cin, tree);
        }
        map<string,int>::iterator it;
        for (it = maps.begin(); it != maps.end(); it++) {
            cout << it->first << " ";
            float percentagem = (100.0*it->second)/all;
            cout << fixed << setprecision(4) << percentagem << endl;
        }

        if (test != 0) cout << endl;
    }



}
