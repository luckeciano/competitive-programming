#include <cstdio>
#include <cmath>
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {

    ofstream myfile;
    myfile.open("result.txt");
    for (int a = 1; a <= 2000; a++) {
        for (int b = 1; b <= 2000; b++) {
            if (a + b <= 2000) {
                for (int c = 1; c <= 2000; c++) {
                    if (a + b + c <= 2000 && a*b*c > 1000000) {
                        int d = 1000000*(a + b + c)/(a*b*c - 1000000);
                        if (d > 0 && a + b + c + d <= 2000 && a*b*c*d == 1000000*(a+ b + c + d) &&
                             a <= b && b <= c && c <= d) {
                             myfile << fixed << setprecision(2) << a/100.00 << " ";
                             myfile << fixed << setprecision(2) << b/100.00 << " ";
                             myfile << fixed << setprecision(2) << c/100.00 << " ";
                             myfile << fixed << setprecision(2) << d/100.00 << "\\n";
                             }

                    }
                }
            }
        }
    }




}
