#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main () {
	int T;
	cin >> T;
	int instructs[110];
	for (int i = 0; i < T; i++) {
		int instructions;
		cin >> instructions;
		int finalPos = 0;
		for (int j = 0; j < instructions; j++) {
			string inst;
			cin >> inst;	
			if (inst == "LEFT")
			{
				finalPos -= 1;
				instructs[j] = -1; 
			}
			else if (inst == "RIGHT") {
				finalPos += 1;
				instructs[j] = 1;
			}
			else if (inst == "SAME") {
				string aux;
				cin >> aux;
				int num;
				cin >> num;
				instructs [j] = instructs[num - 1];
				finalPos += instructs[j];
			}
		}
		//insts.clear();
		cout << finalPos << endl;
	}
	return 0;
}