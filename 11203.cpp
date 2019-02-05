#include <iostream>
#include <regex>
using namespace std;

int main() {
    int TC;
    cin >> TC;
    //regex r("(\\?)+M(\\?)+E(\\?)+");
    string str;
    while (TC--) {
        int x = 0, y = 0, z = 0;
        cin >> str;
        bool t = true;
        int cont = 0;
        while (str[cont] == '?' && cont < str.size()) {
            x++;
            cont++;
        }
        if (str[cont] != 'M') t = false;
        cont++;
        while (str[cont] == '?' && cont < str.size()) {
            y++;
            cont++;
        }
        if (str[cont] != 'E') t = false;
        cont++;
        while (str[cont] == '?' && cont < str.size()) {
            z++;
            cont++;
        }
        if (cont != str.size()) t = false;
        if (x == 0 || y == 0 || z == 0 ) t = false;
        if (z != x + y) t = false;
        if (t) cout << "theorem";
        else cout << "no-theorem";
        cout << endl;


    }


}
