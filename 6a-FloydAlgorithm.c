#include <stdio.h>
#define INF 99999
int V;

void printSolution(int dist[][V]) {
  printf("\nFinal Matrix\n");
  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++) {
      if (dist[i][j] == INF) {
        printf("%6s", "INF");
      } else {
        printf("%6d", dist[i][j]);
      }
    }
    printf("\n");
  }
}

void floydWarshall(int dist[][V]) {
  int i, j, k;
  for (k = 0; k < V; k++) {
    printf("\nMatrix\n");
    for (i = 0; i < V; i++) {
      for (j = 0; j < V; j++) {
        if (dist[i][k] + dist[k][j] < dist[i][j]) {
          dist[i][j] = dist[i][k] + dist[k][j];
        }
        if (dist[i][j] == INF) {
          printf("%6s", "INF");
        } else {
          printf("%6d", dist[i][j]);
        }
      }
      printf("\n");
    }
  }
  printSolution(dist);
}

int main() {

  // Custom input
  // int graph[V][V] = {
  //     {0, 5, INF, 10}, {INF, 0, 3, INF}, {INF, INF, 0, 1}, {INF, INF, INF,
  //     0}};
  printf("Enter number of vertices: ");
  scanf("%d", &V);
  int graph[V][V];
  printf("Enter Distance Matrix: ");
  for (int i = 0; i < V; i++) {
    for (int j = 0; j < V; j++) {
      scanf("%d", &graph[i][j]);
    }
  }

  floydWarshall(graph);
  return 0;
}
