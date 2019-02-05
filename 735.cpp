#include <cstdio>
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {

    int n;
    cin >> n;
    vector<int> elements({0,1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 24, 27, 30, 22, 33, 36, 26, 39, 28, 42, 45, 32, 48, 34, 51, 54, 57, 38, 40, 60, 50});
    while (n > 0) {
        int p = 0; int k = 0;
        set<vector<int> > combinations;
        for (int a = 0; a < elements.size(); a++) {
            for (int b = 0; b < elements.size(); b++) {
                for (int c = 0; c < elements.size(); c++) {
                    int x = elements[a]; int y = elements[b]; int z = elements[c];

                    if (x + y + z == n) {
                        vector<int> sol; sol.push_back(x); sol.push_back(y); sol.push_back(z);
                        sort(sol.begin(), sol.end());
                        if (combinations.find(sol) != combinations.end()) {
                            p++;
                        } else {
                            k++;
                            p++;
                            combinations.insert(sol);
                        }
                    }
                }
            }
        }
        if (k > 0) {
        cout << "NUMBER OF COMBINATIONS THAT SCORES " << n << " IS " << k << "." << endl;
        cout << "NUMBER OF PERMUTATIONS THAT SCORES " << n << " IS " << p << "." << endl;
        } else cout << "THE SCORE OF " << n << " CANNOT BE MADE WITH THREE DARTS." << endl;
        cout << "**********************************************************************" << endl;
        cin >> n;
        if (n <= 0) cout << "END OF OUTPUT" << endl;
    }




}

