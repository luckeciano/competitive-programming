#include <iostream>
#include <vector>

using namespace std;

int main() {

    vector<vector<pair <int, int> > > matrix;
    vector<vector<pair <int, int> >> cpy;
    int m, n;
    while (cin >> m >> n) {
        matrix.clear();
        cpy.clear();
        for (int i = 0; i < m; i++) {
            int edges[10005];
            int num;
            cin >> num;
            for (int j = 0; j < num; j++) {
                cin >> edges[j];
            }
            vector<pair<int,int > > e;
            for (int j = 0; j < num; j++) {
                int w; cin >> w;
                e.push_back(make_pair(edges[j] - 1, w));
            }
            matrix.push_back(e);

        }

        cpy.resize(n);
        for (int i = 0; i < matrix.size(); i++) {
            for (int j =0; j < matrix[i].size(); j++) {
                pair<int,int> edge = matrix[i][j];
                pair<int,int> reverseEdge = make_pair(i, edge.second);
                cpy[edge.first].push_back(reverseEdge);
            }
        }

        cout << n << " " << m << endl;
        for (int i = 0; i < cpy.size(); i++) {
                cout << cpy[i].size();
                if (cpy[i].size() > 0) cout << " ";
            for (int j = 0; j < cpy[i].size(); j++) {
                cout << cpy[i][j].first + 1;
                if (j != cpy[i].size() - 1) cout << " ";
            } cout << endl;
            for (int j = 0; j < cpy[i].size(); j++) {
                cout << cpy[i][j].second;
                if (j != cpy[i].size() - 1) cout << " ";
            } cout << endl;

        }
    }


}
