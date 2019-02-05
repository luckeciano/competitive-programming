#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

typedef vector<int> vi;



vi match, vis;// global variables
vector<vi> AdjList;
int Aug(int l) {
        // return 1 if an augmenting path is found
  if (vis[l]) return 0;                               // return 0 otherwise
  vis[l] = 1;

  for (int j = 0; j < (int)AdjList[l].size(); j++) {
    int r = AdjList[l][j];
    if (match[r] == -1 || (/*!vis[match[r]] &&*/ Aug(match[r]))) {
      match[r] = l; return 1;                           // found 1 matching
  } }
  return 0;                                                  // no matching
}
vector<pair<int,int> > vRight, vLeft;
int main() {
    int r, c;
    char grid[45][20];
    int color[45][20];
    int TC; cin >> TC;
    while (TC--) {
        AdjList.clear();
        vRight.clear(); vLeft.clear();
        cin >> r >> c;
        int y = 1;
        for (int i = 0; i < r; i++) {
            int x = y;
            for (int j = 0; j < c; j++) {
                cin >> grid[i][j];
                color[i][j] = x;
                x = 1 - x;
            }
            y = 1 - y;
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == '*' && color[i][j] == 1) {
                    int node = -1;
                    for (int k = 0; k < vRight.size(); k++) {
                        if (vRight[k].first == i*c + j)
                            node = vRight[k].second;
                    }
                    if (node == -1) {
                        vector<int> t;
                        AdjList.push_back(t);
                        vRight.push_back(make_pair((i)*c + j, AdjList.size() - 1));
                    }
                }
                if (grid[i][j] == '*' && color[i][j] == 0) {
                    vector<int> aux;
                    AdjList.push_back(aux);
                    vLeft.push_back(make_pair(i*c + j, AdjList.size() - 1));
                    int thisWhiteNode = AdjList.size() - 1;
                    if (i - 1 >= 0 && grid[i - 1][j] == '*') {
                        int node = -1;
                        for (int k = 0; k < vRight.size(); k++) {
                            if (vRight[k].first == (i - 1)*c + j)
                                node = vRight[k].second;
                        }
                        if (node == -1) {
                            vector<int> t;
                            AdjList.push_back(t);
                            vRight.push_back(make_pair((i - 1)*c + j, AdjList.size() - 1));
                            node = AdjList.size() - 1;
                        }
                        AdjList[thisWhiteNode].push_back(node);
                        AdjList[node].push_back(thisWhiteNode);
                    }
                    if (i + 1 < r && grid[i + 1][j] == '*') {
                        int node = -1;
                        for (int k = 0; k < vRight.size(); k++) {
                            if (vRight[k].first == (i + 1)*c + j)
                                 node = vRight[k].second;
                        }
                        if (node == -1) {
                            vector<int> t;
                            AdjList.push_back(t);
                            vRight.push_back(make_pair((i + 1)*c + j, AdjList.size() - 1));
                            node = AdjList.size() - 1;
                        }
                        AdjList[thisWhiteNode].push_back(node);
                        AdjList[node].push_back(thisWhiteNode);
                    }
                    if (j - 1 >= 0 && grid[i][j - 1] == '*') {
                        int node = -1;
                        for (int k = 0; k < vRight.size(); k++) {
                            if (vRight[k].first == (i)*c + j - 1)
                                node = vRight[k].second;
                        }
                        if (node == -1) {
                             vector<int> t;
                            AdjList.push_back(t);
                            vRight.push_back(make_pair((i)*c + j - 1, AdjList.size() - 1));
                            node = AdjList.size() - 1;
                        }
                        AdjList[thisWhiteNode].push_back(node);
                        AdjList[node].push_back(thisWhiteNode);
                    }
                    if (j + 1 < c && grid[i][j + 1] == '*') {
                        int node = -1;
                        for (int k = 0; k < vRight.size(); k++) {
                            if (vRight[k].first == (i)*c + j + 1)
                                node = vRight[k].second;
                        }
                        if (node == -1) {
                             vector<int> t;
                            AdjList.push_back(t);
                            vRight.push_back(make_pair((i)*c + j + 1, AdjList.size() - 1));
                            node = AdjList.size() - 1;
                        }
                        AdjList[thisWhiteNode].push_back(node);
                        AdjList[node].push_back(thisWhiteNode);
                    }
                }
            }
        }
        /*cout << "left:" << endl;
        for (int i = 0; i < vLeft.size(); i++) {
            cout << vLeft[i].first << " " << vLeft[i].second << endl;
        }

        cout << "right:" << endl;
        for (int i = 0; i < vLeft.size(); i++) {
            cout << vRight[i].first << " " << vRight[i].second << endl;
        }
        for (int i = 0; i < AdjList.size(); i++) {
            cout << "node " << i << endl;
            for (int j = 0; j < AdjList[i].size(); j++) {
                cout << AdjList[i][j] << " ";
            }
            cout << endl;
        }*/
        int MCBM = 0;
          match.assign(AdjList.size(), -1);    // V is the number of vertices in bipartite graph

          for (int l = 0; l < vRight.size(); l++) {         // Vleft = size of the left set
            vis.assign(AdjList.size(), 0);
            MCBM += Aug(vRight[l].second);
          }

          cout << AdjList.size() - MCBM << endl;


    }
    return 0;

}
