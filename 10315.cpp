#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <cstdio>

using namespace std;

vector<int> hand2Number(vector<string> hand) {
    vector<int> mapHand;
    for (int i = 0; i < 5; i++)
    {
        if (hand[i][0] == 'A')
            mapHand.push_back(14);
        else if (hand[i][0] == 'K')
            mapHand.push_back(13);
        else if (hand[i][0] == 'Q')
            mapHand.push_back(12);
        else if (hand[i][0] == 'J')
            mapHand.push_back(11);
        else if (hand[i][0] == 'T')
            mapHand.push_back(10);
        else {
            int j = hand[i][0] - 48;
            mapHand.push_back(j);
        }
    }
    return mapHand;
}

int highCard (vector<string> hand) {
    vector<int> mapHand = hand2Number(hand);

    int maxValue = 0;
    for (int i = 0; i < 5; i++) {
        if (mapHand[i] > maxValue)
            maxValue = mapHand[i];
    }

    return maxValue;
}

vector<int> sameKind (vector<string> hand) {
    vector<int> sameKindVector;
    for (int i = 0; i < 15; i++) {
        sameKindVector.push_back(0);
    }
    vector<int> handNumber = hand2Number(hand);
    for (int i =0; i < 5; i++) {
        int value = handNumber[i];
        sameKindVector[value] += 1;
    }
    return sameKindVector;
}

int Pair(vector<int> handSameKind) {
    for (int i = 0; i < handSameKind.size(); i++) {
        if (handSameKind[i] == 2)
            return i;
    }
    return -1;
}

int threeKind(vector<int> handSameKind) {
    for (int i = 0; i < handSameKind.size(); i++) {
        if (handSameKind[i] == 3)
            return i;
    }
    return -1;
}

vector<int> twoPairs(vector<int> handSameKind) {
    vector<int> result;
    for (int i = 0; i < handSameKind.size(); i++) {
        if (handSameKind[i] == 2)
            result.push_back(i);
    }
    return result;
}

int fourKind(vector<int> handSameKind) {
    for (int i = 0; i < handSameKind.size(); i++) {
        if (handSameKind[i] == 4)
            return i;
    }
    return -1;
}

int straight(vector<string> hand) {
    vector<int> handNumber = hand2Number(hand);
    sort(handNumber.begin(), handNumber.end());
    for (int i = 1; i < handNumber.size() ;i ++) {
        if (handNumber[i] - handNumber[i - 1] != 1)
            return -1;
    }
    return handNumber[handNumber.size() - 1];
}

int flush (vector<string> hand) {
    char suit = hand[0][1];
    for (int i = 0; i < hand.size(); i++) {
        if (suit != hand[i][1])
            return -1;
    }
    return highCard(hand);
}

int fullHouse(vector<int> sameKind) {
    int threeKindHighCard = threeKind(sameKind);
    if (threeKindHighCard != -1 && Pair(sameKind) != -1)
        return threeKindHighCard;
    return -1;
}

int strFlush(vector<string> hand) {
    int highCard = flush(hand);
    if (highCard != -1 && straight(hand) != -1)
        return highCard;
    return -1;
}

bool gameIsOver (int resultBlack, int resultWhite) {
    if (resultBlack > resultWhite) {
        cout << "Black wins." <<endl;
        return true;
    }
    else if (resultBlack < resultWhite) {
        cout << "White wins." << endl;
        return true;
    }
    else if (resultBlack == -1)
        return false;
    else {
        cout << "Tie." << endl;
        return true;
    }
}
int higherCard (vector<string> handBlack, vector<string> handWhite) {
    vector<int> handBlackNumber = hand2Number(handBlack);
    vector<int> handWhiteNumber = hand2Number(handWhite);
    sort(handBlackNumber.begin(), handBlackNumber.end());
    sort(handWhiteNumber.begin(), handWhiteNumber.end());
    for (int i = handBlackNumber.size() - 1; i >= 0; i--) {

        if (handBlackNumber[i] > handWhiteNumber[i])
            return 2;
        else if (handBlackNumber[i] < handWhiteNumber[i])
            return 1;
    }
    return 0;

}
int remainingCard(vector<int> sameKindBlack,vector<int> sameKindWhite) {
    int rBlack, rWhite;
    for (int i = 0; i < sameKindBlack.size(); i++) {
        if (sameKindBlack[i] == 1)
            rBlack = i;
    }
    for (int j = 0; j < sameKindWhite.size(); j++) {
        if (sameKindWhite[j] == 1)
            rWhite = j;
    }

    if (rBlack > rWhite)
        return 2;
    else if (rBlack < rWhite)
        return 1;
    else return 0;
}


