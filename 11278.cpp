#include <iostream>
#include <string>
using namespace std;


int main() {

    string qwerty = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./~!@#$%^&*()_+QWERTYUIOP{}|ASDFGHJKL:ZXCVBNM<>";
    string dvorak = "`123qjlmfp/[]456.orsuyb;=\\789aehtdck-0zx,inwvg'~!@#QJLMFP?{}$%^>ORSUYB:+|&*(AEHTDCK)ZX<INWVG";

    string x;
    while (getline(cin, x)) {

        //if (x.size() == 0) break;
        for (int j = 0; j < x.size(); j++) {
            if (x[j] == ' ') {
                cout << ' '; continue;
            }
            if (x[j] == '"') {
                cout << "_"; continue;
            }
            if (x[j] == '?') {
                cout << "\""; continue;
            }
            for (int i = 0; i < qwerty.size(); i++){
                if (qwerty[i] == x[j]) {
                    cout << dvorak[i];
                    break;
                }
            }
        }
        cout << endl;
    }



}
