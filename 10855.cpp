#include <iostream>
#include<vector>

using namespace std;

int testInc(vector<vector<char> > S, vector<vector<char> > s) {
    int cont = 0;
     /*for (int i = 0; i < S.size(); i++) {
        for (int j = 0; j < S.size(); j++) {
            cout << S [i][j];
        }
        cout << endl;
     }
    cout << endl;
*/

    for (int i = 0; i < S.size(); i++) {
        for (int j = 0; j < S.size(); j++) {
            bool eq = true;
            bool entered = false;
            for (int k = 0; k < s.size() && eq && (i + s.size() <= S.size()) && (j + s.size() <= S.size()); k++) {
                entered = true;
                for (int l = 0; l < s.size() && eq; l++){
                    if (S[i+k][j+l] != s[k][l])
                        eq = false;
                }
            }
            if (eq && entered) cont ++;
        }
    }

    return cont;
}

vector<vector<char> > rotateMatrix(vector<vector<char> > S) {
    vector<vector<char> > aux;
    for (int i = 0; i < S.size(); i++) {
        vector<char> line;
        for (int j = 0; j < S.size(); j++) {
            line.push_back(S[j][S.size() - i - 1]);
        }
        aux.push_back(line);
    }

    return aux;


}


int main() {
    int N, n;
    cin >> N >> n;
    while (!(N == 0 && n == 0)) {
        vector<vector<char> > S;
        vector<vector<char> > s;
        for (int i = 0; i < N; i++) {
            vector<char> line;
            for (int j = 0; j < N; j++) {
                char aux;
                cin >> aux;
                line.push_back(aux);
            }
            S.push_back(line);
        }

        for (int i = 0; i < n; i++) {
            vector<char> line;
            for (int j = 0; j < n; j++) {
                char aux;
                cin >> aux;
                line.push_back(aux);
            }
            s.push_back(line);
        }

        cout << testInc (S, s) << " ";
        S = rotateMatrix(S);
        cout << testInc(S, s) << " ";
        S = rotateMatrix(S);
        cout << testInc(S,s) << " ";
        S = rotateMatrix(S);
        cout << testInc(S,s) << endl;

        cin >> N >> n;
    }





}
