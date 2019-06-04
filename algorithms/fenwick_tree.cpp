/*
* Fenwick Tree / BIT (Binary Indexed Tree)
* Erick Blanco. 2019
*/

#define MAX_N 1000001
#include <iostream>

using namespace std;

int N, bit[MAX_N], arr[MAX_N];

int getParent(int i) {
  return i - ((~i + 1) & i);
}

int getNext(int i) {
  return i + ((~i + 1) & i);
}

void update(int i, int value) {
  int q = value - arr[i]; // The increment
  bit[i + 1] += q;
  int index = getNext(i + 1);
  while (index <= N) {
    bit[index] += q;
    index = getNext(index);
  }
}

int getSum(int i) {
  int sum = 0, index = i + 1;
  while (index) {
    sum += bit[index];
    index = getParent(index);
  }
  return sum;
}

int main() {
  cin >> N; int aux;
  // Read and initialization
  for (int i = 0; i < N; i++) {
    cin >> aux;
    update(i, aux);
  }
  cout << "sum: " << getSum(N - 1);
}
