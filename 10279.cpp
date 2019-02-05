#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;


bool evalutatePos (vector<vector<char> > field, int i, int j, vector<char> &line, int dimension) {
    if (field[i][j] == '*') {
        line.push_back('*');
        return true;
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
        if (i-1>=0 && j+1 < dimension) {
            if (field [i-1][j+1] == '*')
                cont++;
        }
        if (i + 1 < dimension) {
            if (field [i+1][j] == '*')
                cont++;
        }
        if (i + 1 < dimension && j - 1 >= 0) {
            if (field[i+1][j-1] == '*')
                cont++;
        }
        if (i+1 < dimension && j + 1 < dimension) {
            if (field[i+1][j+1] == '*')
                cont++;
        }
        if (j - 1>=0) {
            if (field[i][j-1] == '*')
                cont++;
        }
        if (j+1 < dimension) {
            if (field[i][j + 1] == '*')
                cont++;
        }
        line.push_back(char(cont + 48));
    }
    return false;


}

int main() {
    int N;
    cin >> N;

    for (int counter = 0; counter < N; counter++) {
        scanf ("\n");
        int dimension;
        cin >> dimension;
        if (counter != 0) cout << endl;
        vector<vector<char>> field;
        for (int i = 0; i < dimension; i++) {
            vector<char> line;
            for (int j = 0; j < dimension; j++) {
                char aux;
                cin >> aux;
                line.push_back(aux);
            }
            field.push_back(line);
        }

        vector<vector<char>> input;
         for (int i = 0; i < dimension; i++) {
            vector<char> line;
            for (int j = 0; j < dimension; j++) {
                char aux;
                cin >> aux;
                line.push_back(aux);
            }
            input.push_back(line);
        }

        vector<vector<char> > result;
        bool isMined = false;
        for (int i = 0; i < dimension; i++) {
            vector<char> line;
            for (int j = 0; j < dimension; j++) {
                if (input[i][j] == 'x') {
                    bool aux = false;
                    aux = evalutatePos(field,i, j, line, dimension);
                    if (aux) isMined = true;
                } else {
                    line.push_back('.');
                }

            }
            result.push_back(line);

        }

        //isMined
        if (isMined) {
            for (int i = 0; i < dimension; i++) {
                for (int j = 0; j < dimension; j++) {
                    if (field[i][j] == '*') {

                        result[i][j] = '*';
                    }
                }
            }
        }

        for (int i = 0; i < dimension; i++) {
            for (int j = 0; j < dimension; j++) {
                cout << result[i][j];
            }
            cout << endl;
        }

    }

}
