/*
* Binomial coefficient
* Erick Blanco. 2019
*/

#include <iostream>

using namespace std;

int nCk(int n, int k) {
  if (n < k)
    return 0;
  if (k == 0)
    return 1;

  return n * nCk(n - 1, k - 1) / k;
}

int main() {
  int n, k;
  cin >> n >> k;
  cout << nCk(n, k);
  return 0;
}
