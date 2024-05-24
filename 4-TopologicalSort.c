#include <stdio.h>
#define MAX 100

int n;
int indegree[MAX];
int adj[MAX][MAX];

void topologicalSort() {
  int i, j, k, count = 0;
  int top_order[MAX];

  for (i = 0; i < n; i++) {
    indegree[i] = 0;
    for (j = 0; j < n; j++) {
      if (adj[j][i] == 1) {
        indegree[i]++;
      }
    }
  }
  while (count < n) {
    for (i = 0; i < n; i++) {
      if (indegree[i] == 0) {
        top_order[count++] = i;
        indegree[i] = -1;
      }
      for (j = 0; j < n; j++) {
        if (adj[i][j] == 1) {
          indegree[j]--;
        }
      }
      break;
    }
  }
  printf("Topological Ordering: ");
  for (i = 0; i < n; i++) {
    printf("%d", top_order[i]);
  }
}

int main() {
  int i, j;
  printf("Enter the number of vertices: ");
  scanf("%d", &n);
  printf("Enter the adjacency matrix: \n");
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      scanf("%d", &adj[i][j]);
    }
  }
  topologicalSort();
  return 0;
}
