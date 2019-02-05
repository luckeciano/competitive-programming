#include <iostream>
#include <regex>
#include <cstdio>
using namespace std;

int main() {
    regex r ("[a-zA-Z]+[.!?]?");
    string word, text;
    while (getline(cin, text)) {
        //cout << text << endl;
        int cont = 0;
        for (int i = 0; i < text.size(); i++) {
            if (isalpha(text[i])) {
                cont++;
                while (isalpha(text[i])) {
                    i++;
                }
              //  cout << i << endl;
            }
        }
        cout << cont << endl;
    }



}
