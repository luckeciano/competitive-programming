#include <iostream>
#include <string>

using namespace std;

int main() {

	string music[100];
	music[0] = "Happy";
	music[1] = "birthday";
	music[2] = "to";
	music[3] = "you";
	music[4] = "Happy";
	music[5] = "birthday";
	music[6] = "to";
	music[7] = "you";
	music[8] = "Happy";
	music[9] = "birthday";
	music[10] = "to";
	music[11] = "Rujia";
	music[12] = "Happy";
	music[13] = "birthday";
	music[14] = "to";
	music[15] = "you";

	int t;
	cin >> t;
	string names[101];
	for (int i = 0; i < t; i++) {
		cin >> names[i];
	}
	int contNames = 0;
	int contMusic = 0;
	bool end = false;
	while(!end)
	{
		cout << names[contNames%t] << ": " << music[contMusic%16] << endl;
		if (contMusic%16 == 15){
			if (contNames >= t - 1) {
				end = true;
			}
		}
		contMusic++;
		contNames++;
	}
	return 0;

}