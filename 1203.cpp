#include <iostream>
#include <queue>

using namespace std;

int main() {
    priority_queue <pair<int, pair<int, int> > > queries;
    string aux;
    cin >> aux;
    while (aux != "#") {
        int q, p;
        cin >> q >> p;
        queries.push(make_pair(-p, make_pair(-q, -p)));
        cin >> aux;
    }
    int K;
    cin >> K;
    for (int i = 0; i < K; i++) {
        cout << -queries.top().second.first << endl;
        int time = -queries.top().first;
        int lastQ, lastP;
        lastQ = -queries.top().second.first;
        lastP = -queries.top().second.second;
        queries.pop();
        priority_queue<pair<int, pair <int, int> > > aux;
        int cont = queries.size();
        for (int j = 0; j < cont; j++) {
            int q, newP;
            q = -queries.top().second.first;
            newP = -queries.top().first - time;
            aux.push(make_pair(-newP, make_pair(-q, queries.top().second.second)));
            queries.pop();
        }
        cont = aux.size();
        for (int j = 0; j < cont; j++) {
            queries.push(aux.top());
            aux.pop();
        }
        queries.push(make_pair(-lastP, make_pair(-lastQ, -lastP)));
    }


}
