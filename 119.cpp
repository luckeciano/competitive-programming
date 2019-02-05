#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int main() {
	int N;
	bool isFirst = true;
	while (cin >> N) {
		if (!isFirst) {
			cout << endl;
		} else isFirst = false;
		map<string, int> peopleAmount;
		vector <string> peopleInOrder;
		for (int i = 0; i < N; i++){
			string name;
			cin >> name;
			peopleInOrder.push_back(name);
			peopleAmount[name] = 0;
		}
		for (int i = 0; i < N; i++) {
			string whoGivesGift;
			cin >> whoGivesGift;
			int amount, people;
			cin >> amount >> people;
			if (people != 0) {
				peopleAmount[whoGivesGift] -= people*(amount/people);
				for (int k = 0; k < people; k++) {
					string whoGainsGift;
					cin >> whoGainsGift;
					peopleAmount[whoGainsGift] += amount/people;
				}	
			}	
				
			
		}
		vector<string>::iterator it;
		for (it = peopleInOrder.begin(); it != peopleInOrder.end(); it++) {
			cout << *it << " " << peopleAmount[*it] << endl;
		}
	}
}