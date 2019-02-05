#include <iostream>
#include <map>

using namespace std;

int main() {
    string str1, str2;
    map<char, int> freq1, freq2;
    while (getline(cin, str1), getline(cin, str2)) {
        freq1.clear(); freq2.clear();
        for (int i = 0; i < str1.size(); i++) {
            freq1[str1[i]]++;
        }
        for (int i = 0; i < str2.size(); i++) {
            freq2[str2[i]]++;
        }
        string res;
        map<char, int> :: iterator it;
        for (it = freq1.begin(); it != freq1.end(); it++) {
            if (freq2.find(it->first) != freq2.end()) {
                int cont = min(freq2[it->first], it->second);
                for (int k = 0; k < cont; k++) res += it->first;
            }
        }

        cout << res << endl;
    }


}
