#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int l, int m, int r) {
  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;

  int L[n1], R[n2];

  for (i = 0; i < n1; i++) {
    L[i] = arr[l + i];
  }
  for (j = 0; j < n2; j++) {
    R[j] = arr[m + 1 + j];
  }

  while (i < n1 && j < n2) {
    if (i < n1 && j < n2) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = R[j];
    j++;
    k++;
  }
}

void mergeSort(int arr[], int l, int r) {
  if (l < r) {
    int m = l + (r - l) / 2;
    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);
    merge(arr, l, m, r);
  }
}

int main() {
  int n, i;
  clock_t start, end;
  double cpu_time_used;
  FILE *fp = fopen("time.txt", "w");
  if (fp == NULL) {
    printf("Error opening file.\n");
    return 1;
  }
  fprintf(fp, "n,Time(ms)\n");

  for (n = 5000; n <= 10000; n += 1000) {
    int *arr = (int *)malloc(n * sizeof(int));
    srand(time(NULL));
    for (i = 0; i < n; i++) {
      arr[i] = rand();
    }
    start = clock();
    mergeSort(arr, 0, n - 1);
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
    printf("Time taken to sort %d elements: %f\n", n, cpu_time_used);
    fprintf(fp, "%d,%f", n, cpu_time_used);
    free(arr);
  }
  fclose(fp);
  return 0;
}
