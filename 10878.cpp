#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    string str, aux;
    getline(cin, aux);
    getline(cin, str);
    vector<string> text;

    while (str[0] != '_') {
        string newLine;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == ' ') newLine.push_back('0');
            else if (str[i] == 'o') newLine.push_back('1');
            //else if (str[i] == '.') newLine.push_back('.');
        }
        text.push_back(newLine);
        getline(cin, str);
    }

    for (int i =0; i < text.size(); i++) {
        int k = 0;
        int sum = 0;
        for (int j = text[i].size() - 1; j >= 0; j--) {
            sum += pow(2, k) * (text[i][j] - '0');
            k++;
        }
       // cout << sum << " ";
        cout << char(sum);
    }


}
