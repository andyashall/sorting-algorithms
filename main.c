#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void qs(int *list, int len);
void bubble(int *list, int len);
void selection(int *list, int len);
void insertion(int *list, int len);
void shell(int *list, int len);
void gapInsert(int *list, int s, int e, int l);
void mergeSort (int *a, int n, int m);
void merge (int *a, int n);

int main (void) {
  int list[10000];
  srand(0);
  int n = sizeof list / sizeof list[0];
  int i;
  for (i = 0; i < n; i++) {
    list[i] = rand() / 1000000;
  }
  merge(list, n);
  for (i = 0; i < n; i++) {
    printf("%d ", list[i]);
  }
  printf("\n");
  return 0;
}

void bubble(int *list, int len) {
  int i, n;
  for (n = len; n >= 0; n--) {
    for (i = 0; i < len; i++) {
      if (list[i] > list[i+1]) {
        int tmp = list[i];
        list[i] = list[i+1];
        list[i+1] = tmp;
      }
    }
  }
}

void selection(int *list, int len) {
  int i, n, l;
  for (n = len; n >= 0; n--) {
    l = 0;
    for (i = 0; i < n; i++) {
      if (list[i] > list[l]) {
        l = i;
      }
    }
    int tmp = list[n];
    list[n] = list[l];
    list[l] = tmp;
  }
}

void insertion(int *list, int len) {
  int n, c, p;
  for (n = 0; n < len; n++) {
    c = list[n];
    p = n;
    while (p > 0 && list[p-1] > c) {
      list[p] = list[p-1];
      p--;
    }
    list[p] = c;
  }
}

void shell(int *list, int len) {
  int split = len / 2;
  int i;
  while (split > 0) {
    for (i = 0; i < len; i++) {
      gapInsert(list, i, split, len);
    }
    split = split / 2;
  }
}

void gapInsert(int *list, int s, int e, int l) {
  int n, p, c;
  for (n = s+e; n < l; n+=e) {
    c = list[n];
    p = n;
    while (p >= e && list[p-e] > c) {
      list[p] = list[p-e];
      p-=e;
    }
    list[p] = c;
  }
}

void mergeSort (int *a, int n, int m) {
  int i, j, k;
  int *x = malloc(n * sizeof a[0]);
  for (i = 0, j = m, k = 0; k < n; k++) {
    x[k] = j == n      ? a[i++]
         : i == m      ? a[j++]
         : a[j] < a[i] ? a[j++]
         :               a[i++];
  }
  for (i = 0; i < n; i++) {
    a[i] = x[i];
  }
  free(x);
}
 
void merge (int *a, int n) {
  if (n < 2)
    return;
  int m = n / 2;
  merge(a, m);
  merge(a + m, n - m);
  mergeSort(a, n, m);
}

void qs(int *list, int len) {
  if (len < 2) return;
  int pivot = list[len / 2];
  int i, j;
  for (i = 0, j = len - 1; ; i++, j--) {
    while (list[i] < pivot) i++;
    while (list[j] > pivot) j--;
    if (i >= j) break;
    int temp = list[i];
    list[i] = list[j];
    list[j] = temp;
  }
  qs(list, i);
  qs(list + i, len - i);
}
 