/*
* Merge Sort
* Erick Blanco. 2019
*/

#include <iostream>
#include <string.h>

using namespace std;

merge(int *arr, int *tmp, int start, int end) {
  int leftEnd = start + (end - start) / 2;
  int head = 0, leftHead = start, rightHead = leftEnd + 1;
  while (leftHead <= leftEnd && rightHead <= end) { // While both halves have elements
    if (arr[leftHead] < arr[rightHead]) {
      tmp[head++] = arr[leftHead++];
    } else {
      tmp[head++] = arr[rightHead++];
    }
  }
  // At this point, one list has remaining elements
  while (leftHead <= leftEnd) {
    tmp[head++] = arr[leftHead++];
  }
  while (rightHead <= end) {
    tmp[head++] = arr[rightHead++];
  }
  // Copy back
  int size = (end - start) + 1;
  memcpy(arr + start, tmp, size * sizeof(int));
}

void mergeSort(int *arr, int *tmp, int start, int end) {
  if (start >= end) // Trivially sorted
    return;
  int mid = start + (end - start) / 2; // To avoid overflow
  mergeSort(arr, tmp, start, mid);
  mergeSort(arr, tmp, mid + 1, end);
  // Once the two halves are sorted
  merge(arr, tmp, start, end);
}

void mergeSort(int *start, int *end) {
  int size = end - start;
  int *tmp = new int[size];
  mergeSort(start, tmp, 0, size - 1);
}

int main() {
  int N;
  cin >> N;
  int *arr = new int[N];
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  mergeSort(arr, arr + N);
  for (int i = 0; i < N; i++) {
    cout << arr[i] << ' ';
  }
}
