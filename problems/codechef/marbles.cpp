#include <iostream>
typedef long long int big;

using namespace std;

big nCk(int n, int k) {
  if (n < k)
    return 0;
  if (k == 0)
    return 1;

  return n * nCk(n - 1, k - 1) / k;
}

int main() {
  int T, N, K;
  cin >> T;
  while (T--) {
    cin >> N >> K;
    cout << nCk(N - 1, K - 1) << endl;
  }
  return 0;
}
