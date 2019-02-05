#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int card[6][6];
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (!(i == 2 && j == 2))
                    cin >> card[i][j];
                else card[i][j] = 0;
            }
        }

        bool isOver = false;
        int play;
        for (int i = 0; i < 75; i++) {
            int num;
            cin >> num;
            if (!isOver) {
                if (num >= 1 && num <= 15) {
                    for (int j = 0; j < 5; j++) {
                        if (card[j][0] == num) {
                            card[j][0] = 0;
                            if (card[0][0] + card[1][0] + card[2][0] + card[3][0] + card[4][0] == 0) {
                                isOver = true;
                                play = i + 1;
                            }
                            break;
                        }
                    }

                }
                else if (num > 15 && num <= 30) {
                    for (int j = 0; j < 5; j++) {
                        if (card[j][1] == num) {
                            card[j][1] = 0;
                            if (card[0][1] + card[1][1] + card[2][1] + card[3][1] + card[4][1] == 0) {
                                isOver = true;
                                play = i + 1;
                            }
                            break;
                        }
                    }
                }
                else if (num > 30 && num <= 45) {
                    for (int j = 0; j < 5; j++) {
                        if (card[j][2] == num) {
                            card[j][2] = 0;
                            if (card[0][2] + card[1][2] + card[2][2] + card[3][2] + card[4][2] == 0) {
                                isOver = true;
                                play = i+1;
                            }
                            break;
                        }
                    }

                }
                else if (num > 45 && num <= 60) {
                    for (int j = 0; j < 5; j++) {
                        if (card[j][3] == num) {
                            card[j][3] = 0;
                            if (card[0][3] + card[1][3] + card[2][3] + card[3][3] + card[4][3] == 0) {
                                isOver = true;
                                play = i+1;
                            }
                            break;
                        }
                    }

                }
                else if (num > 60 && num <= 75) {
                    for (int j = 0; j < 5; j++) {
                        if (card[j][4] == num) {
                            card[j][4] = 0;
                            if (card[0][4] + card[1][4] + card[2][4] + card[3][4] + card[4][4] == 0) {
                                isOver = true;
                                play = i+1;
                            }
                            break;
                        }
                    }

                }

                for (int k = 0; k < 5; k ++) {
                    if (card[k][0] + card[k][1] + card[k][2] + card[k][3] + card[k][4] == 0) {
                        isOver = true;
                        play = i + 1;
                    }
                }
                if (card[0][0] + card[1][1] + card[2][2] + card[3][3] + card[4][4] == 0) {
                    isOver = true;
                    play = i + 1;
                }
                if (card[0][4] + card[1][3] + card[2][2] + card[3][1] + card[4][0] == 0) {
                    isOver = true;
                    play = i + 1;
                }

            }
        }
        cout << "BINGO after " << play << " numbers announced" << endl;




    }

}
