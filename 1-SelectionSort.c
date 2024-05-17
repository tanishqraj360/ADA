#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selectionSort(int a[], int n) {
  int i, j, min;
  for (i = 0; i < n - 1; i++) {
    min = i;
    for (j = i + 1; j < n; j++) {
      if (a[j] < a[min]) {
        min = j;
      }
    }
    int temp = a[min];
    a[min] = a[i];
    a[i] = temp;
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
    int *a = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++) {
      a[i] = rand();
    }
    start = clock();
    printf("%ld\t", start);
    selectionSort(a, n);
    end = clock();
    printf("%ld\t", end);
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
    printf("Time taken to sort %d elements: %f milliseconds\n", n,
           cpu_time_used);
    fprintf(fp, "%d,%f\n", n, cpu_time_used);
    free(a);
  }
  fclose(fp);
  return 0;
}