int main() {
    string aux;
    while (cin >> aux) {
        vector<string> handBlack, handWhite;
        handBlack.push_back(aux);
        for (int i = 0; i < 4; i++) {
            string aux;
            cin >> aux;
            handBlack.push_back(aux);
        }
        for (int i = 0; i < 5; i++) {
            string aux;
            cin >> aux;
            handWhite.push_back(aux);
        }

        vector<int>  sameKindBlack, sameKindWhite;
        sameKindBlack.resize(15);
        sameKindWhite.resize(15);
        sameKindBlack = sameKind(handBlack);
        sameKindWhite = sameKind(handWhite);
        int doneBlack = -1;
        int doneWhite = -1;
        bool finalGame;

        doneBlack = strFlush(handBlack);
        doneWhite = strFlush(handWhite);
        finalGame = gameIsOver(doneBlack, doneWhite);
        if (!finalGame) {
            doneBlack = fourKind(sameKindBlack);
            doneWhite = fourKind(sameKindWhite);
            finalGame = gameIsOver(doneBlack, doneWhite);
        }
        if (!finalGame) {
            doneBlack = fullHouse (sameKindBlack);
            doneWhite = fullHouse(sameKindWhite);
            finalGame = gameIsOver(doneBlack, doneWhite);
        }
        if (!finalGame) {
            doneBlack = flush(handBlack);
            doneWhite = flush(handWhite);
            finalGame = true;
            if (doneBlack != -1 && doneWhite == -1) {
                cout << "Black wins." << endl;
            }
            else if (doneBlack == -1 && doneWhite != -1) {
                cout << "White wins." << endl;
            }
            else if (doneBlack != -1 && doneWhite != -1) {
                    if (higherCard(handBlack, handWhite) == 2)
                        cout << "Black wins." << endl;
                    else if (higherCard(handBlack, handWhite) == 1)
                        cout << "White wins." << endl;
                    else cout << "Tie." << endl;
            }
            else {
                finalGame = false;
            }

        }
        if (!finalGame) {
            doneBlack = straight (handBlack);
            doneWhite = straight(handWhite);
            finalGame = gameIsOver(doneBlack, doneWhite);

        }

        if (!finalGame) {
            doneBlack = threeKind (sameKindBlack);
            doneWhite = threeKind(sameKindWhite);
            finalGame = true;
            finalGame = true;
            if (doneBlack != -1 && doneWhite == -1) {
                cout << "Black wins." << endl;
            }
            else if (doneBlack == -1 && doneWhite != -1) {
                cout << "White wins." << endl;
            }
            else if (doneBlack != -1 && doneWhite != -1) {
                    if (doneBlack > doneWhite)
                        cout << "Black wins." << endl;
                    else if (doneBlack < doneWhite)
                        cout << "White wins." << endl;
                    else {
                        if (higherCard(handBlack, handWhite) == 2)
                            cout << "Black wins." << endl;
                        else if (higherCard(handBlack, handWhite) == 1)
                            cout << "White wins." << endl;
                        else cout << "Tie." << endl;
                    }
            }
            else {
                finalGame = false;
            }
        }
        if (!finalGame) {
            vector<int> pairsBlack, pairsWhite;
            pairsBlack = twoPairs (sameKindBlack);
            pairsWhite = twoPairs(sameKindWhite);
            finalGame = true;
            if (pairsBlack.size() == 2 && pairsWhite.size() == 2) {
                if (pairsBlack[1] > pairsWhite[1])
                    cout << "Black wins." << endl;
                else if (pairsBlack[1] < pairsWhite[1])
                    cout << "White wins." << endl;
                else if (pairsBlack[0] > pairsWhite[0])
                    cout << "Black wins." << endl;
                else if (pairsBlack[0] < pairsWhite[0])
                    cout << "White wins." << endl;
                else {
                    int x = remainingCard(sameKindBlack, sameKindWhite);
                    if (x == 2)
                        cout << "Black wins." << endl;
                    else if (x == 1)
                        cout << "White wins." << endl;
                    else cout << "Tie." << endl;
                }

            } else if (pairsBlack.size() == 2 && pairsWhite.size() != 2) {
                cout << "Black wins." << endl;
            } else if (pairsBlack.size() != 2 && pairsWhite.size() == 2) {
                    cout << "White wins." << endl;
            } else finalGame = false;
        }
        if (!finalGame) {
            doneBlack = Pair (sameKindBlack);
            doneWhite = Pair(sameKindWhite);
            finalGame = true;
            if (doneBlack != -1 && doneWhite == -1) {
                cout << "Black wins." << endl;
            }
            else if (doneBlack == -1 && doneWhite != -1) {
                cout << "White wins." << endl;
            }
            else if (doneBlack != -1 && doneWhite != -1) {
                    if (doneBlack > doneWhite)
                        cout << "Black wins." << endl;
                    else if (doneBlack < doneWhite)
                        cout << "White wins." << endl;
                    else {
                        if (higherCard(handBlack, handWhite) == 2)
                            cout << "Black wins." << endl;
                        else if (higherCard(handBlack, handWhite) == 1)
                            cout << "White wins." << endl;
                        else cout << "Tie." << endl;
                    }
            }
            else {
                finalGame = false;
            }
        }
        if (!finalGame) {
            if (higherCard(handBlack, handWhite) == 2)
                cout << "Black wins." << endl;
            else if (higherCard(handBlack, handWhite) == 1)
                cout << "White wins." << endl;
            else cout << "Tie." << endl;
        }
    }

}
