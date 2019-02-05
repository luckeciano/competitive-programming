#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <map>

using namespace std;

string baseString (string x) {
    string s = "";
    for (int i = 0; i < x.size(); i++) {
        if (x[i] != ' ')
            s += x[i];
    }
    sort(s.begin(),s.end());
    return s;
}

int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        if (i != 0) cout << endl;
        scanf ("\n");
        string x;
        vector<string>  dic;
        while (getline(cin, x)){
            if (x == "") break;
            dic.push_back(x);
        }
        sort(dic.begin(), dic.end());
        vector<string>  anagrams;
        for (int j = 0; j < dic.size(); j++) {
            for (int k = j + 1; k < dic.size(); k++) {
                bool isAnagram = true;
                if (baseString(dic[j]) == baseString(dic[k])) {
                  cout << dic[j] << " = " << dic[k] << endl;
                }
            }
        }

    }

}
