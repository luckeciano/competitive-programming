#include <iostream>
#include <map>
using namespace std;

int main() {
    int k;
    int TC; cin >> TC;
    string expr, equals, f1, sig, f2;
    map<string, string> dic, prec;
    int cont = 0;
    while (TC--) {
        cont ++;
        cin >> k;
        dic.clear();
        prec.clear();
        for (int i = 0; i < k; i++) {
            cin >> expr >> equals >> f1 >> sig >> f2;
            string str;
            if (dic.find(f1) != dic.end()) {
                if (sig == "*" && prec[f1] != "*")
                    str += "(" + dic[f1] + ")";
                else str += dic[f1];
            } else str += f1;
            str += sig;
            if (dic.find(f2) != dic.end()) {
                if (prec[f2] != "*" || (prec[f2] == "*" && sig == "*"))
                    str += "(" + dic[f2] + ")";
                else str += dic[f2];
            } else str += f2;
            dic[expr] = str;
            prec[expr] = sig;
        }
        cout << "Expression #" << cont << ": " << dic[expr] << endl;


    }

}
