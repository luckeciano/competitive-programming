#include <iostream>
#include <vector>
using namespace std;

int main() {
    string str;
    vector<string> codes;
    bool decodable;
    int cont = 0;
    while (cin >> str) {
        if (str == "9") {
            cont++;
            decodable = true;
            for (int i = 0; i < codes.size() && decodable; i++) {
                for (int j = i + 1; j < codes.size() && decodable; j++) {
                    int siz = min(codes[i].size(), codes[j].size());
                    string aux1 = codes[i].substr(0, siz);
                    string aux2 = codes[j].substr(0, siz);
                    //cout << aux1 << "~" << aux2 << endl;
                    if (aux1 == aux2) decodable = false;
                }
            }
            if (decodable)
                cout << "Set " << cont << " is immediately decodable" << endl;
            else cout << "Set " << cont << " is not immediately decodable" << endl;
            codes.clear();
        } else codes.push_back(str);



    }



}
