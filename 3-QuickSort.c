#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int arr[], int low, int high) {
  int pivot = arr[high];
  int i = (low - 1);

  for (int j = low; j <= high - 1; j++) {
    if (arr[j] < pivot) {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[high]);
  return (i + 1);
}

void quickSort(int arr[], int low, int high) {
  if (low < high) {
    int pi = partition(arr, low, high);
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
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
    for (i = 0; i < n; i++) {
      arr[i] = rand();
    }
    start = clock();
    printf("%ld\t\t", start);
    quickSort(arr, 0, n - 1);
    end = clock();
    printf("%ld\t\t", end);
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
    printf("Time taken to sort %d elements: %f milliseconds\n", n,
           cpu_time_used);
    fprintf(fp, "%d,%f\n", n, cpu_time_used);
    free(arr);
  }
  fclose(fp);
  return 0;
}
