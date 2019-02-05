#include <iostream>
#include <vector> 

using namespace std;

int main() {
	int k;
	cin >> k;
	while (k > 0) {
		int m;
		cin >> m;
		bool grads = true;
		vector <int> freddieCourses;
		for (int i = 0; i < k; i++) {
			int course;
			cin >> course;
			freddieCourses.push_back(course);
		}

		for (int j = 0; j < m; j++) {
			int c; int r;
			cin >> c >> r;
			
			for (int k = 0; k < c; k++){
				int givenCourse;
				cin >> givenCourse;
				for (int i = 0; i < freddieCourses.size(); i++) {
					if (freddieCourses[i] == givenCourse) {
						r--;
					}
				}
			}
			if (r > 0) {
				grads = false;
			}
		}
		if (grads) cout << "yes" << endl;
		else cout << "no" << endl;
		cin >> k;	
	}

	return 0;
}