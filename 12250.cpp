#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    string word;
    cin >> word;
    map <string, string> mapWord;
    mapWord.insert(std::pair <string, string>("HELLO", "ENGLISH"));
    mapWord.insert(std::pair <string, string>("HOLA", "SPANISH"));
    mapWord.insert(std::pair <string, string>("HALLO", "GERMAN"));
    mapWord.insert(std::pair <string, string>("BONJOUR", "FRENCH"));
    mapWord.insert(std::pair <string, string>("CIAO", "ITALIAN"));
    mapWord.insert(std::pair <string, string>("ZDRAVSTVUJTE", "RUSSIAN"));
    int cont = 0;
    while (word != "#") {
        cont++;
        if (mapWord.find(word) != mapWord.end()) {
            cout << "Case " << cont << ": " << mapWord.find(word)->second << endl;
        }
        else {
            cout <<  "Case " << cont << ": " << "UNKNOWN" << endl;
        }
        cin >> word;
    }

}


