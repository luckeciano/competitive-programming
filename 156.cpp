#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {

    string x;
    cin >> x;
    map<string, vector<string> > dic;
    while (x != "#") {
        string key = x;
        transform(key.begin(), key.end(), key.begin(), ::tolower);
        sort(key.begin(), key.end());
        dic[key].push_back(x);
         cin >> x;
    }
    vector<string> relAn;
    map<string,vector<string> >::iterator it;
    for (it = dic.begin(); it != dic.end(); it++) {
        if (it->second.size() == 1)
            relAn.push_back(it->second[0]);
    }
    sort(relAn.begin(), relAn.end());
    for (int i = 0; i < relAn.size(); i++) {
        cout << relAn[i] << endl;
    }



}
