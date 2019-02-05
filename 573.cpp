#include <iostream>

using namespace std;

int main() {
	int H, U, D, F;
	cin >> H >> U >> D >> F;
	while (H != 0) {
		double distance = 0;
		int day = 0;
		double climb = U;
		bool sucess;
		while (distance <= H && distance >= 0) {	
				day++;
				distance += climb;
				if (distance > H) {
					sucess = true;
					break;					
				}
				else {
					distance -= D;
				}
				if (distance < 0){
					sucess = false;
					break;
				}
				
				climb -= (U*F)/100.0;
				if (climb < 0) {
					climb = 0;
				} 

		}
		if (sucess)
			cout << "success on day " << day << endl;
		else cout << "failure on day " << day << endl;

		cin >> H >> U >> D >> F;
	}
	return 0;
}