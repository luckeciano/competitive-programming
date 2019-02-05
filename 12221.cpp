#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
using namespace std;
int main() {
    int N;
    cin >> N;
    for (int i = 0; i < N; i++) {
        string s = "";
        string aux;
        scanf ("\n");
        while ((cin.peek()!='\n') && (cin >> aux)) {
            for (int t = 0; t < aux.size(); t++) {
                if ((aux[t] >= 'a' && aux[t] <= 'z') || (aux[t] >= 'A' && aux[t] <= 'Z'))
                    s += tolower(aux[t]);
            }
        }
        vector<string> mat;
        string x = "";
        for (int j = 0; j < s.size(); j++) {
            if ((j+1)%(int(sqrt(s.size()))) != 0)
                x += s[j];
            else {
                x += s[j];
                mat.push_back(x);
                x = "";
            }

        }

        int dim = mat.size();
        bool magic = true;
        for (int  j = 0; j < dim && magic; j++) {
            for (int k = 0; k < dim && magic; k++) {
                if (mat[j][k] != mat[k][j] || mat[j][k] != mat[dim - k - 1][dim-j - 1])
                    magic = false;
            }
        }

        cout << "Case #" << i+1 << ":" << endl;
        if (magic) cout << dim << endl;
        else cout << "No magic :(" << endl;



    }


}
