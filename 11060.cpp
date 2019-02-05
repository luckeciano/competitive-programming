#include <iostream>
#include <map>
#include <vector>
#include <queue>

using namespace std;


string aux;
priority_queue <int, vector<int>, greater<int> > Q;
map<string, int> incoming;
map<string, vector<string> > graph;
map<string, vector<string> >::iterator it;
map<string, int> order;
map<int, string> rOrder;
string a, b;
int N, M;
int cont = 0;
int main() {
    while (cin >> N) {
        cont++;
        order.clear();
        incoming.clear();
        graph.clear();
        rOrder.clear();
        for (int i = 0; i < N; i++) {
           cin >> aux;
           vector<string> vec;
           order[aux] = i;
           rOrder[i] = aux;
           graph[aux] = vec;
           incoming[aux] = 0;
        }
        cin >> M;
        for (int i = 0; i < M; i++) {
            cin >> a >> b;
            graph[a].push_back(b);
            incoming[b]++;
        }

        for (it = graph.begin(); it != graph.end(); it++) {
            if (incoming[it->first] == 0) {
                Q.push(order[it->first]);
            }
        }
        cout << "Case #" << cont << ": Dilbert should drink beverages in this order:";
        while (!Q.empty()) {
            int k = Q.top();
            string u = rOrder[k]; Q.pop();
            cout << " " << u;
            for (int i = 0; i < graph[u].size(); i++) {
                incoming[graph[u][i]]--;
                if (incoming[graph[u][i]] == 0)
                    Q.push(order[graph[u][i]]);
            }

        }
        cout << "." << endl;
        cout << endl;


    }

}
