#include <stdio.h>
#include <stdlib.h>

void qs(int *list, int len);

void bubble(int *list, int len);

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
 