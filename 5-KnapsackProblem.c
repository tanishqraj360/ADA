#include <stdio.h>

int w[10], p[10], v[10][50], n, i, j, cap, x[10] = {0};

int max(int i, int j) {
  if (i > j) {
    return i;
  } else {
    return j;
  }
}

int knap(int i, int j) {
  int value;
  if (v[i][j] < 0) {
    if (j < w[i]) {
      value = knap(i - 1, j);
    } else {
      value = max(knap(i - 1, j), p[i] + knap(i - 1, j - w[i]));
    }
    v[i][j] = value;
  }
  return (v[i][j]);
}

int main() {
  int profit, count = 0;
  printf("\nEnter the number of elements:\n");
  scanf("%d", &n);

  printf("Enter the profit and weight of the element: \n");
  for (i = 1; i <= n; i++) {
    printf("For item no %d\n", i);
    scanf("%d%d", &p[i], &w[i]);
  }

  printf("\nEnter the capacity: ");
  scanf("%d", &cap);

  for (i = 0; i <= n; i++) {
    for (j = 0; j <= cap; j++) {
      if ((i == 0) || (j == 0)) {
        v[i][j] = 0;
      } else {
        v[i][j] = -1;
      }
    }
  }

  profit = knap(n, cap);

  int i = n, j = cap;
  while (i > 0 && j > 0) {
    if (v[i][j] != v[i - 1][j]) {
      x[i] = 1;
      j = j - w[i];
    }
    i--;
  }

  printf("Items included are\n");
  printf("%-10s %-10s %-10s\n", "Item No", "Weight", "Profit");
  for (i = 1; i <= n; i++) {
    if (x[i]) {
      printf("%-10d %-10d %-10d\n", i, w[i], p[i]);
      count++;
    }
  }

  printf("Total profit=%d\n", profit);
  return 0;
}
