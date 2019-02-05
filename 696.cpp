#include <iostream>

using namespace std;

int main() {
    int M, N;
    cin >> M >> N;
    while (M != 0 || N !=0) {
        int result;
        if (M == 0 || N == 0)
            result = 0;
        else if (M == 1 || N == 1)
            result = max(M, N);
        else if (M == 2 || N == 2)  {

            if (max(M,N) == 3 || max(M,N) == 2)
                result = 4;
            else if (max(M, N)%2 == 0){
                if ((max(M,N)/2)%2 == 0)
                    result = 2*(max(M, N)/2);
                else result = 2*(max(M, N)/2 + 1);
            }
            else result = 2*(max(M, N)/2 + 1);
        }
        else {
            if (M*N%2 == 0)
                result = M*N/2;
            else result = (M*N)/2 + 1;

        }
        cout << result << " knights may be placed on a " << M << " row " << N << " column board." << endl;
        cin >> M >> N;
    }



}
