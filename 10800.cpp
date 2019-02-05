#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    int TC; cin >> TC;
    string str;
    vector<int> graph;
    string line;
    int cont = 0;
    while(TC--) {
        str.clear(); graph.clear(); line.clear();
        cont++;
        cin >> str;
        int pt = 0; int maxPt = 0; int minPt = 0;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == 'R') {
                pt++;
            }
            if (str[i] == 'F') {
                pt--;
            }
            if (pt < minPt) minPt = pt;
            if (pt > maxPt)
                maxPt = pt;
            graph.push_back(pt);
        }
        for (int i = 0; i < graph.size(); i++)
            graph[i] += abs(minPt);
        maxPt += abs(minPt);
        for (int i = 0; i < graph.size(); i++) {
            if (graph[i] == maxPt && str[i] == 'C')
                maxPt++;
        }
        //yAxis = maxPt + 1;
        cout << "Case #" << cont << ":" << endl;
        for (int i = maxPt; i >= 1; i--) {
            line.clear();
            line.push_back('|'); line.push_back(' ');
            int contSpace = 0;
            for (int j = 0; j < graph.size(); j++) {
                if (graph[j] == i && str[j] == 'R') {
                    while (contSpace) contSpace--, line.push_back(' ');
                   line.push_back('/');
                }
                else if (graph[j] == i - 1 && str[j] == 'C'){
                    while (contSpace) contSpace--, line.push_back(' ');
                    line.push_back('_');
                }
                else if (graph[j] == i - 1 && str[j] == 'F') {
                     while (contSpace) contSpace--, line.push_back (' ');
                     line.push_back('\\');
                }
                else contSpace++;
            }
            cout << line << endl;
        }
       // cout << endl;
        line.clear(); line.push_back('+');
        for (int k = 0; k < graph.size() + 2; k++){
            line.push_back('-');
        }
        cout << line << endl;


        cout << endl;
    }


}
