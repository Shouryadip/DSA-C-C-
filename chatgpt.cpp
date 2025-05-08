#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INF INT_MAX

void dijkstra(int **graph, int V, int src) {
    int dist[V]; // The output array. dist[i] will hold the shortest distance from src to i
    int prev[V]; // Array to store the shortest path tree
    int visited[V]; // visited[i] will be true if vertex i is included in the shortest path tree or the shortest distance from src to i is finalized

    // Initialize all distances as INFINITE and visited[] as false
    for (int i = 0; i < V; i++) {
        dist[i] = INF;
        visited[i] = 0;
        prev[i] = -1;
    }

    // Distance of source vertex from itself is always 0
    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not yet processed.
        // u is always equal to src in the first iteration.
        int u = -1;
        for (int i = 0; i < V; i++) {
            if (!visited[i] && (u == -1 || dist[i] < dist[u])) {
                u = i;
            }
        }

        // Mark the picked vertex as processed
        visited[u] = 1;

        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < V; v++) {
            // Update dist[v] only if it is not in visited, there is an edge from u to v, and total weight of path from src to v through u is smaller than the current value of dist[v]
            if (!visited[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                prev[v] = u;
            }
        }
    }

    // Print the constructed distance array
    printf("Vertex\tDistance from Source\tPath\n");
    for (int i = 0; i < V; i++) {
        if (dist[i] == INF) {
            printf("%d\t\tINF\t\t\t-\n", i);
        } else {
            printf("%d\t\t%d\t\t\t", i, dist[i]);
            int path[V];
            int j = 0;
            for (int v = i; v != -1; v = prev[v]) {
                path[j++] = v;
            }
            for (int k = j - 1; k >= 0; k--) {
                printf("%d ", path[k]);
            }
            printf("\n");
        }
    }
}

int main() {
    char filename[100];
    printf("Enter the filename: ");
    scanf("%s", filename);

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Could not open file %s\n", filename);
        return 1;
    }

    int V;
    fscanf(file, "%d", &V);

    // Allocate memory for the graph
    int **graph = (int **)malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++) {
        graph[i] = (int *)malloc(V * sizeof(int));
        for (int j = 0; j < V; j++) {
            fscanf(file, "%d", &graph[i][j]);
        }
    }

    fclose(file);

    int src;
    printf("Enter the source vertex: ");
    scanf("%d", &src);

    dijkstra(graph, V, src);

    // Free the allocated memory
    for (int i = 0; i < V; i++) {
        free(graph[i]);
    }
    free(graph);

    return 0;
}
