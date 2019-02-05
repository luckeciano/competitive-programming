#include <iostream>
#include <map>

using namespace std;

int main() {

    map <char, char> rev;
    rev['A'] = 'A';
    rev['E'] = '3';
    rev['H'] = 'H';
    rev['I'] = 'I';
    rev['J'] = 'L';
    rev['L'] = 'J';
    rev['M'] = 'M';
    rev['O'] = 'O';
    rev['S'] = '2';
    rev['T'] = 'T';
    rev['U'] = 'U';
    rev['V'] = 'V';
    rev['W'] = 'W';
    rev['X'] = 'X';
    rev['Y'] = 'Y';
    rev['Z'] = '5';
    rev['1'] = '1';
    rev['2'] = 'S';
    rev['3'] = 'E';
    rev['5'] = 'Z';
    rev['8'] = '8';


    string s;
    while (cin >> s) {
        bool pal = true;
        bool mirror = true;
        for (int i = 0; i < s.size()/2; i++) {
            if (!(s[i] == s[s.size()-i-1]))
                pal = false;

            if (!(s[i] == rev[s[s.size() - i - 1]])) {
                mirror = false;
            }
        }
        if (s.size()%2 != 0)
            if (s[s.size()/2] != rev[s[s.size()/2]]) mirror = false;

        if (!mirror && !pal) cout << s << " -- is not a palindrome." << endl;
        else if (pal && !mirror) cout << s << " -- is a regular palindrome." << endl;
        else if (mirror && !pal) cout << s << " -- is a mirrored string." << endl;
        else if (mirror && pal) cout << s << " -- is a mirrored palindrome." << endl;

        cout << endl;
    }

}
