#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		vector<string> mostRelevantSites;
		int relevance = -100000;
		for (int j = 0; j < 10; j++) {
			string site; int siteRelevance;
			cin >> site; cin >> siteRelevance;
			if (siteRelevance > relevance) {
				mostRelevantSites.clear();
				mostRelevantSites.push_back(site);
				relevance = siteRelevance;
			}
			else if (siteRelevance == relevance) {
				mostRelevantSites.push_back(site);
			}
		}
		cout << "Case #" << i+1 << ":" << endl;
		for (int k = 0; k < mostRelevantSites.size(); k++) {
			cout << mostRelevantSites[k] << endl;
		}
	}

	return 0;

}