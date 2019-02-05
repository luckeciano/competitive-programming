#include <iostream>

using namespace std;

int South (int state, int &north, int &south) {
    int finalState = north;
    north = 7 - state;
    south = state;
    return finalState;
}

int North (int state, int &north, int &south) {
    int finalState = south;
    south = 7 - state;
    north = state;
    return finalState;
}

int East (int state, int &west, int &east) {
    int finalState = west;
    west = 7 - state;
    east = state;
    return finalState;
}

int West (int state, int &west, int &east) {
    int finalState = east;
    east = 7 - state;
    west = state;
    return finalState;
}


int main() {
    int N;
    cin >> N;

    while (N != 0) {
        string com;
        int state = 1;
        int north = 2;
        int south = 5;
        int west = 3;
        int east = 4;
        for (int i = 0; i < N; i++) {
            cin >> com;
            if (com == "north")
                state = North(state, north, south);
            else if (com == "east")
                state = East(state, west, east);
            else if (com == "west")
                state = West(state, west, east);
            else if (com == "south")
                state = South(state, north, south);
        }
        cout << state << endl;
        cin >> N;

    }


}
