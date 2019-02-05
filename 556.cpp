#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

int main() {
    int b, w;
    cin >> b >> w;
    while (!(b == 0 && w == 0)) {
        vector<vector<int> > maze;
        vector<vector<int> > visited;
        for (int i = 0; i < b; i++) {
            vector<int> line;
            vector<int> visitedLine;
            for (int j = 0; j < w; j++) {
                char aux;
                cin >> aux;
                line.push_back(int(aux - '0'));
                visitedLine.push_back(0);
            }
            maze.push_back(line);
            visited.push_back(visitedLine);
        }
        int dir = 0; //left
        int x = b - 1;
        int y = 0;
        bool isOver = false;
        bool started = false;
        while (!isOver) {
            bool lostWall = false;
            if (dir == 0) {
                if (x + 1 < b && maze[x+1][y] == 0)
                    lostWall = true;

                //goes to y + 1
                if (!lostWall && y + 1 < w && maze[x][y+1] == 0) {
                    y++;
                    visited[x][y]++;
                }
                //check with exists a right wall to turn right
                else if (lostWall) {
                    x++;
                    visited[x][y]++;
                    dir = 3;
                }
                else {
                    dir = (dir + 1)%4;
                }

            }
            else if (dir == 1) {
                if (y + 1 < w && maze[x][y+1] == 0)
                    lostWall = true;
                //goes to x - 1
                if (!lostWall && x - 1 >= 0 && maze[x-1][y] == 0) {
                    x--;
                    visited[x][y]++;
                }
                else if (lostWall) {
                    y++;
                    visited[x][y]++;
                    dir = 0;
                }
                else {
                    dir = (dir + 1)%4;
                }
            }
            else if (dir == 2) {
                if (x - 1 >= 0 && maze[x-1][y] == 0)
                    lostWall = true;
                //goes to y - 1
                if (!lostWall && y - 1 >= 0 && maze[x][y-1] == 0) {
                    y--;
                    visited[x][y]++;
                }
                else if (lostWall) {
                    x--;
                    visited[x][y]++;
                    dir = 1;
                }
                else {
                    dir = (dir+1)%4;
                }
            }
            else if (dir == 3) {
                if (y - 1 >= 0  && maze[x][y-1] == 0)
                    lostWall = true;
                //goes to x + 1;
                if (!lostWall && x + 1 < b && maze[x+1][y] == 0) {
                    x++;
                    visited[x][y]++;
                }
                else if (lostWall) {
                    y--;
                    visited[x][y]++;
                    dir = 2;
                }
                else {
                    dir = (dir + 1)%4;
                }
            }

            //cout << x << " " <<  y << " " << dir << endl;
            if (!started && (x != b - 1 || y != 0))
                started = true;
            if (x == b - 1 && y == 0 && started)
                isOver = true;
        }

        /*for (int i = 0; i < b; i++) {
            for (int j = 0; j < w; j++) {
                cout << visited[i][j];
            }
            cout << endl;
        }*/
        vector<int> freq;
        for (int n = 0; n < 5; n++) {
            freq.push_back(0);
        }
        for (int i = 0; i < b; i++) {
            for (int j = 0; j < w; j++) {
                if (visited[i][j] == 1 && maze[i][j] == 0)
                    freq[1]++;
                else if (visited[i][j] == 2 && maze[i][j] == 0)
                    freq[2]++;
                else if (visited[i][j] == 3 && maze[i][j] == 0)
                    freq[3]++;
                else if (visited[i][j] == 4 && maze[i][j] == 0)
                    freq[4]++;
                else if (visited[i][j] == 0 && maze[i][j] == 0)
                    freq[0]++;
            }
        }

        cout << setw(3) << freq[0];
        cout << setw(3) << freq[1];
        cout << setw(3) << freq[2];
        cout << setw(3) << freq[3];
        cout << setw(3) << freq[4];
        cout << endl;

        cin >> b >> w;
    }



}
