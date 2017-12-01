#include <stdio.h>
#include <stdlib.h>

void qs(int *list, int len);
void bubble(int *list, int len);
void selection(int *list, int len);
void insertion(int *list, int len);
void shell(int *list, int len);
void gapInsert(int *list, int s, int e, int l);
void merge(int *list, int len);

int main (void) {
  int list[10000];
  srand(0);
  int n = sizeof list / sizeof list[0];
  int i;
  for (i = 0; i < n; i++) {
    list[i] = rand() / 1000000;
  }
  // qs(list, n);
  bubble(list, n);
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

void merge(int *list, int len) {
  if (len >= 1) {
    int split = len / 2;
    int left = list[0:split];
    int right = list[split:len];
    int llen = sizeof left / sizeof left[0];
    int rlen = sizeof right / sizeof right[0];
    merge(left, llen);
    merge(right, rlen);
    int i, j, k = 0;
    while (i < llen && j < rlen) {
      if (left[i] < right[j]) {
        list[k] = left[i];
        i++;
      } else {
        list[k] = right[j];
        j++;
      }
    }
    while (i < llen) {
      list[k] = left[i];
      i++;
      k++;
    }
    while (j < rlen) {
      list[k] = right[j];
      j++;
      k++;
    }
  }
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
 