#include <iostream>
#include <map>


using namespace std;

int main() {
    int m, n, costWall, p, value, cost, x, y, direction, lifetime;
    map<pair<int, int>, pair<int, int> > bumpers;
    int totalPoints = 0;

    cin >> m >> n >> costWall >> p;
    for (int i = 0; i < p ; i++) {
        cin >> x >> y >> value >> cost;
        bumpers[make_pair(x,y)] = make_pair(value, cost);
    }

    while (cin >> x >> y >> direction >> lifetime) {
        int points = 0;
        while (--lifetime > 0) {
            switch(direction) {
                case 0:
                    if (x == m - 1) {
                        lifetime -= costWall;
                        direction = 3;
                    } else {
                        if (bumpers.find(make_pair(x+1, y)) != bumpers.end()) {
                            points += bumpers[make_pair(x+1, y)].first;
                            lifetime -= bumpers[make_pair(x+1, y)].second;
                            direction = 3;
                        }
                        else x++;
                    }
                    break;
                case 1:
                if (y == n - 1) {
                    lifetime -= costWall;
                    direction = 0;
                } else {
                    if (bumpers.find(make_pair(x, y + 1)) != bumpers.end()) {
                        points += bumpers[make_pair(x, y + 1)].first;
                        lifetime -= bumpers[make_pair(x, y+ 1)].second;
                        direction = 0;
                    }
                    else y++;
                }
                break;
                case 2:
                if (x == 2) {
                    lifetime -= costWall;
                    direction = 1;
                } else {
                    if (bumpers.find(make_pair(x-1, y)) != bumpers.end()) {
                        points += bumpers[make_pair(x-1, y)].first;
                        lifetime -= bumpers[make_pair(x-1, y)].second;
                        direction = 1;
                    }
                    else x--;
                }
                break;
                case 3:
                if (y == 2) {
                    lifetime -= costWall;
                    direction = 2;
                } else {
                    if (bumpers.find(make_pair(x, y-1)) != bumpers.end()) {
                        points += bumpers[make_pair(x, y-1)].first;
                        lifetime -= bumpers[make_pair(x, y-1)].second;
                        direction = 2;
                    }
                    else y--;
                }
                break;

            }
        }

        cout << points << endl;
        totalPoints += points;


    }

    cout << totalPoints << endl;

    return 0;



}
