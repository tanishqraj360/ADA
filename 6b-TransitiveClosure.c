#include <stdio.h>
#define MAX 100

int n;
int adj[MAX][MAX];

void warshallalgo() {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < n; k++) {
        adj[i][j] = adj[i][j] || adj[i][k] && adj[k][j];
      }
    }
  }
}

int main() {
  printf("Enter the number of vertices: ");
  scanf("%d", &n);
  printf("Enter the adjacency matrix:\n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      scanf("%d", &adj[i][j]);
    }
  }

  warshallalgo();
  printf("The resultant matrix is: \n");
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      printf("%6d", adj[i][j]);
    }
    printf("\n");
  }
  return 0;
}
