#include <cstdio>
#include <iostream>


using namespace std;


int main() {
    char road[105][105];
    int N, M, S;
    int ori;
    char inst;
    pair<int, int> pos;
    int stickers;
    while (scanf ("%d %d %d", &N, &M, &S), N || S || M) {
        scanf ("\n");
        stickers = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                scanf ("%c", &road[i][j]);
                if (road[i][j] == 'N') {
                    pos.first = i;
                    pos.second = j;
                    ori = 0;
                } else if (road[i][j] == 'O') {
                    pos.first = i;
                    pos.second = j;
                    ori = 1;
                } else if (road[i][j] == 'S') {
                    pos.first = i;
                    pos.second = j;
                    ori = 2;
                } else if (road[i][j] == 'L') {
                    pos.first = i;
                    pos.second = j;
                    ori = 3;
                }
            }
            scanf ("\n");
        }
        scanf ("\n");
        for (int i = 0; i < S; i++) {
            scanf ("%c", &inst);
            if (inst == 'D') {
                ori--; if (ori < 0) ori = 3;
            }
            else if (inst == 'E') {
                ori++; if (ori > 3) ori = 0;
            } else if (inst == 'F') {
                if (ori == 0) {
                    if (pos.first - 1 >= 0 && road[pos.first - 1][pos.second] != '#')
                        pos.first--;
                }
                else if (ori == 1) {
                    if (pos.second - 1 >= 0 && road[pos.first][pos.second - 1] != '#')
                        pos.second --;
                }
                else if (ori == 2) {
                    if (pos.first + 1 < N && road[pos.first + 1][pos.second] != '#')
                        pos.first++;
                }
                else if (ori == 3) {
                    if (pos.second + 1 < M && road[pos.first][pos.second + 1] != '#')
                        pos.second++;
                }

            }


            if (road[pos.first][pos.second] == '*') {
                road[pos.first][pos.second] = '.';
                stickers++;
            }
        }
        printf ("%d\n", stickers);
    }




}
