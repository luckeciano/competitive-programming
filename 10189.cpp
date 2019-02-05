#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    int counter = 0;

    while (!(N == 0 && M == 0)) {
        counter ++;
        if (counter != 1) cout << endl;
        vector<vector<char>> field;
        for (int i = 0; i < N; i++) {
            vector<char> line;
            for (int j = 0; j < M; j++) {
                char aux;
                cin >> aux;
                line.push_back(aux);
            }
            field.push_back(line);
        }
        vector<vector<char>> result;

        for (int i = 0; i < N; i++) {
            vector<char> lineRes;
            for (int j = 0; j < M; j++) {
                if (field[i][j] == '*') {
                    lineRes.push_back('*');
                }
                else {
                    int cont = 0;
                    if (i - 1 >= 0) {
                        if (field[i-1][j] == '*')
                            cont++;
                    }
                    if (i-1>=0 && j-1>=0) {
                        if (field[i-1][j-1] == '*')
                            cont++;
                    }
                    if (i-1>=0 && j+1 < M) {
                        if (field [i-1][j+1] == '*')
                            cont++;
                    }
                    if (i + 1 < N) {
                        if (field [i+1][j] == '*')
                            cont++;
                    }
                    if (i + 1 < N && j - 1 >= 0) {
                        if (field[i+1][j-1] == '*')
                            cont++;
                    }
                    if (i+1 < N && j + 1 < M) {
                        if (field[i+1][j+1] == '*')
                            cont++;
                    }
                    if (j - 1>=0) {
                        if (field[i][j-1] == '*')
                            cont++;
                    }
                    if (j+1 < M) {
                        if (field[i][j + 1] == '*')
                            cont++;
                    }
                    lineRes.push_back(char(cont + 48));
                }
            }
            result.push_back(lineRes);
        }

        cout << "Field #" << counter << ":" << endl;
        for (int i = 0; i < N; i ++) {
            for (int j = 0; j < M; j++) {
                cout << result[i][j];
            }
            cout << endl;
        }

        cin >> N >> M;


    }
}
