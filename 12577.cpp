#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main() {
    string word;
    cin >> word;
    int cont = 0;
    while (word != "*") {
        cont ++;
        if (word == "Hajj")
            cout << "Case " << cont << ": " << "Hajj-e-Akbar" << endl;
        if (word == "Umrah")
            cout << "Case " << cont << ": " << "Hajj-e-Asghar" << endl;

        cin >> word;
    }
}
