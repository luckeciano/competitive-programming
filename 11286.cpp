#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    while (N!=0) {
        map <vector <int>, int> conf;
        for (int i = 0; i < N; i++) {
            vector<int> courses;
            for (int j = 0; j < 5; j++) {
                int aux;
                cin >> aux;
                courses.push_back(aux);
            }
            sort(courses.begin(), courses.end());
            if (conf.find(courses) == conf.end())
                conf[courses] = 1;
            else conf[courses]++;

        }
        map<vector<int>, int>::iterator it;
        int maxSize = 0;
        int freq = 0;
        for (it = conf.begin(); it != conf.end(); it++)
            if (it->second == maxSize) {
                freq++;

            } else if (it->second > maxSize) {
                maxSize = it->second;
                freq = 1;
            }

        cout << freq*maxSize << endl;





        cin >> N;
    }



}
