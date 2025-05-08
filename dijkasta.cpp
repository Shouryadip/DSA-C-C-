#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100
#define INF INT_MAX

int graph[MAX][MAX];
int dist[MAX];
int visited[MAX];
int n; // Number of vertices

// Function to find the vertex with the minimum distance value
int minDistance() {
    int min = INF, minIndex;

    for (int v = 0; v < n; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            minIndex = v;
        }
    }

    return minIndex;
}

// Function to implement Dijkstra's algorithm
void dijkstra(int src) {
    // Initialize all distances as INFINITE and visited[] as false
    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = 0;
    }

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    // Find shortest path for all vertices
    for (int count = 0; count < n - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not yet processed
        int u = minDistance();
        visited[u] = 1;

        // Update dist value of the adjacent vertices of the picked vertex
        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print the constructed distance array
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < n; i++) {
        printf("%d \t %d\n", i, dist[i]);
    }
}

int main() {
    int edges, src, dest, weight, startVertex;

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    // Initialize the graph with 0 (no edges)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }

    // Read the edges with weights
    printf("Enter the edges (source destination weight):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d %d", &src, &dest, &weight);
        graph[src][dest] = weight;  // Directed graph
        graph[dest][src] = weight;  // Comment this line if the graph is directed
    }

    printf("Enter the starting vertex: ");
    scanf("%d", &startVertex);

    // Run Dijkstra's algorithm from the starting vertex
    dijkstra(startVertex);

    return 0;
}
