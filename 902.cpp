#include <iostream>
#include <map>
using namespace std;

int main() {
    int N; string str; string aux;
    map<string, int> freq;
    while (cin >> N >> str) {
        freq.clear();
        for (int i = 0; i < str.size(); i++) {
            aux = str.substr(i, N);
            if (freq.find(aux) == freq.end())
                freq[aux] = 1;
            else freq[aux]++;
        }
        map<string, int> :: iterator it;
        int maxFreq = 0; string pw;
        for (it = freq.begin(); it != freq.end(); it++) {
            if (it->second > maxFreq) {
                maxFreq = it->second;
                pw = it->first;
            }
        }
        cout << pw << endl;
    }
}
