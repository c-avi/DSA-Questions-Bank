#include <iostream>
using namespace std;

// Number of vertices in the graph
#define V 4
#define INF 99999

// A function to prin the solution matrix
void printSolution(int dist[][V]);

bool negCyclefloydWarshall(int graph[][V]) {
    int dist[V][V], i, j, k;

    /*
    Initialize the solution matrix same as input graph matrix*/
    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            dist[i][j] = graph[i][j];
        }
    }

    // Intermediate vertices
    for (k = 0; k < V; k++) {
        // Pick all vertices as source one by one
        for (i = 0; i < V; i++) {
            // Pick all vertices as destination one by one
            for (j = 0; j < V; j++) {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }

    // If distance of any vertex from itself becomes negative , then there is a negative weight cycle
    for (int i = 0; i < V; i++)
        if (dist[i][i] < 0) 
            return true;
    return false;
}

int main() {
    int graph[V][V] = {{0, 1, INF, INF},
                        {INF, 0, -1, INF},
                        {INF, INF, 0, -1},
                        {-1, INF, INF, 0}};

    if (negCyclefloydWarshall(graph))
        cout << "Yes";
    else
        cout << "No";
    return 0;
}