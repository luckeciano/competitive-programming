#include <algorithm>
#include <cstdio>
using namespace std;

#define INF 1000000000

///FLOYD-WARSHALL: OTHER APPLICATIONS
    ///SINGLE SOURCE (SSSP): IF V < 400, CODING IS FASTER THE DIJKSTRA

    ///PRINTING SHORTEST PATH: STORE PARENT INFORMATION IN p matrix:
    /*
    int main() {

    // inside int main()
    // let p be a 2D parent matrix, where p[i][j] is the last vertex before j
    // on a shortest path from i to j, i.e. i -> ... -> p[i][j] -> j
    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
            p[i][j] = i; // initialize the parent matrix
    for (int k = 0; k < V; k++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++) // this time, we need to use if statement
                if (AdjMat[i][k] + AdjMat[k][j] < AdjMat[i][j])
                {
                    AdjMat[i][j] = AdjMat[i][k] + AdjMat[k][j];
                    p[i][j] = p[k][j]; // update the parent matrix
                }

    }

        //-------------------------------------------------------------------------
        // when we need to print the shortest paths, we can call the method below:
        void printPath(int i, int j)
        {
            if (i != j) printPath(i, p[i][j]);
            printf(" %d", j);
        }
    */

    ///TRANSITIVE CLOSURE: GIVEN A GRAPH, DETERMINE IF A VERTEX i IS CONNECTED WITH j, DIRECTLY OF INDIRECTLY
        ///INITIALLY, AdjMat[i][j] CONTAINS 1 if  i IS DIRECTLY CONNECTED WITH j, and 0 OTHERWISE
     /*
    for (int k = 0; k < V; k++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                AdjMat[i][j] |= (AdjMat[i][k] & AdjMat[k][j]);
    */

    /// FINDING (CHEAPEST/NEGATIVE) CYCLE: WE INITIALLY SET THE MAIN DIAGONAL WITH 1B
        /// AdjMat[i][i] = INF;
        /// THEN, RUN FW; IF AdjMat[i][i] IS NO LONGER INF, THEN WE HAVE A CYCLE
        /// THE SMALLEST NON NEGATIVE AdjMat[i][i] IS THE CHEAPEST CYCLE
        /// IF  AdjMat[i][i] < 0, THEN WE HAVE A NEGATIVE CYCLE.

    /// FINDING THE DIAMETER OF A GRAPH: RUN FW AND THE MAX DIST AdjMat[i][j] IS THE DIAMETER

    /// FINDING SCC OF A DIRECTED GRAPH: USE TRANSITIVE CLOSURE; IF AdjMat[i][j] && AdjMat[j][i] IS TRUE,
        /// THEN VERTEX i AND j BELONG THE SAME SCC.


int main() {
  int V, E, u, v, w, AdjMatrix[200][200];

  /*
  // Graph in Figure 4.30
  5 9
  0 1 2
  0 2 1
  0 4 3
  1 3 4
  2 1 1
  2 4 1
  3 0 1
  3 2 3
  3 4 5
  */

  freopen("in_07.txt", "r", stdin);

  scanf("%d %d", &V, &E);
  ///INITIALIZING ADJ MATRIX: INF FOR ALL I != J
  /// 0 for I = J (DISTANCE BETWEEN A NODE AND ITSELF IS ZERO)
  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++)
      AdjMatrix[i][j] = INF;
    AdjMatrix[i][i] = 0;
  }
    ///DIRECTED GRAPH IN THIS CASE
  for (int i = 0; i < E; i++) {
    scanf("%d %d %d", &u, &v, &w);
    AdjMatrix[u][v] = w; // directed graph
  }
    ///FLOYD-WARSHALL ITSELF
  for (int k = 0; k < V; k++) // common error: remember that loop order is k->i->j
    for (int i = 0; i < V; i++)
      for (int j = 0; j < V; j++)
        AdjMatrix[i][j] = min(AdjMatrix[i][j], AdjMatrix[i][k] + AdjMatrix[k][j]);


  return 0;
}

