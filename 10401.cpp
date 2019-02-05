#include <iostream>
#include <vector>
#include <cstring>

using namespace std;
vector<int> rows;
long long memo [20][20];
bool can (int i, int c, vector<int> res) {

    if (res[c - 1] == i || (i - 1 >= 0 && res[c-1] == i - 1) || (i + 1 < rows.size() && res[c - 1] == i + 1))
        return false;
    if (c + 1 < rows.size() && (rows[c + 1] == i || (i - 1 >= 0 && rows[c + 1] == i - 1) || (i + 1 < rows.size()  && rows[c + 1] == i + 1)))
        return false;
    return true;
}
string x = "";
long long ways (vector<int> res, int r, int c) {

    if (c == rows.size()) return 1;

    if (memo[r][c] != -1) return memo[r][c];
    long long ans = 0;
    if (rows[c] != -1) {
        if (can (rows[c], c, res)) {
            res.push_back(rows[c]);
            ans += ways(res, rows[c], c+1);
        }
    } else {
        for (int i = 0; i < rows.size(); i++) {
            if (can(i, c, res)) {
                vector<int> aux = res;
                aux.push_back(i);
                ans += ways (aux, i,  c + 1);
            }
        }
    }
    return memo[r][c] = ans;

}

int main() {

    while (cin >> x) {
        memset(memo, -1, sizeof memo);
        rows.clear();
        for (int i = 0; i < x.size(); i++) {
            if (x[i] == '?')
                rows.push_back(-1);
            else if (x[i] >= '0' && x[i] <= '9')
                rows.push_back(x[i] - '1');
            else rows.push_back(x[i] - 'A' + 9);
        }
        vector<int> res;
        long long ans = 0;
        if (rows[0] != -1) {
            res.push_back(rows[0]);
            ans += ways(res, rows[0], 1);
        } else {
            for (int i = 0; i < rows.size(); i++) {
                res.clear();
                res.push_back(i);
                ans += ways(res, i , 1);
            }
        }
        cout << ans << endl;


    }


}
