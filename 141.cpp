#include <iostream>
#include <map>

using namespace std;

void rotateMatrix (int x[][50], int n) {
    int copyMat[50][50];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            copyMat[j][n - i - 1] = x[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            x[i][j] = copyMat[i][j];
        }
    }
}

int main() {
    int N;
    int board[50][50] = {{0}};
    cin >> N;
    while (N!=0) {
        for (int i =0; i < N; i++)
            for (int j = 0; j < N; j++)
                board[i][j] = 0;


        map <string, int> cases;
        int m = 2*N;
        bool patternChecked = false;
        int player;
        int moved;
        for (int i = 0; i < m; i++) {
            int x, y;
            char symbol;
            cin >> x >> y >> symbol;
            if (!patternChecked) {
                if (symbol == '+')
                    board[x-1][y-1] = 1;
                else board[x-1][y-1] = 0;
                string s = "";
                for (int j = 0; j < N; j++) {
                    for (int k = 0; k < N; k++) {
                        s += (board[j][k] + '0');
                    }
                }
                //cout << "in this time: " << s << endl;
                if (cases[s] == 1) {
                    patternChecked = true;
                    player = (i+1)%2 + 1;
                    moved = i + 1;

                } else {
                    cases[s] = 1;
                    //cout << s << endl;
                    int boardCopy [50][50];
                    for (int l = 0; l < N; l++) {
                        for (int r = 0; r < N; r++) {
                            boardCopy[l][r] = board[l][r];
                        }
                    }
                    for (int cont = 0; cont < 3; cont++) {
                        rotateMatrix (boardCopy, N);
                        string t = "";
                        for (int j = 0; j < N; j++) {
                            for (int k = 0; k < N; k++) {
                                t += boardCopy[j][k] + '0';
                            }
                        }
                        //cout << t  << endl;
                        cases[t] = 1;
                    }



                }
            }


        }
        if (patternChecked) cout << "Player " << player << " wins on move " << moved << endl;
        else cout << "Draw" << endl;

        cin >> N;
        patternChecked = false;
    }




}
